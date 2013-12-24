/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Chung Leong <cleong@cal.berkeley.edu>                        |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

typedef enum qb_pixel_format qb_pixel_format;

enum qb_pixel_format {
	QB_PIXEL_ARRANGEMENT_1D = 0x40000000,
	QB_PIXEL_ARRANGEMENT_2D = 0x80000000,
	QB_PIXEL_ARRANGEMENT_FLAGS = 0xF0000000,

	QB_PIXEL_INVALID = 0,
	QB_PIXEL_I08_1,
	QB_PIXEL_I08_4,
	QB_PIXEL_I32_1,
	QB_PIXEL_F32_1,
	QB_PIXEL_F32_3,
	QB_PIXEL_F32_4,
	QB_PIXEL_F64_1,
	QB_PIXEL_F64_3,
	QB_PIXEL_F64_4,

	QB_PIXEL_1D_I08_1 = QB_PIXEL_I08_1 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_I08_4 = QB_PIXEL_I08_4 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_I32_1 = QB_PIXEL_I32_1 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F32_1 = QB_PIXEL_F32_1 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F32_3 = QB_PIXEL_F32_3 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F32_4 = QB_PIXEL_F32_4 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F64_1 = QB_PIXEL_F64_1 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F64_3 = QB_PIXEL_F64_3 | QB_PIXEL_ARRANGEMENT_1D,
	QB_PIXEL_1D_F64_4 = QB_PIXEL_F64_4 | QB_PIXEL_ARRANGEMENT_1D,

	QB_PIXEL_2D_I08_1 = QB_PIXEL_I08_1 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_I08_4 = QB_PIXEL_I08_4 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_I32_1 = QB_PIXEL_I32_1 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F32_1 = QB_PIXEL_F32_1 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F32_3 = QB_PIXEL_F32_3 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F32_4 = QB_PIXEL_F32_4 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F64_1 = QB_PIXEL_F64_1 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F64_3 = QB_PIXEL_F64_3 | QB_PIXEL_ARRANGEMENT_2D,
	QB_PIXEL_2D_F64_4 = QB_PIXEL_F64_4 | QB_PIXEL_ARRANGEMENT_2D,
};

static gdImagePtr qb_get_gd_image(zval *resource) {
	if(Z_TYPE_P(resource) == IS_RESOURCE) {
		static int le_gd = -1;
		TSRMLS_FETCH();
		if(le_gd == -1) {
			le_gd = zend_fetch_list_dtor_id("gd");
		}
		if(le_gd) {
			gdImagePtr image = (gdImagePtr) zend_fetch_resource(&resource TSRMLS_CC, -1, NULL, NULL, 1, le_gd);
			return image;
		}
	}
	return NULL;
}

static int32_t qb_set_image_dimensions(qb_storage *storage, qb_address *address, gdImagePtr image) {
	qb_address *width_address = address->dimension_addresses[1];
	qb_address *height_address = address->dimension_addresses[0];
	uint32_t width_expected = VALUE_IN(storage, U32, width_address);
	uint32_t height_expected = VALUE_IN(storage, U32, height_address);
	if(width_expected != image->sx) {
		if(CONSTANT(width_address)) {
			qb_report_image_width_mismatch_exception(storage->current_owner, 0, image->sx, width_expected);
			return FALSE;
		}
		VALUE_IN(storage, U32, width_address) = image->sx;
	}

	if(height_expected != image->sy) {
		if(CONSTANT(height_address)) {
			qb_report_image_height_mismatch_exception(storage->current_owner, 0, image->sy, width_expected);
		}
		VALUE_IN(storage, U32, height_address) = image->sy;
	}
	return TRUE;
}

static int32_t qb_set_image_linear_size(qb_storage *storage, qb_address *address, gdImagePtr image) {
	qb_address *length_address = address->dimension_addresses[0];
	uint32_t pixel_count = image->sx * image->sy;
	uint32_t length_expected = VALUE_IN(storage, U32, length_address);
	if(length_expected != pixel_count) {
		if(CONSTANT(length_address)) {
			qb_report_pixel_count_mismatch_exception(storage->current_owner, 0, pixel_count, length_expected);
			return FALSE;
		}
	}
	VALUE_IN(storage, U32, length_address) = pixel_count;
	return TRUE;
}

static qb_pixel_format qb_get_compatible_pixel_format(qb_storage *storage, qb_address *address, int32_t true_color) {
	qb_pixel_format pixel_format = QB_PIXEL_INVALID;
	qb_primitive_type element_type = address->type;
	qb_address *last_dimension_address = DIMENSION_ADDRESS(address, -1);
	uint32_t last_dimension = VALUE_IN(storage, U32, last_dimension_address);

	if(address->dimension_count == 3) {
		// allow int8, float32, and float64 and the last dimension must be 1, 3, or 4
		// the GD image must be true color
		if(true_color) {
			if(STORAGE_TYPE_MATCH(element_type, QB_TYPE_I08)) {
				if(last_dimension == 4) {
					pixel_format = QB_PIXEL_2D_I08_4;
				}
			} else if(element_type == QB_TYPE_F32) {
				if(last_dimension == 1) {
					pixel_format = QB_PIXEL_2D_F32_1;
				} else if(last_dimension == 3) {
					pixel_format = QB_PIXEL_2D_F32_3;
				} else if(last_dimension == 4) {
					pixel_format = QB_PIXEL_2D_F32_4;
				}
			} else if(element_type == QB_TYPE_F64) {
				if(last_dimension == 1) {
					pixel_format = QB_PIXEL_2D_F64_1;
				} else if(last_dimension == 3) {
					pixel_format = QB_PIXEL_2D_F64_3;
				} else if(last_dimension == 4) {
					pixel_format = QB_PIXEL_2D_F64_4;
				}
			}
		}
	} else if(address->dimension_count == 2) {
		// allow either int32, representing each pixel (if the image is true color)
		// or int8, representing representing each pixel (if the image uses a palette )
		// or int8, float32, and float64, with the last dimension being one, three, or four (if the image is true color)
		if(true_color) {
			if(STORAGE_TYPE_MATCH(element_type, QB_TYPE_I32)) {
				pixel_format = QB_PIXEL_2D_I32_1;
			} else if(element_type == QB_TYPE_F32) {
				if(last_dimension == 1) {
					pixel_format = QB_PIXEL_1D_F32_1;
				} else if(last_dimension == 3) {
					pixel_format = QB_PIXEL_1D_F32_3;
				} else if(last_dimension == 4) {
					pixel_format = QB_PIXEL_1D_F32_4;
				}
			} else if(element_type == QB_TYPE_F64) {
				if(last_dimension == 1) {
					pixel_format = QB_PIXEL_1D_F64_1;
				} else if(last_dimension == 3) {
					pixel_format = QB_PIXEL_1D_F64_3;
				} else if(last_dimension == 4) {
					pixel_format = QB_PIXEL_1D_F64_4;
				}
			}
		} else {
			if(STORAGE_TYPE_MATCH(element_type, QB_TYPE_I08)) {
				pixel_format = QB_PIXEL_2D_I08_1;
			}
		}
	} else if(address->dimension_count == 1) {
		// allow either int32, representing each pixel (if the image is true color)
		// or int8, representing representing each pixel (if the image uses a palette)
		if(true_color) {
			if(STORAGE_TYPE_MATCH(element_type, QB_TYPE_I32)) {
				pixel_format = QB_PIXEL_1D_I32_1;
			}
		} else {
			if(STORAGE_TYPE_MATCH(element_type, QB_TYPE_I08)) {
				pixel_format = QB_PIXEL_1D_I08_1;
			}
		}
	}
	return pixel_format;
}

static int32_t qb_set_array_dimensions_from_image(qb_storage *storage, qb_address *address, gdImagePtr image, uint32_t *p_array_size) {
	uint32_t array_size, i;
	qb_pixel_format pixel_format = qb_get_compatible_pixel_format(storage, address, image->trueColor);

	if(pixel_format == QB_PIXEL_INVALID) {
		qb_report_invalid_variable_for_image_exception(storage->current_owner, 0, address->dimension_count, image->trueColor);
		return FALSE;
	}

	// set the dimension(s)
	if(pixel_format & QB_PIXEL_ARRANGEMENT_1D) {
		qb_set_image_linear_size(storage, address, image);
	} else {
		qb_set_image_dimensions(storage, address, image);
	}

	// calculate the array sizes
	array_size = 1;
	for(i = address->dimension_count - 1; (int32_t) i >= 0; i--) {
		qb_address *dimension_address = address->dimension_addresses[i];
		qb_address *array_size_address = address->array_size_addresses[i];
		array_size *= VALUE_IN(storage, U32, dimension_address);
		VALUE_IN(storage, U32, array_size_address) = array_size;
	}
	*p_array_size = array_size;
	return TRUE;
}

static int32_t qb_reallocate_gd_image(gdImagePtr image, int width, int height) {
	int i, scanline_size, pixel_size;
	unsigned char ***p_scanlines;

	if(width <= 0 || height <= 0 || width > INT_MAX / sizeof(int) || height > INT_MAX / sizeof(void *)) {
		qb_report_gd_image_exception(NULL, 0, width, height);
		return FALSE;
	}

	if(image->trueColor) {
		p_scanlines = (unsigned char ***) &image->tpixels;
		scanline_size = sizeof(int) * width;
		pixel_size = sizeof(int);
	} else {
		p_scanlines = &image->pixels;
		scanline_size = sizeof(unsigned char) * width;
		pixel_size = sizeof(unsigned char);
	}

	// free scanlines that aren't needed
	for(i = height; i < image->sy; i++) {
		efree((*p_scanlines)[i]);
		efree(image->AA_opacity[i]);
	}

	// reallocate scanline pointer array
	*p_scanlines = erealloc(*p_scanlines, sizeof(unsigned char *) * height);
	image->AA_opacity = erealloc(image->AA_opacity, sizeof(unsigned char *) * height);
	for(i = image->sy; i < height; i++) {
		(*p_scanlines)[i] = NULL;
	}

	// reallocate the scalines themselves
	for(i = 0; i < height; i++) {
		if((*p_scanlines)[i]) {
			(*p_scanlines)[i] = erealloc((*p_scanlines)[i], scanline_size);
			if(width > image->sx) {
				memset((*p_scanlines)[i] + image->sx * pixel_size, 0, pixel_size * (width - image->sx));
			}
		} else {
			(*p_scanlines)[i] = emalloc(scanline_size);
			memset((*p_scanlines)[i], 0, scanline_size);
		}
		if(image->AA_opacity[i]) {
			image->AA_opacity[i] = erealloc(image->AA_opacity[i], sizeof(unsigned char) * width);
			if(width > image->sx) {
				memset(image->AA_opacity[i] + image->sx, 0, sizeof(unsigned char) * (width - image->sx));
			}
		} else {
			image->AA_opacity[i] = emalloc(sizeof(unsigned char) * width);
			memset(image->AA_opacity[i], 0, sizeof(unsigned char) * width);
		}
	}
	image->sx = width;
	image->sy = height;
	return TRUE;
}

static void qb_copy_rgba_pixel_from_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax));
		p[1] = ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax));
		p[2] = ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax));
		p[3] = ((float32_t) (gdAlphaTransparent - gdTrueColorGetAlpha(tpixel)) * (1.0f / gdAlphaMax));
		p += 4;
	}
}

static void qb_copy_rgb_pixel_from_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax));
		p[1] = ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax));
		p[2] = ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax));
		p += 3;
	}
}

static void qb_copy_monochrome_pixel_from_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax)) * 0.299f
			 + ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax)) * 0.587f
			 + ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax)) * 0.114f;
		p += 1;
	}
}

static void qb_copy_rgba_pixel_from_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax));
		p[1] = ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax));
		p[2] = ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax));
		p[3] = ((float32_t) (gdAlphaTransparent - gdTrueColorGetAlpha(tpixel)) * (1.0f / gdAlphaMax));
		p += 4;
	}
}

static void qb_copy_rgb_pixel_from_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax));
		p[1] = ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax));
		p[2] = ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax));
		p += 3;
	}
}

static void qb_copy_monochrome_pixel_from_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2, tpixel;
	uint32_t width = (uint32_t) param3, i;

	for(i = 0; i < width; i++) {
		tpixel = tpixels[i];
		p[0] = ((float32_t) gdTrueColorGetRed(tpixel) * (1.0f / gdRedMax)) * 0.299f
			 + ((float32_t) gdTrueColorGetGreen(tpixel) * (1.0f / gdGreenMax)) * 0.587f
			 + ((float32_t) gdTrueColorGetBlue(tpixel) * (1.0f / gdBlueMax)) * 0.114f;
		p += 1;
	}
}

static int32_t qb_copy_elements_from_gd_image(qb_storage *storage, qb_address *address, gdImagePtr image) {
	uint32_t i, j;
	qb_pixel_format pixel_format = qb_get_compatible_pixel_format(storage, address, image->trueColor);
	qb_pixel_format pixel_type = pixel_format & ~QB_PIXEL_ARRANGEMENT_FLAGS;

	if(image->trueColor) {
		qb_thread_proc proc = NULL;
		uint32_t pixel_size;

		switch(pixel_type) {
			case QB_PIXEL_I08_4:
			case QB_PIXEL_I32_1: {
				int32_t *p = ARRAY_IN(storage, I32, address);

				for(i = 0; i < (uint32_t) image->sy; i++) {
					for(j = 0; j < (uint32_t) image->sx; j++) {
						p[0] = gdImageTrueColorPixel(image, j, i);
						p += 1;
					}
				}
			}	break;
			case QB_PIXEL_F32_4: {
				proc = qb_copy_rgba_pixel_from_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 4;
			}	break;
			case QB_PIXEL_F32_3: {
				proc = qb_copy_rgb_pixel_from_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 3;
			}	break;
			case QB_PIXEL_F32_1: {
				proc = qb_copy_monochrome_pixel_from_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 1;
			}	break;
			case QB_PIXEL_F64_4: {
				proc = qb_copy_rgba_pixel_from_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 4;
			}	break;
			case QB_PIXEL_F64_3: {
				proc = qb_copy_rgb_pixel_from_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 3;
			}	break;
			case QB_PIXEL_F64_1: {
				proc = qb_copy_monochrome_pixel_from_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 1;
			}	break;
			default: {
			}	break;
		}

		if(proc) {
			TSRMLS_FETCH();
			int8_t *p = ARRAY_IN(storage, I08, address);
			qb_task_group _group, *group = &_group;
			qb_main_thread *main_thread = qb_get_main_thread(TSRMLS_C);
			qb_initialize_task_group(group, (qb_thread *) main_thread, image->sy, 0);
			for(i = 0; i < (uint32_t) image->sy; i++) {
				qb_add_task(group, proc, p, image->tpixels[i], image->sx, NULL);
				p += image->sx * pixel_size;
			}
			qb_run_task_group(group);
			qb_free_task_group(group);
		}
	} else {
		switch(pixel_type) {
			case QB_PIXEL_I08_1: {
				int8_t *p = ARRAY_IN(storage, I08, address);

				for(i = 0; i < (uint32_t) image->sy; i++) {
					for(j = 0; j < (uint32_t) image->sx; j++) {
						p[0] = gdImagePalettePixel(image, j, i);
						p += 1;
					}
				}

			}	break;
			default: {
			}	break;
		}
	}
	return TRUE;
}

static void qb_copy_rgba_pixel_to_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r, g, b, a;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float32(p[0], gdRedMax);
		g = qb_clamp_float32(p[1], gdGreenMax);
		b = qb_clamp_float32(p[2], gdBlueMax);
		a = gdAlphaTransparent - qb_clamp_float32(p[3], gdAlphaMax);
		tpixels[i] = gdTrueColorAlpha(r, g, b, a);
		p += 4;
	}
}

static void qb_copy_rgb_pixel_to_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r, g, b;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float32(p[0], gdRedMax);
		g = qb_clamp_float32(p[1], gdGreenMax);
		b = qb_clamp_float32(p[2], gdBlueMax);
		tpixels[i] = gdTrueColorAlpha(r, g, b, gdAlphaOpaque);
		p += 3;
	}
}

static void qb_copy_monochrome_pixel_to_gd_image_scanline_F32(void *param1, void *param2, int param3) {
	float32_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float32(p[0], gdRedMax);
		tpixels[i] = gdTrueColorAlpha(r, r, r, gdAlphaOpaque);
		p += 1;
	}
}

static void qb_copy_rgba_pixel_to_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r, g, b, a;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float64(p[0], gdRedMax);
		g = qb_clamp_float64(p[1], gdGreenMax);
		b = qb_clamp_float64(p[2], gdBlueMax);
		a = gdAlphaTransparent - qb_clamp_float64(p[3], gdAlphaMax);
		tpixels[i] = gdTrueColorAlpha(r, g, b, a);
		p += 4;
	}
}

static void qb_copy_rgb_pixel_to_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r, g, b;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float64(p[0], gdRedMax);
		g = qb_clamp_float64(p[1], gdGreenMax);
		b = qb_clamp_float64(p[2], gdBlueMax);
		tpixels[i] = gdTrueColorAlpha(r, g, b, gdAlphaOpaque);
		p += 3;
	}
}

static void qb_copy_monochrome_pixel_to_gd_image_scanline_F64(void *param1, void *param2, int param3) {
	float64_t *p = param1;
	int *tpixels = param2;
	uint32_t width = (uint32_t) param3, i;
	int r;

	for(i = 0; i < width; i++) {
		r = qb_clamp_float64(p[0], gdRedMax);
		tpixels[i] = gdTrueColorAlpha(r, r, r, gdAlphaOpaque);
		p += 1;
	}
}

static int32_t qb_copy_elements_to_gd_image(qb_storage *storage, qb_address *address, gdImagePtr image) {
	int32_t width, height;
	uint32_t i, j;
	qb_pixel_format pixel_format = qb_get_compatible_pixel_format(storage, address, image->trueColor);
	qb_pixel_format pixel_type = pixel_format & ~QB_PIXEL_ARRANGEMENT_FLAGS;

	if(pixel_format & QB_PIXEL_ARRANGEMENT_1D) {
		qb_address *length_address = address->dimension_addresses[0];
		uint32_t length = VALUE_IN(storage, U32, length_address);
		if(length >= (uint32_t) image->sx) {
			width = image->sx;
			height = length / width;
		} else {
			width = 0;
			height = 0;
		}
	} else {
		qb_address *height_address = address->dimension_addresses[0];
		qb_address *width_address = address->dimension_addresses[1];
		height = VALUE_IN(storage, S32, height_address);
		width = VALUE_IN(storage, S32, width_address);
	}
	if(image->sy != height || image->sx != width) {
		if(!qb_reallocate_gd_image(image, width, height)) {
			return FALSE;
		}
	}

	if(image->trueColor) {
		qb_thread_proc proc = NULL;
		uint32_t pixel_size;

		switch(pixel_type) {
			case QB_PIXEL_I08_4:
			case QB_PIXEL_I32_1: {
				int32_t *p = ARRAY_IN(storage, I32, address);
				int tpixel;
				for(i = 0; i < (uint32_t) image->sy; i++) {
					for(j = 0; j < (uint32_t) image->sx; j++) {
						tpixel = *p++;
						gdImageTrueColorPixel(image, j, i) = tpixel;
					}
				}
			}	break;
			case QB_PIXEL_F32_4: {
				proc = qb_copy_rgba_pixel_to_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 4;
			}	break;
			case QB_PIXEL_F32_3: {
				proc = qb_copy_rgb_pixel_to_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 3;
			}	break;
			case QB_PIXEL_F32_1: {
				proc = qb_copy_monochrome_pixel_to_gd_image_scanline_F32;
				pixel_size = sizeof(float32_t) * 1;
			}	break;
			case QB_PIXEL_F64_4: {
				proc = qb_copy_rgba_pixel_to_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 4;
			}	break;
			case QB_PIXEL_F64_3: {
				proc = qb_copy_rgb_pixel_to_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 3;
			}	break;
			case QB_PIXEL_F64_1: {
				proc = qb_copy_monochrome_pixel_to_gd_image_scanline_F64;
				pixel_size = sizeof(float64_t) * 1;
			}	break;
			default: {
			}	break;
		}

		if(proc) {
			TSRMLS_FETCH();
			int8_t *p = ARRAY_IN(storage, I08, address);
			qb_task_group _group, *group = &_group;
			qb_main_thread *main_thread = qb_get_main_thread(TSRMLS_C);
			qb_initialize_task_group(group, (qb_thread *) main_thread, image->sy, 0);
			for(i = 0; i < (uint32_t) image->sy; i++) {
				qb_add_task(group, proc, p, image->tpixels[i], image->sx, NULL);
				p += image->sx * pixel_size;
			}
			qb_run_task_group(group);
			qb_free_task_group(group);
		}
	} else {
		switch(pixel_type) {
			case QB_PIXEL_I08_1: {
				int8_t *p = ARRAY_IN(storage, I08, address);
				unsigned char pixel;
				for(i = 0; i < (uint32_t) image->sy; i++) {
					for(j = 0; j < (uint32_t) image->sx; j++) {
						pixel = p[0];
						gdImagePalettePixel(image, j, i) = pixel;
						p += 1;
					}
				}
			}	break;
			default: {
			}	break;
		}
	}
	return TRUE;
}

static int32_t qb_initialize_zval_image(qb_storage *storage, qb_address *element_address, zval *element) {	
	uint32_t height = VALUE_IN(storage, U32, element_address->dimension_addresses[0]);
	uint32_t width = VALUE_IN(storage, U32, element_address->dimension_addresses[1]);
	zval *z_width, *z_height, *z_function_name, *z_retval = NULL;
	zval **params[2];
	TSRMLS_FETCH();

	ALLOC_INIT_ZVAL(z_width);
	ALLOC_INIT_ZVAL(z_height);
	ALLOC_INIT_ZVAL(z_function_name);
	ZVAL_LONG(z_width, width);
	ZVAL_LONG(z_height, height);
	ZVAL_STRING(z_function_name, "imagecreatetruecolor", TRUE);
	params[0] = &z_width;
	params[1] = &z_height;
	call_user_function_ex(CG(function_table), NULL, z_function_name, &z_retval, 2, params, TRUE, NULL TSRMLS_CC);
	zval_ptr_dtor(&z_width);
	zval_ptr_dtor(&z_height);
	zval_ptr_dtor(&z_function_name);
	if(Z_TYPE_P(z_retval) != IS_RESOURCE) {
		qb_report_gd_image_exception(storage->current_owner, 0, width, height);
		return FALSE;
	}
	*element = *z_retval;
	Z_TYPE_P(z_retval) = IS_NULL;
	zval_ptr_dtor(&z_retval);
	return TRUE;
}
