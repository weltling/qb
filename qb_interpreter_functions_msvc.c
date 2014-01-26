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

#include "qb.h"
#include "qb_interpreter_msvc.h"

int qb_compare_ascending_F32(const void *p1, const void *p2) {
	if(*((float32_t *) p1) < *((float32_t *) p2)) {
		return -1;
	} else if(*((float32_t *) p1) > *((float32_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_F32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_F32((float32_t *) p1, len, (float32_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_F32((float32_t *) p2, len, (float32_t *) p3, len);
#endif
}

int qb_compare_ascending_F64(const void *p1, const void *p2) {
	if(*((float64_t *) p1) < *((float64_t *) p2)) {
		return -1;
	} else if(*((float64_t *) p1) > *((float64_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_F64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_F64((float64_t *) p1, len, (float64_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_F64((float64_t *) p2, len, (float64_t *) p3, len);
#endif
}

int qb_compare_ascending_S08(const void *p1, const void *p2) {
	if(*((int8_t *) p1) < *((int8_t *) p2)) {
		return -1;
	} else if(*((int8_t *) p1) > *((int8_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_S08_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S08((int8_t *) p1, len, (int8_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S08((int8_t *) p2, len, (int8_t *) p3, len);
#endif
}

int qb_compare_ascending_S16(const void *p1, const void *p2) {
	if(*((int16_t *) p1) < *((int16_t *) p2)) {
		return -1;
	} else if(*((int16_t *) p1) > *((int16_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_S16_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S16((int16_t *) p1, len, (int16_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S16((int16_t *) p2, len, (int16_t *) p3, len);
#endif
}

int qb_compare_ascending_S32(const void *p1, const void *p2) {
	if(*((int32_t *) p1) < *((int32_t *) p2)) {
		return -1;
	} else if(*((int32_t *) p1) > *((int32_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_S32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S32((int32_t *) p1, len, (int32_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S32((int32_t *) p2, len, (int32_t *) p3, len);
#endif
}

int qb_compare_ascending_S64(const void *p1, const void *p2) {
	if(*((int64_t *) p1) < *((int64_t *) p2)) {
		return -1;
	} else if(*((int64_t *) p1) > *((int64_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_S64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S64((int64_t *) p1, len, (int64_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S64((int64_t *) p2, len, (int64_t *) p3, len);
#endif
}

int qb_compare_ascending_U08(const void *p1, const void *p2) {
	if(*((uint8_t *) p1) < *((uint8_t *) p2)) {
		return -1;
	} else if(*((uint8_t *) p1) > *((uint8_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_U08_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U08((uint8_t *) p1, len, (uint8_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U08((uint8_t *) p2, len, (uint8_t *) p3, len);
#endif
}

int qb_compare_ascending_U16(const void *p1, const void *p2) {
	if(*((uint16_t *) p1) < *((uint16_t *) p2)) {
		return -1;
	} else if(*((uint16_t *) p1) > *((uint16_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_U16_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U16((uint16_t *) p1, len, (uint16_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U16((uint16_t *) p2, len, (uint16_t *) p3, len);
#endif
}

int qb_compare_ascending_U32(const void *p1, const void *p2) {
	if(*((uint32_t *) p1) < *((uint32_t *) p2)) {
		return -1;
	} else if(*((uint32_t *) p1) > *((uint32_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_U32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U32((uint32_t *) p1, len, (uint32_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U32((uint32_t *) p2, len, (uint32_t *) p3, len);
#endif
}

int qb_compare_ascending_U64(const void *p1, const void *p2) {
	if(*((uint64_t *) p1) < *((uint64_t *) p2)) {
		return -1;
	} else if(*((uint64_t *) p1) > *((uint64_t *) p2)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_ascending_U64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U64((uint64_t *) p1, len, (uint64_t *) p2, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U64((uint64_t *) p2, len, (uint64_t *) p3, len);
#endif
}

int qb_compare_descending_F32(const void *p1, const void *p2) {
	if(*((float32_t *) p2) < *((float32_t *) p1)) {
		return -1;
	} else if(*((float32_t *) p2) > *((float32_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_F32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_F32((float32_t *) p2, len, (float32_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_F32((float32_t *) p3, len, (float32_t *) p2, len);
#endif
}

int qb_compare_descending_F64(const void *p1, const void *p2) {
	if(*((float64_t *) p2) < *((float64_t *) p1)) {
		return -1;
	} else if(*((float64_t *) p2) > *((float64_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_F64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_F64((float64_t *) p2, len, (float64_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_F64((float64_t *) p3, len, (float64_t *) p2, len);
#endif
}

int qb_compare_descending_S08(const void *p1, const void *p2) {
	if(*((int8_t *) p2) < *((int8_t *) p1)) {
		return -1;
	} else if(*((int8_t *) p2) > *((int8_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_S08_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S08((int8_t *) p2, len, (int8_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S08((int8_t *) p3, len, (int8_t *) p2, len);
#endif
}

int qb_compare_descending_S16(const void *p1, const void *p2) {
	if(*((int16_t *) p2) < *((int16_t *) p1)) {
		return -1;
	} else if(*((int16_t *) p2) > *((int16_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_S16_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S16((int16_t *) p2, len, (int16_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S16((int16_t *) p3, len, (int16_t *) p2, len);
#endif
}

int qb_compare_descending_S32(const void *p1, const void *p2) {
	if(*((int32_t *) p2) < *((int32_t *) p1)) {
		return -1;
	} else if(*((int32_t *) p2) > *((int32_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_S32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S32((int32_t *) p2, len, (int32_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S32((int32_t *) p3, len, (int32_t *) p2, len);
#endif
}

int qb_compare_descending_S64(const void *p1, const void *p2) {
	if(*((int64_t *) p2) < *((int64_t *) p1)) {
		return -1;
	} else if(*((int64_t *) p2) > *((int64_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_S64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_S64((int64_t *) p2, len, (int64_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_S64((int64_t *) p3, len, (int64_t *) p2, len);
#endif
}

int qb_compare_descending_U08(const void *p1, const void *p2) {
	if(*((uint8_t *) p2) < *((uint8_t *) p1)) {
		return -1;
	} else if(*((uint8_t *) p2) > *((uint8_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_U08_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U08((uint8_t *) p2, len, (uint8_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U08((uint8_t *) p3, len, (uint8_t *) p2, len);
#endif
}

int qb_compare_descending_U16(const void *p1, const void *p2) {
	if(*((uint16_t *) p2) < *((uint16_t *) p1)) {
		return -1;
	} else if(*((uint16_t *) p2) > *((uint16_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_U16_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U16((uint16_t *) p2, len, (uint16_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U16((uint16_t *) p3, len, (uint16_t *) p2, len);
#endif
}

int qb_compare_descending_U32(const void *p1, const void *p2) {
	if(*((uint32_t *) p2) < *((uint32_t *) p1)) {
		return -1;
	} else if(*((uint32_t *) p2) > *((uint32_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_U32_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U32((uint32_t *) p2, len, (uint32_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U32((uint32_t *) p3, len, (uint32_t *) p2, len);
#endif
}

int qb_compare_descending_U64(const void *p1, const void *p2) {
	if(*((uint64_t *) p2) < *((uint64_t *) p1)) {
		return -1;
	} else if(*((uint64_t *) p2) > *((uint64_t *) p1)) {
		return 1;
	} else {
		return 0;
	}
}

int qb_compare_descending_U64_array(const void *p1, const void *p2, const void *p3) {
#ifdef __linux__
	// the GNU version of qsort_r expects the extra parameter to come last
	uint32_t len = *((const uint32_t *) p3);
	return qb_compare_array_U64((uint64_t *) p2, len, (uint64_t *) p1, len);
#else
	uint32_t len = *((const uint32_t *) p1);
	return qb_compare_array_U64((uint64_t *) p3, len, (uint64_t *) p2, len);
#endif
}

int32_t qb_compare_array_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

int32_t qb_compare_array_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count) {
	if(op1_count && op2_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t end1 = 0, end2 = 0;
		while(1) {
			if(*op1_ptr > *op2_ptr) {
				return 1;
			} else if(*op1_ptr < *op2_ptr) {
				return -1;
			}
			op1_ptr++;
			if(op1_ptr == op1_end) {
				if(end2) {
					break;
				}
				op1_ptr = op1_start;
				end1 = 1;
			}
			op2_ptr++;
			if(op2_ptr == op2_end) {
				if(end1) {
					break;
				}
				op2_ptr = op2_start;
				end2 = 1;
			}
		}
	} else if(op2_count) {
		return -1;
	} else if(op1_count) {
		return 1;
	}
	return 0;
}

void qb_convert_hsl_to_rgb_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t h = op1_ptr[0], s = op1_ptr[1], l = op1_ptr[2];
	float32_t f, c, r, g, b;
	int32_t i;
	if(s == 0) {
		r = g = b = l;
	} else {
		c = (1 - fabsf(2 * l - 1)) * s;
		h /= 60;
		i = (int32_t) floorf(h);
		f = h - i;
		switch_loop:
		switch(i) {
			case 0:
			r = l + c * 0.5f;
			g = l - c * 0.5f + c * f;
			b = l - c * 0.5f;
			break;
			case 1:
			r = l + c * 0.5f - c * f;
			g = l + c * 0.5f;
			b = l - c * 0.5f;
			break;
			case 2:
			r = l - c * 0.5f;
			g = l + c * 0.5f;
			b = l - c * 0.5f + c * f;
			break;
			case 3:
			r = l - c * 0.5f;
			g = l + c * 0.5f - c * f;
			b = l + c * 0.5f;
			break;
			case 4:
			r = l - c * 0.5f + c * f;
			g = l - c * 0.5f;
			b = l + c * 0.5f;
			break;
			case 5:
			r = l + c * 0.5f;
			g = l - c * 0.5f;
			b = l + c * 0.5f - c * f;
			break;
			default:
			i = i % 6;
			if(i < 0) {
				i += 6;
			}
			goto switch_loop;
		}
	}
	res_ptr[0] = r;
	res_ptr[1] = g;
	res_ptr[2] = b;
}

void qb_convert_hsl_to_rgb_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t h = op1_ptr[0], s = op1_ptr[1], l = op1_ptr[2];
	float64_t f, c, r, g, b;
	int32_t i;
	if(s == 0) {
		r = g = b = l;
	} else {
		c = (1 - fabs(2 * l - 1)) * s;
		h /= 60;
		i = (int32_t) floor(h);
		f = h - i;
		switch_loop:
		switch(i) {
			case 0:
			r = l + c * 0.5;
			g = l - c * 0.5 + c * f;
			b = l - c * 0.5;
			break;
			case 1:
			r = l + c * 0.5 - c * f;
			g = l + c * 0.5;
			b = l - c * 0.5;
			break;
			case 2:
			r = l - c * 0.5;
			g = l + c * 0.5;
			b = l - c * 0.5 + c * f;
			break;
			case 3:
			r = l - c * 0.5;
			g = l + c * 0.5 - c * f;
			b = l + c * 0.5;
			break;
			case 4:
			r = l - c * 0.5 + c * f;
			g = l - c * 0.5;
			b = l + c * 0.5;
			break;
			case 5:
			r = l + c * 0.5;
			g = l - c * 0.5;
			b = l + c * 0.5 - c * f;
			break;
			default:
			i = i % 6;
			if(i < 0) {
				i += 6;
			}
			goto switch_loop;
		}
	}
	res_ptr[0] = r;
	res_ptr[1] = g;
	res_ptr[2] = b;
}

void qb_convert_hsv_to_rgb_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t h = op1_ptr[0], s = op1_ptr[1], v = op1_ptr[2];
	float32_t f, c, r, g, b;
	int32_t i;
	if(s == 0) {
		r = g = b = v;
	} else {
		c = v * s;
		h /= 60;
		i = (int32_t) floorf(h);
		f = h - i;
		switch_loop:
		switch(i) {
			case 0:
			r = v;
			g = v + c * (f - 1);
			b = v - c;
			break;
			case 1:
			r = v - c * f;
			g = v;
			b = v - c;
			break;
			case 2:
			r = v - c;
			g = v;
			b = v + c * (f - 1);
			break;
			case 3:
			r = v - c;
			g = v - c * f;
			b = v;
			break;
			case 4:
			r = v + c * (f - 1);
			g = v - c;
			b = v;
			break;
			case 5:
			r = v;
			g = v - c;
			b = v - c * f;
			break;
			default:
			i = i % 6;
			if(i < 0) {
				i += 6;
			}
			goto switch_loop;
		}
	}
	res_ptr[0] = r;
	res_ptr[1] = g;
	res_ptr[2] = b;
}

void qb_convert_hsv_to_rgb_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t h = op1_ptr[0], s = op1_ptr[1], v = op1_ptr[2];
	float64_t f, c, r, g, b;
	int32_t i;
	if(s == 0) {
		r = g = b = v;
	} else {
		c = v * s;
		h /= 60;
		i = (int32_t) floor(h);
		f = h - i;
		switch_loop:
		switch(i) {
			case 0:
			r = v;
			g = v + c * (f - 1);
			b = v - c;
			break;
			case 1:
			r = v - c * f;
			g = v;
			b = v - c;
			break;
			case 2:
			r = v - c;
			g = v;
			b = v + c * (f - 1);
			break;
			case 3:
			r = v - c;
			g = v - c * f;
			b = v;
			break;
			case 4:
			r = v + c * (f - 1);
			g = v - c;
			b = v;
			break;
			case 5:
			r = v;
			g = v - c;
			b = v - c * f;
			break;
			default:
			i = i % 6;
			if(i < 0) {
				i += 6;
			}
			goto switch_loop;
		}
	}
	res_ptr[0] = r;
	res_ptr[1] = g;
	res_ptr[2] = b;
}

void qb_convert_rgb_to_hsl_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = op1_ptr[0], g = op1_ptr[1], b = op1_ptr[2];
	float32_t min, max, delta, h, s, l;
	if(r > g) {
		max = r;
		min = g;
	} else {
		max = g;
		min = r;
	}
	if(b > max) {
		max = b;
	} else if(b < min) {
		min = b;
	}
	l = (max + min) * 0.5f;
	delta = max - min;
	if(delta != 0) {
		s = delta / (1 - fabsf(max + min - 1));
		if(r == max) {
			h = (g - b) / delta;
		} else if(g == max) {
			h = 2 + (b - r) / delta;
		} else {
			h = 4 + (r - g) / delta;
		}
		h *= 60;
		if(h < 0) {
			h += 360;
		}
	} else {
		s = 0;
		h = 0;
	}
	res_ptr[0] = h;
	res_ptr[1] = s;
	res_ptr[2] = l;
}

void qb_convert_rgb_to_hsl_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = op1_ptr[0], g = op1_ptr[1], b = op1_ptr[2];
	float64_t min, max, delta, h, s, l;
	if(r > g) {
		max = r;
		min = g;
	} else {
		max = g;
		min = r;
	}
	if(b > max) {
		max = b;
	} else if(b < min) {
		min = b;
	}
	l = (max + min) * 0.5;
	delta = max - min;
	if(delta != 0) {
		s = delta / (1 - fabs(max + min - 1));
		if(r == max) {
			h = (g - b) / delta;
		} else if(g == max) {
			h = 2 + (b - r) / delta;
		} else {
			h = 4 + (r - g) / delta;
		}
		h *= 60;
		if(h < 0) {
			h += 360;
		}
	} else {
		s = 0;
		h = 0;
	}
	res_ptr[0] = h;
	res_ptr[1] = s;
	res_ptr[2] = l;
}

void qb_convert_rgb_to_hsv_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = op1_ptr[0], g = op1_ptr[1], b = op1_ptr[2];
	float32_t min, max, delta, h, s, v;
	if(r > g) {
		max = r;
		min = g;
	} else {
		max = g;
		min = r;
	}
	if(b > max) {
		max = b;
	} else if(b < min) {
		min = b;
	}
	v = max;
	delta = max - min;
	if(delta != 0) {
		s = delta / max;
		if(r == max) {
			h = (g - b) / delta;
		} else if(g == max) {
			h = 2 + (b - r) / delta;
		} else {
			h = 4 + (r - g) / delta;
		}
		h *= 60;
		if(h < 0) {
			h += 360;
		}
	} else {
		s = 0;
		h = 0;
	}
	res_ptr[0] = h;
	res_ptr[1] = s;
	res_ptr[2] = v;
}

void qb_convert_rgb_to_hsv_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = op1_ptr[0], g = op1_ptr[1], b = op1_ptr[2];
	float64_t min, max, delta, h, s, v;
	if(r > g) {
		max = r;
		min = g;
	} else {
		max = g;
		min = r;
	}
	if(b > max) {
		max = b;
	} else if(b < min) {
		min = b;
	}
	v = max;
	delta = max - min;
	if(delta != 0) {
		s = delta / max;
		if(r == max) {
			h = (g - b) / delta;
		} else if(g == max) {
			h = 2 + (b - r) / delta;
		} else {
			h = 4 + (r - g) / delta;
		}
		h *= 60;
		if(h < 0) {
			h += 360;
		}
	} else {
		s = 0;
		h = 0;
	}
	res_ptr[0] = h;
	res_ptr[1] = s;
	res_ptr[2] = v;
}

void qb_relocate_elements_F32(float32_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

void qb_relocate_elements_F64(float64_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

void qb_relocate_elements_I08(int8_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

void qb_relocate_elements_I16(int16_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

void qb_relocate_elements_I32(int32_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

void qb_relocate_elements_I64(int64_t *elements, uint32_t *old_dims, uint32_t *new_dims, uint32_t dimension_count) {
	uint32_t i;
	int32_t expansion = FALSE;
	int32_t contraction = FALSE;
	uint32_t level = 0;
	uint32_t copy_counts[MAX_DIMENSION + 1], zero_counts[MAX_DIMENSION + 1], skip_counts[MAX_DIMENSION + 1];
	uint32_t remaining[MAX_DIMENSION + 1];
	uint32_t old_cell_index, new_cell_index = 0;
	uint32_t old_length = 1, new_length = 1;
	// shift index by one to simplify loop logic
	for(i = dimension_count; (int32_t) i > 0; i--) {
		uint32_t old_dim = old_dims[i - 1];
		uint32_t new_dim = new_dims[i - 1];
		if(new_dim > old_dim) {
			expansion = TRUE;
			copy_counts[i] = old_dim;
			zero_counts[i] = (new_dim - old_dim) * new_length;
			skip_counts[i] = 0;
		} else if(old_dim > new_dim) {
			contraction = TRUE;
			copy_counts[i] = new_dim;
			zero_counts[i] = 0;
			skip_counts[i] = (old_dim - new_dim) * old_length;
		} else {
			copy_counts[i] = old_dim;
			zero_counts[i] = 0;
			skip_counts[i] = 0;
		}
		old_length *= old_dim;
		new_length *= new_dim;
	}
	copy_counts[0] = 1;
	zero_counts[0] = 0;
	skip_counts[0] = 0;
	remaining[0] = -1;
	if(contraction) {
		// scan forward if some dimensions got smaller
		level = 0;
		old_cell_index = 0;
		new_cell_index = 0;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
			}
			// copy only when elements are moved backward
			if(new_cell_index < old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index++;
					old_cell_index++;
					remaining[level]--;
				}
			} else {
				new_cell_index += remaining[level];
				old_cell_index += remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				old_cell_index += skip_counts[level];
				new_cell_index += zero_counts[level];
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
	if(expansion) {
		// scan backward if some dimensions got bigger
		level = 0;
		old_cell_index = old_length - 1;
		new_cell_index = new_length - 1;
		for(;;) {
			while(level < dimension_count) {
				level++;
				remaining[level] = copy_counts[level];
				old_cell_index -= skip_counts[level];
				// zero out new space 
				for(i = 0; i < zero_counts[level]; i++) {
					elements[new_cell_index] = 0;
					new_cell_index--;
				}
			}
			// copy only when elements are moved forward
			if(new_cell_index > old_cell_index) {
				while(remaining[level] != 0) {
					elements[new_cell_index] = elements[old_cell_index];
					new_cell_index--;
					old_cell_index--;
					remaining[level]--;
				}
			} else {
				new_cell_index -= remaining[level];
				old_cell_index -= remaining[level];
				remaining[level] = 0;
			}
			while(remaining[level] == 0) {
				level--;
				remaining[level]--;
			}
			if(level == 0) {
				break;
			}
		}
	}
}

int32_t qb_do_array_column_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	float32_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(float32_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_array_column_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	float64_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(float64_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_array_column_I08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, int8_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	int8_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(int8_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_array_column_I16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, int16_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	int16_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(int16_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_array_column_I32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, int32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	int32_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(int32_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_array_column_I64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, uint32_t op4, int64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	int64_t *op1_end = op1_ptr + op1_count;
	uint32_t column_offset = op4, column_count = op2, element_size = op3;
	if(UNEXPECTED(column_offset >= column_count)) {
		USE_TSRM
		qb_report_missing_column_exception(line_id, column_offset, column_count);
		cxt->exit_type = QB_VM_ERROR;
		return FALSE;
	}
	op1_ptr += column_offset * element_size;
	if(element_size == 1) {
		while(op1_ptr < op1_end) {
			*res_ptr = *op1_ptr;
			res_ptr += 1;
			op1_ptr += column_count * element_size;
		}
	} else {
		while(op1_ptr < op1_end) {
			memcpy(res_ptr, op1_ptr, element_size * sizeof(int64_t));
			res_ptr += element_size;
			op1_ptr += column_count * element_size;
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_S08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_S16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_S32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_S64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_U08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_U16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_U32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_divide_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_divide_U64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_S08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_S16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_S32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_S64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_U08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_U16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_U32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

int32_t qb_do_modulo_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count, uint32_t line_id) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			if(!qb_do_modulo_U64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr), line_id)) {
				return FALSE;
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
	return TRUE;
}

void qb_do_abs_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) fabsf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_abs_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) fabs((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_abs_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) abs((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_abs_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) abs((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_abs_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) abs((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_abs_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) llabs((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_accommodate_size_copy_dimension_8_U32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, uint32_t *op7_ptr, uint32_t *op8_ptr, uint32_t op9, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t op14, uint32_t *op15_ptr, uint32_t *op16_ptr, uint32_t op17, uint32_t op18, uint32_t *op19_ptr, uint32_t *op20_ptr, uint32_t op21, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, uint32_t op26, uint32_t *op27_ptr, uint32_t *op28_ptr, uint32_t op29, uint32_t op30, uint32_t *op31_ptr, uint32_t *op32_ptr, uint32_t op33, uint32_t op34) {
	(*op3_ptr) = op1;
	(*op4_ptr) = op2;
	(*op7_ptr) = op5;
	(*op8_ptr) = op6;
	(*op11_ptr) = op9;
	(*op12_ptr) = op10;
	(*op15_ptr) = op13;
	(*op16_ptr) = op14;
	(*op19_ptr) = op17;
	(*op20_ptr) = op18;
	(*op23_ptr) = op21;
	(*op24_ptr) = op22;
	(*op27_ptr) = op25;
	(*op28_ptr) = op26;
	(*op31_ptr) = op29;
	(*op32_ptr) = op30;
	qb_resize_segment(&cxt->function->local_storage->segments[op33], op1 * op34);
}

void qb_do_acos_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) acosf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_acos_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) acos((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_acosh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = acoshf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_acosh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = acosh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_add_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
				res_ptr[2] = op1_ptr[2] + op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
				res_ptr[2] = op1_ptr[2] + op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
				res_ptr[2] = op1_ptr[2] + op2_ptr[2];
				res_ptr[3] = op1_ptr[3] + op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] + op2_ptr[0];
				res_ptr[1] = op1_ptr[1] + op2_ptr[1];
				res_ptr[2] = op1_ptr[2] + op2_ptr[2];
				res_ptr[3] = op1_ptr[3] + op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_add_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) + (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_alpha_blend_2x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t a2 = op2_ptr[1];
	if(a2 != 0) {
		float32_t a1 = op1_ptr[1];
		if(a1 != 0) {
			float32_t y1 = op1_ptr[0];
			float32_t y2 = op2_ptr[0];
			float32_t af = a2 + a1 * (1 - a2);
			float32_t iaf = 1 / af;
			res_ptr[0] = (y2 * a2 * iaf) + (y1 * a1 * iaf) * (1 - a2);
			res_ptr[1] = af;
		} else {
			res_ptr[0] = op2_ptr[0];
			res_ptr[1] = op2_ptr[1];
		}
	} else {
		res_ptr[0] = op1_ptr[0];
		res_ptr[1] = op1_ptr[1];
	}
}

void qb_do_alpha_blend_2x_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t a2 = op2_ptr[1];
	if(a2 != 0) {
		float64_t a1 = op1_ptr[1];
		if(a1 != 0) {
			float64_t y1 = op1_ptr[0];
			float64_t y2 = op2_ptr[0];
			float64_t af = a2 + a1 * (1 - a2);
			float64_t iaf = 1 / af;
			res_ptr[0] = (y2 * a2 * iaf) + (y1 * a1 * iaf) * (1 - a2);
			res_ptr[1] = af;
		} else {
			res_ptr[0] = op2_ptr[0];
			res_ptr[1] = op2_ptr[1];
		}
	} else {
		res_ptr[0] = op1_ptr[0];
		res_ptr[1] = op1_ptr[1];
	}
}

void qb_do_alpha_blend_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_alpha_blend_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_alpha_blend_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_alpha_blend_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_alpha_blend_4x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t a2 = op2_ptr[3];
	if(a2 != 0) {
		float32_t a1 = op1_ptr[3];
		if(a1 != 0) {
			float32_t r1 = op1_ptr[0];
			float32_t g1 = op1_ptr[1];
			float32_t b1 = op1_ptr[2];
			float32_t r2 = op2_ptr[0];
			float32_t g2 = op2_ptr[1];
			float32_t b2 = op2_ptr[2];
			float32_t af = a2 + a1 * (1 - a2);
			float32_t iaf = 1 / af;
			res_ptr[0] = (r2 * a2 * iaf) + (r1 * a1 * iaf) * (1 - a2);
			res_ptr[1] = (g2 * a2 * iaf) + (g1 * a1 * iaf) * (1 - a2);
			res_ptr[2] = (b2 * a2 * iaf) + (b1 * a1 * iaf) * (1 - a2);
			res_ptr[3] = af;
		} else {
			res_ptr[0] = op2_ptr[0];
			res_ptr[1] = op2_ptr[1];
			res_ptr[2] = op2_ptr[2];
			res_ptr[3] = op2_ptr[3];
		}
	} else {
		res_ptr[0] = op1_ptr[0];
		res_ptr[1] = op1_ptr[1];
		res_ptr[2] = op1_ptr[2];
		res_ptr[3] = op1_ptr[3];
	}
}

void qb_do_alpha_blend_4x_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t a2 = op2_ptr[3];
	if(a2 != 0) {
		float64_t a1 = op1_ptr[3];
		if(a1 != 0) {
			float64_t r1 = op1_ptr[0];
			float64_t g1 = op1_ptr[1];
			float64_t b1 = op1_ptr[2];
			float64_t r2 = op2_ptr[0];
			float64_t g2 = op2_ptr[1];
			float64_t b2 = op2_ptr[2];
			float64_t af = a2 + a1 * (1 - a2);
			float64_t iaf = 1 / af;
			res_ptr[0] = (r2 * a2 * iaf) + (r1 * a1 * iaf) * (1 - a2);
			res_ptr[1] = (g2 * a2 * iaf) + (g1 * a1 * iaf) * (1 - a2);
			res_ptr[2] = (b2 * a2 * iaf) + (b1 * a1 * iaf) * (1 - a2);
			res_ptr[3] = af;
		} else {
			res_ptr[0] = op2_ptr[0];
			res_ptr[1] = op2_ptr[1];
			res_ptr[2] = op2_ptr[2];
			res_ptr[3] = op2_ptr[3];
		}
	} else {
		res_ptr[0] = op1_ptr[0];
		res_ptr[1] = op1_ptr[1];
		res_ptr[2] = op1_ptr[2];
		res_ptr[3] = op1_ptr[3];
	}
}

void qb_do_alpha_blend_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_alpha_blend_4x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_alpha_blend_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_alpha_blend_4x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_append_multidimensional_variable_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	float32_t *op1_start = op1_ptr;
	float32_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	float64_t *op1_start = op1_ptr;
	float64_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	int8_t *op1_start = op1_ptr;
	int8_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	int16_t *op1_start = op1_ptr;
	int16_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	int32_t *op1_start = op1_ptr;
	int32_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	int64_t *op1_start = op1_ptr;
	int64_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint8_t *op1_start = op1_ptr;
	uint8_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint16_t *op1_start = op1_ptr;
	uint16_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t *op1_start = op1_ptr;
	uint32_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_multidimensional_variable_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint64_t *op1_start = op1_ptr;
	uint64_t *op1_end = op1_ptr + op1_count;
	uint32_t *op2_start = op2_ptr;
	uint32_t *op2_end = op2_ptr + op2_count;
	uint32_t depth = 0, pos = (*res_count_ptr);
	uint32_t counts[64];
	uint32_t total = 0, multiplier = 1;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
		total += len;
		op1_ptr++;
	}
	while(op2_ptr < op2_end) {
		total += multiplier * *op2_ptr * 2;
		multiplier *= *op2_ptr;
		op2_ptr++;
	}
	if(total == 0) {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op3], (*res_count_ptr) + total);
	memset(counts, 0, sizeof(uint32_t) * op2_count);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	op2_ptr = op2_start;
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				res_ptr[pos++] = ',';
				res_ptr[pos++] = ' ';
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
				memcpy(res_ptr + pos, sprintf_buffer, len);
				pos += len;
				op1_ptr++;
				counts[depth]++;
			} else {
				res_ptr[pos++] = '[';
				depth++;
			}
		} else {
			res_ptr[pos++] = ']';
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_string_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + op1_count);
	memcpy(res_ptr + (*res_count_ptr), op1_ptr, op1_count);
	(*res_count_ptr) += op1_count;
}

void qb_do_append_variable_F32(qb_interpreter_context *__restrict cxt, float32_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_F64(qb_interpreter_context *__restrict cxt, float64_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_S08(qb_interpreter_context *__restrict cxt, int8_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_S16(qb_interpreter_context *__restrict cxt, int16_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_S32(qb_interpreter_context *__restrict cxt, int32_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_S64(qb_interpreter_context *__restrict cxt, int64_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_U08(qb_interpreter_context *__restrict cxt, uint8_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_U16(qb_interpreter_context *__restrict cxt, uint16_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_U32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_U64(qb_interpreter_context *__restrict cxt, uint64_t op1, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, op1);
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + len);
	memcpy(res_ptr + (*res_count_ptr), sprintf_buffer, len);
	(*res_count_ptr) += len;
}

void qb_do_append_variable_multiple_times_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	float32_t *op1_start = op1_ptr;
	float32_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	float64_t *op1_start = op1_ptr;
	float64_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	int8_t *op1_start = op1_ptr;
	int8_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	int16_t *op1_start = op1_ptr;
	int16_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	int32_t *op1_start = op1_ptr;
	int32_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	int64_t *op1_start = op1_ptr;
	int64_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	uint8_t *op1_start = op1_ptr;
	uint8_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	uint16_t *op1_start = op1_ptr;
	uint16_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	uint32_t *op1_start = op1_ptr;
	uint32_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_append_variable_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t pos = (*res_count_ptr);
	uint32_t total = 0;
	uint64_t *op1_start = op1_ptr;
	uint64_t *op1_end = op1_ptr + op1_count;
	if(op1_count) {
		while(op1_ptr < op1_end) {
			char sprintf_buffer[64];
			uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
			total += len;
			op1_ptr++;
		}
		total += op1_count * 2;
	} else {
		total = 2;
	}
	res_ptr += qb_resize_segment(&cxt->function->local_storage->segments[op2], (*res_count_ptr) + total);
	res_ptr[pos++] = '[';
	op1_ptr = op1_start;
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
		memcpy(res_ptr + pos, sprintf_buffer, len);
		pos += len;
		op1_ptr++;
		if(op1_ptr != op1_end) {
			res_ptr[pos++] = ',';
			res_ptr[pos++] = ' ';
		}
	}
	res_ptr[pos++] = ']';
	(*res_count_ptr) += total;
}

void qb_do_apply_premultiplication_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_apply_premultiplication_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_apply_premultiplication_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_apply_premultiplication_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_array_difference_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	float32_t *op1_end = op1_ptr + op1_count;
	float32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(float32_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	float64_t *op1_end = op1_ptr + op1_count;
	float64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(float64_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, uint32_t op3, int8_t *res_ptr, uint32_t res_count) {
	int8_t *op1_end = op1_ptr + op1_count;
	int8_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S08(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(int8_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, uint32_t op3, int16_t *res_ptr, uint32_t res_count) {
	int16_t *op1_end = op1_ptr + op1_count;
	int16_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S16(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(int16_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, uint32_t op3, int32_t *res_ptr, uint32_t res_count) {
	int32_t *op1_end = op1_ptr + op1_count;
	int32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(int32_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, uint32_t op3, int64_t *res_ptr, uint32_t res_count) {
	int64_t *op1_end = op1_ptr + op1_count;
	int64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				memcpy(res_ptr, op1_ptr, sizeof(int64_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_difference_count_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	float32_t *op1_end = op1_ptr + op1_count;
	float32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_difference_count_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	float64_t *op1_end = op1_ptr + op1_count;
	float64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_difference_count_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int8_t *op1_end = op1_ptr + op1_count;
	int8_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S08(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_difference_count_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int16_t *op1_end = op1_ptr + op1_count;
	int16_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S16(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_difference_count_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int32_t *op1_end = op1_ptr + op1_count;
	int32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_difference_count_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int64_t *op1_end = op1_ptr + op1_count;
	int64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(!found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_fill_F32(uint32_t op1, float32_t op2, float32_t *res_ptr, uint32_t res_count) {
	float32_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_F64(uint32_t op1, float64_t op2, float64_t *res_ptr, uint32_t res_count) {
	float64_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_I08(uint32_t op1, int8_t op2, int8_t *res_ptr, uint32_t res_count) {
	int8_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_I16(uint32_t op1, int16_t op2, int16_t *res_ptr, uint32_t res_count) {
	int16_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_I32(uint32_t op1, int32_t op2, int32_t *res_ptr, uint32_t res_count) {
	int32_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_I64(uint32_t op1, int64_t op2, int64_t *res_ptr, uint32_t res_count) {
	int64_t *res_end = res_ptr + res_count, *res_start = res_ptr + op1;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = op2;
		res_ptr++;
	}
}

void qb_do_array_fill_multiple_times_F32(uint32_t op1, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	float32_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	float32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_fill_multiple_times_F64(uint32_t op1, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	float64_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	float64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_fill_multiple_times_I08(uint32_t op1, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	int8_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	int8_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_fill_multiple_times_I16(uint32_t op1, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	int16_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	int16_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_fill_multiple_times_I32(uint32_t op1, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	int32_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	int32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_fill_multiple_times_I64(uint32_t op1, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	int64_t *res_end = res_ptr + res_count, *res_start = res_ptr + (op1 * op2_count);
	int64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	while(res_ptr < res_start) {
		*res_ptr = 0;
		res_ptr++;
	}
	while(res_ptr < res_end) {
		*res_ptr = *op2_ptr;
		op2_ptr++;
		res_ptr++;
		if(op2_ptr >= op2_end) {
			op2_ptr = op2_start;
		}
	}
}

void qb_do_array_intersect_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	float32_t *op1_end = op1_ptr + op1_count;
	float32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(float32_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	float64_t *op1_end = op1_ptr + op1_count;
	float64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(float64_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, uint32_t op3, int8_t *res_ptr, uint32_t res_count) {
	int8_t *op1_end = op1_ptr + op1_count;
	int8_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S08(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(int8_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, uint32_t op3, int16_t *res_ptr, uint32_t res_count) {
	int16_t *op1_end = op1_ptr + op1_count;
	int16_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S16(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(int16_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, uint32_t op3, int32_t *res_ptr, uint32_t res_count) {
	int32_t *op1_end = op1_ptr + op1_count;
	int32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(int32_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, uint32_t op3, int64_t *res_ptr, uint32_t res_count) {
	int64_t *op1_end = op1_ptr + op1_count;
	int64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				*res_ptr = *op1_ptr;
				res_ptr++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				memcpy(res_ptr, op1_ptr, sizeof(int64_t) * op3);
				res_ptr += op3;
			}
			op1_ptr += op3;
		}
	}
}

void qb_do_array_intersect_count_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	float32_t *op1_end = op1_ptr + op1_count;
	float32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_intersect_count_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	float64_t *op1_end = op1_ptr + op1_count;
	float64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_F64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_intersect_count_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int8_t *op1_end = op1_ptr + op1_count;
	int8_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S08(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_intersect_count_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int16_t *op1_end = op1_ptr + op1_count;
	int16_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S16(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_intersect_count_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int32_t *op1_end = op1_ptr + op1_count;
	int32_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S32(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_intersect_count_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t *res_ptr) {
	int64_t *op1_end = op1_ptr + op1_count;
	int64_t *op2_end = op2_ptr + op2_count, *op2_start = op2_ptr;
	uint32_t count = 0;
	if(op3 == 1) {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr++) {
				if(*op2_ptr == *op1_ptr) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr++;
		}
	} else {
		while(op1_ptr < op1_end) {
			int32_t found = FALSE;
			for(op2_ptr = op2_start; op2_ptr < op2_end; op2_ptr += op3) {
				if(qb_compare_array_S64(op1_ptr, op3, op2_ptr, op3) == 0) {
					found = TRUE;
					break;
				}
			}
			if(found) {
				count++;
			}
			op1_ptr += op3;
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_max_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		float32_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		float64_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int8_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int16_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int32_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int64_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint8_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint16_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint32_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_max_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint64_t biggest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] > biggest) {
				biggest = op1_ptr[i];
			}
		}
		(*res_ptr) = biggest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		float32_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		float64_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int8_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int16_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int32_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		int64_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint8_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint16_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint32_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_min_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr) {
	if(op1_count > 0) {
		uint32_t i;
		uint64_t smallest = op1_ptr[0];
		for(i = 1; i < op1_count; i++) {
			if(op1_ptr[i] < smallest) {
				smallest = op1_ptr[i];
			}
		}
		(*res_ptr) = smallest;
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_pad_F32(float32_t *op1_ptr, uint32_t op1_count, int32_t op2, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		float32_t *res_end;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(float32_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(float32_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(float32_t) * op1_count);
	}
}

void qb_do_array_pad_F64(float64_t *op1_ptr, uint32_t op1_count, int32_t op2, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		float64_t *res_end;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(float64_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(float64_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(float64_t) * op1_count);
	}
}

void qb_do_array_pad_I08(int8_t *op1_ptr, uint32_t op1_count, int32_t op2, int8_t *op3_ptr, uint32_t op3_count, int8_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		int8_t *res_end;
		int8_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(int8_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(int8_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(int8_t) * op1_count);
	}
}

void qb_do_array_pad_I16(int16_t *op1_ptr, uint32_t op1_count, int32_t op2, int16_t *op3_ptr, uint32_t op3_count, int16_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		int16_t *res_end;
		int16_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(int16_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(int16_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(int16_t) * op1_count);
	}
}

void qb_do_array_pad_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t *op3_ptr, uint32_t op3_count, int32_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		int32_t *res_end;
		int32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(int32_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(int32_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(int32_t) * op1_count);
	}
}

void qb_do_array_pad_I64(int64_t *op1_ptr, uint32_t op1_count, int32_t op2, int64_t *op3_ptr, uint32_t op3_count, int64_t *res_ptr, uint32_t res_count) {
	if(res_count > op1_count) {
		int64_t *res_end;
		int64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		if(op2 > 0) {
			memcpy(res_ptr, op1_ptr, sizeof(int64_t) * op1_count);
			res_end = res_ptr + res_count;
			res_ptr += op1_count;
		} else {
			res_end = res_ptr + (res_count - op1_count);
			memcpy(res_end, op1_ptr, sizeof(int64_t) * op1_count);
		}
		while(res_ptr < res_end) {
			*res_ptr = *op3_ptr;
			op3_ptr++;
			res_ptr++;
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	} else {
		memcpy(res_ptr, op1_ptr, sizeof(int64_t) * op1_count);
	}
}

void qb_do_array_product_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr) {
	uint32_t i;
	float32_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr) {
	uint32_t i;
	float64_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr) {
	uint32_t i;
	int8_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr) {
	uint32_t i;
	int16_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	uint32_t i;
	int32_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr) {
	uint32_t i;
	int64_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr) {
	uint32_t i;
	uint8_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr) {
	uint32_t i;
	uint16_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	uint32_t i;
	uint32_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_product_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr) {
	uint32_t i;
	uint64_t product = 1;
	for(i = 0; i < op1_count; i++) {
		product *= op1_ptr[i];
	}
	(*res_ptr) = product;
}

void qb_do_array_random_U32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *res_ptr) {
	USE_TSRM
	uint32_t num_key = 0, num_req = op2, num_avail = op1;
	while(num_req > 0) {
		double randval = php_rand(TSRMLS_C);
		if ((double) (randval / (PHP_RAND_MAX + 1.0)) < (double) num_req / (double) num_avail) {
			*res_ptr = num_key;
			res_ptr++;
			num_req--;
		}
		num_avail--;
		if(num_key < op1 - 1) {
			num_key++;
		}
	}
}

void qb_do_array_replace_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, float32_t *res_ptr, uint32_t *res_count_ptr) {
	float32_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			float32_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(float32_t));
		}
		res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(float32_t)));
		if(remaining_len != 0 && change_len > 0) {
			float32_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(float32_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		float32_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_replace_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, float64_t *res_ptr, uint32_t *res_count_ptr) {
	float64_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			float64_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(float64_t));
		}
		res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(float64_t)));
		if(remaining_len != 0 && change_len > 0) {
			float64_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(float64_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		float64_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_replace_I08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, int8_t *res_ptr, uint32_t *res_count_ptr) {
	int8_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			int8_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int8_t));
		}
		res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(int8_t)));
		if(remaining_len != 0 && change_len > 0) {
			int8_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int8_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		int8_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_replace_I16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, int16_t *res_ptr, uint32_t *res_count_ptr) {
	int16_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			int16_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int16_t));
		}
		res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(int16_t)));
		if(remaining_len != 0 && change_len > 0) {
			int16_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int16_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		int16_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_replace_I32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, int32_t *res_ptr, uint32_t *res_count_ptr) {
	int32_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			int32_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int32_t));
		}
		res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(int32_t)));
		if(remaining_len != 0 && change_len > 0) {
			int32_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int32_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		int32_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_replace_I64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t op3, uint32_t *op4_ptr, uint32_t op5, uint32_t op6, int64_t *res_ptr, uint32_t *res_count_ptr) {
	int64_t *op1_end = op1_ptr + op1_count;
	uint32_t replacement_len = op1_count, extraction_len;
	uint32_t start_index, end_index;
	if(op2 >= 0) {
		start_index = op2;
	} else {
		start_index = (*op4_ptr) + op2;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op3 >= 0) {
		end_index = start_index + op3;
		if(end_index > (*op4_ptr)) {
			end_index = (*op4_ptr);
		}
	} else {
		end_index = (*op4_ptr) + op3;
	}
	extraction_len = (end_index - start_index) * op5;
	if(extraction_len != replacement_len) {
		uint32_t remaining_len = ((*op4_ptr) - end_index) * op5;
		int32_t change_len = replacement_len - extraction_len;
		if(remaining_len != 0 && change_len < 0) {
			int64_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int64_t));
		}
		res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op6], ((*res_count_ptr) + change_len) * sizeof(int64_t)));
		if(remaining_len != 0 && change_len > 0) {
			int64_t *end_ptr = res_ptr + end_index * op5, *new_end_ptr = end_ptr + change_len;
			memmove(new_end_ptr, end_ptr, remaining_len * sizeof(int64_t));
		}
		if(op4_ptr != res_count_ptr) {
			*op4_ptr += change_len / ((int32_t) op5);
		}
		(*res_count_ptr) += change_len;
	}
	if(replacement_len > 0) {
		int64_t *ptr = res_ptr + start_index * op5;
		while(op1_ptr < op1_end) {
			*ptr = *op1_ptr;
			op1_ptr++;
			ptr++;
		}
	}
}

void qb_do_array_resize_1_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_1_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_1_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_1_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_1_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_1_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr))) {
		uint32_t old_dims[1] = {
			(*op3_ptr)
		};
		uint32_t new_dims[1] = {
			op1
		};
		uint32_t old_length = (*op2_ptr), new_length = op1;
		
		(*op2_ptr) = op1;
		(*op3_ptr) = op1;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 1);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 1);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op4], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 1);
			}
		}
	}
}

void qb_do_array_resize_2_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_2_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_2_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_2_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_2_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_2_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr))) {
		uint32_t old_dims[2] = {
			(*op3_ptr), (*op6_ptr)
		};
		uint32_t new_dims[2] = {
			op1, op4
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4;
		
		(*op2_ptr) = op1 * op4;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4;
		(*op6_ptr) = op4;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 2);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 2);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op7], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 2);
			}
		}
	}
}

void qb_do_array_resize_3_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_3_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_3_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_3_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_3_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_3_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr))) {
		uint32_t old_dims[3] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr)
		};
		uint32_t new_dims[3] = {
			op1, op4, op7
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7;
		
		(*op2_ptr) = op1 * op4 * op7;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7;
		(*op9_ptr) = op7;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 3);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 3);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op10], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 3);
			}
		}
	}
}

void qb_do_array_resize_4_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_4_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_4_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_4_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_4_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_4_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr))) {
		uint32_t old_dims[4] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr)
		};
		uint32_t new_dims[4] = {
			op1, op4, op7, op10
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10;
		
		(*op2_ptr) = op1 * op4 * op7 * op10;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10;
		(*op12_ptr) = op10;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 4);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 4);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op13], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 4);
			}
		}
	}
}

void qb_do_array_resize_5_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_5_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_5_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_5_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_5_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_5_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr))) {
		uint32_t old_dims[5] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr)
		};
		uint32_t new_dims[5] = {
			op1, op4, op7, op10, op13
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13;
		(*op15_ptr) = op13;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 5);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 5);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op16], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 5);
			}
		}
	}
}

void qb_do_array_resize_6_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_6_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_6_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_6_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_6_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_6_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr))) {
		uint32_t old_dims[6] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr)
		};
		uint32_t new_dims[6] = {
			op1, op4, op7, op10, op13, op16
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16;
		(*op18_ptr) = op16;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 6);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 6);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op19], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 6);
			}
		}
	}
}

void qb_do_array_resize_7_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_7_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_7_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_7_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_7_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_7_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr))) {
		uint32_t old_dims[7] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr)
		};
		uint32_t new_dims[7] = {
			op1, op4, op7, op10, op13, op16, op19
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19;
		(*op21_ptr) = op19;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 7);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 7);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op22], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 7);
			}
		}
	}
}

void qb_do_array_resize_8_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, float32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float32_t));
		} else {
			res_ptr = (float32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float32_t)));
			if(old_length > 0) {
				qb_relocate_elements_F32(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_resize_8_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, float64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float64_t));
		} else {
			res_ptr = (float64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(float64_t)));
			if(old_length > 0) {
				qb_relocate_elements_F64(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_resize_8_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, int8_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int8_t));
		} else {
			res_ptr = (int8_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int8_t)));
			if(old_length > 0) {
				qb_relocate_elements_I08(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_resize_8_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, int16_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int16_t));
		} else {
			res_ptr = (int16_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int16_t)));
			if(old_length > 0) {
				qb_relocate_elements_I16(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_resize_8_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, int32_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int32_t));
		} else {
			res_ptr = (int32_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int32_t)));
			if(old_length > 0) {
				qb_relocate_elements_I32(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_resize_8_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t *op2_ptr, uint32_t *op3_ptr, uint32_t op4, uint32_t *op5_ptr, uint32_t *op6_ptr, uint32_t op7, uint32_t *op8_ptr, uint32_t *op9_ptr, uint32_t op10, uint32_t *op11_ptr, uint32_t *op12_ptr, uint32_t op13, uint32_t *op14_ptr, uint32_t *op15_ptr, uint32_t op16, uint32_t *op17_ptr, uint32_t *op18_ptr, uint32_t op19, uint32_t *op20_ptr, uint32_t *op21_ptr, uint32_t op22, uint32_t *op23_ptr, uint32_t *op24_ptr, uint32_t op25, int64_t *res_ptr) {
	if(EXPECTED(op1 != (*op3_ptr) || op4 != (*op6_ptr) || op7 != (*op9_ptr) || op10 != (*op12_ptr) || op13 != (*op15_ptr) || op16 != (*op18_ptr) || op19 != (*op21_ptr) || op22 != (*op24_ptr))) {
		uint32_t old_dims[8] = {
			(*op3_ptr), (*op6_ptr), (*op9_ptr), (*op12_ptr), (*op15_ptr), (*op18_ptr), (*op21_ptr), (*op24_ptr)
		};
		uint32_t new_dims[8] = {
			op1, op4, op7, op10, op13, op16, op19, op22
		};
		uint32_t old_length = (*op2_ptr), new_length = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		
		(*op2_ptr) = op1 * op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op3_ptr) = op1;
		(*op5_ptr) = op4 * op7 * op10 * op13 * op16 * op19 * op22;
		(*op6_ptr) = op4;
		(*op8_ptr) = op7 * op10 * op13 * op16 * op19 * op22;
		(*op9_ptr) = op7;
		(*op11_ptr) = op10 * op13 * op16 * op19 * op22;
		(*op12_ptr) = op10;
		(*op14_ptr) = op13 * op16 * op19 * op22;
		(*op15_ptr) = op13;
		(*op17_ptr) = op16 * op19 * op22;
		(*op18_ptr) = op16;
		(*op20_ptr) = op19 * op22;
		(*op21_ptr) = op19;
		(*op23_ptr) = op22;
		(*op24_ptr) = op22;
		
		if(new_length > old_length) {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 8);
			}
		} else if(old_length < new_length) {
			if(new_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 8);
			}
			qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int64_t));
		} else {
			res_ptr = (int64_t *) (((int8_t *) res_ptr) + qb_resize_segment(&cxt->function->local_storage->segments[op25], new_length * sizeof(int64_t)));
			if(old_length > 0) {
				qb_relocate_elements_I64(res_ptr, old_dims, new_dims, 8);
			}
		}
	}
}

void qb_do_array_reverse_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			float32_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		float32_t *t = do_alloca(op2 * sizeof(float32_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(float32_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(float32_t));
			memcpy(res_ptr + j, t, op2 * sizeof(float32_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_reverse_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			float64_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		float64_t *t = do_alloca(op2 * sizeof(float64_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(float64_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(float64_t));
			memcpy(res_ptr + j, t, op2 * sizeof(float64_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_reverse_I08(int8_t *op1_ptr, uint32_t op1_count, uint32_t op2, int8_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			int8_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		int8_t *t = do_alloca(op2 * sizeof(int8_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(int8_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(int8_t));
			memcpy(res_ptr + j, t, op2 * sizeof(int8_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_reverse_I16(int16_t *op1_ptr, uint32_t op1_count, uint32_t op2, int16_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			int16_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		int16_t *t = do_alloca(op2 * sizeof(int16_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(int16_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(int16_t));
			memcpy(res_ptr + j, t, op2 * sizeof(int16_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_reverse_I32(int32_t *op1_ptr, uint32_t op1_count, uint32_t op2, int32_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			int32_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		int32_t *t = do_alloca(op2 * sizeof(int32_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(int32_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(int32_t));
			memcpy(res_ptr + j, t, op2 * sizeof(int32_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_reverse_I64(int64_t *op1_ptr, uint32_t op1_count, uint32_t op2, int64_t *res_ptr, uint32_t res_count) {
	uint32_t i, j;
	if(op2 == 1) {
		for(i = 0, j = op1_count - 1; i <= j; i++, j--) {
			int64_t t = op1_ptr[i];
			res_ptr[i] = op1_ptr[j];
			res_ptr[j] = t;
		}
	} else {
		ALLOCA_FLAG(use_heap)
		int64_t *t = do_alloca(op2 * sizeof(int64_t), use_heap);
		for(i = 0, j = op1_count - op2; i <= j; i += op2, j -= op2) {
			memcpy(t, op1_ptr + i, op2 * sizeof(int64_t));
			memcpy(res_ptr + i, op1_ptr + j, op2 * sizeof(int64_t));
			memcpy(res_ptr + j, t, op2 * sizeof(int64_t));
		}
		free_alloca(t, use_heap);
	}
}

void qb_do_array_search_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t op2, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i;
	for(i = 0; i < op1_count; i++) {
		if(op1_ptr[i] == op2) {
			index = i;
			break;
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_search_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	int32_t index = -1;
	uint32_t i, j, k;
	for(i = 0, j = 0; j < op1_count; i++, j += op2_count) {
		if(op1_ptr[j] == op2_ptr[0]) {
			for(k = 1; k < op2_count; k++) {
				if(op1_ptr[j + k] != op2_ptr[k]) {
					break;
				}
			}
			if(k == op2_count) {
				index = i;
				break;
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_array_slice_F32(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	float32_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		float32_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_F64(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	float64_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		float64_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_I08(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, int8_t *op5_ptr, uint32_t op5_count, int8_t *res_ptr, uint32_t res_count) {
	int8_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		int8_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_I16(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, int16_t *op5_ptr, uint32_t op5_count, int16_t *res_ptr, uint32_t res_count) {
	int16_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		int16_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_I32(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, int32_t *op5_ptr, uint32_t op5_count, int32_t *res_ptr, uint32_t res_count) {
	int32_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		int32_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_I64(int32_t op1, int32_t op2, uint32_t op3, uint32_t op4, int64_t *op5_ptr, uint32_t op5_count, int64_t *res_ptr, uint32_t res_count) {
	int64_t *res_end = res_ptr + res_count;
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = (op3 > (uint32_t) -op1) ? op3 + op1 : 0;
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		int64_t *ptr = op5_ptr + (start_index * op4);
		while(res_ptr < res_end) {
			*res_ptr = *ptr;
			res_ptr++;
			ptr++;
		}
	} else {
		while(res_ptr < res_end) {
			*res_ptr = 0;
			res_ptr++;
		}
	}
}

void qb_do_array_slice_count_I32(int32_t op1, int32_t op2, uint32_t op3, uint32_t *res_ptr) {
	uint32_t start_index, end_index;
	if(op1 >= 0) {
		start_index = op1;
	} else {
		start_index = op3 + op1;
		if((int32_t) start_index < 0) {
			start_index = 0;
		}
	}
	if(op2 >= 0) {
		end_index = start_index + op2;
		if(end_index > op3) {
			end_index = op3;
		}
	} else {
		end_index = op3 + op2;
	}
	if(start_index < end_index) {
		(*res_ptr) = (end_index - start_index);
	} else {
		(*res_ptr) = 0;
	}
}

void qb_do_array_sum_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr) {
	uint32_t i;
	float32_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr) {
	uint32_t i;
	float64_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr) {
	uint32_t i;
	int8_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr) {
	uint32_t i;
	int16_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	uint32_t i;
	int32_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr) {
	uint32_t i;
	int64_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr) {
	uint32_t i;
	uint8_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr) {
	uint32_t i;
	uint16_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	uint32_t i;
	uint32_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_sum_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr) {
	uint32_t i;
	uint64_t sum = 0;
	for(i = 0; i < op1_count; i++) {
		sum += op1_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_array_unique_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_I08(int8_t *op1_ptr, uint32_t op1_count, uint32_t op2, int8_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_I16(int16_t *op1_ptr, uint32_t op1_count, uint32_t op2, int16_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_I32(int32_t *op1_ptr, uint32_t op1_count, uint32_t op2, int32_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_I64(int64_t *op1_ptr, uint32_t op1_count, uint32_t op2, int64_t *res_ptr, uint32_t res_count) {
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				*res_ptr = op1_ptr[i];
				res_ptr++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				for(k = 0; k < op2; k++) {
					*res_ptr = op1_ptr[i + k];
					res_ptr++;
				}
			}
		}
	}
}

void qb_do_array_unique_count_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_unique_count_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_unique_count_I08(int8_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_unique_count_I16(int16_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_unique_count_I32(int32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_array_unique_count_I64(int64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t *res_ptr) {
	uint32_t count = 0;
	uint32_t i, j, k;
	if(op2 == 1) {
		for(i = 0; i < op1_count; i++) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j++) {
				if(op1_ptr[j] == op1_ptr[i]) {
					repeat = TRUE;
					break;
				}
			}
			if(!repeat) {
				count++;
			}
		}
	} else {
		for(i = 0; i < op1_count; i += op2) {
			int32_t repeat = FALSE;
			for(j = 0; j < i; j += op2) {
				if(op1_ptr[j] == op1_ptr[i]) {
					int32_t match = TRUE;
					for(k = 1; k < op2; k++) {
						if(op1_ptr[j + k] != op1_ptr[i + k]) {
							match = FALSE;
							break;
						}
					}
					if(match) {
						repeat = TRUE;
						break;
					}
				}
			}
			if(!repeat) {
				count++;
			}
		}
	}
	(*res_ptr) = count;
}

void qb_do_asin_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = asinf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_asin_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = asin((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_asinh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = asinhf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_asinh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = asinh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_atan2_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atan2f((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_atan2_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atan2((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_atan_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atanf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_atan_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atan((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_atanh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atanhf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_atanh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = atanh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_bitwise_and_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) & (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_and_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) & (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_and_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) & (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_and_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) & (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_not_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ~(*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_bitwise_not_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ~(*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_bitwise_not_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ~(*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_bitwise_not_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ~(*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_bitwise_or_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) | (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_or_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) | (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_or_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) | (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_or_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) | (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_xor_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) ^ (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_xor_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) ^ (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_xor_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) ^ (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_bitwise_xor_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) ^ (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_F64(float32_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_S08(float32_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_S16(float32_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_S32(float32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_S64(float32_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_U08(float32_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_U16(float32_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_U32(float32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F32_U64(float32_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_F32(float64_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_S08(float64_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_S16(float64_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_S32(float64_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_S64(float64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_U08(float64_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_U16(float64_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_U32(float64_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_F64_U64(float64_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (uint64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I16_I08(int16_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I32_I08(int32_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I32_I16(int32_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I64_I08(int64_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int8_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I64_I16(int64_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_I64_I32(int64_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S08_F32(int8_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S08_F64(int8_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S08_I16(int8_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S08_I32(int8_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S08_I64(int8_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S16_F32(int16_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S16_F64(int16_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S16_I32(int16_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S16_I64(int16_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S32_F32(int32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S32_F64(int32_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S32_I64(int32_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S64_F32(int64_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_S64_F64(int64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U08_F32(uint8_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U08_F64(uint8_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U08_I16(uint8_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int16_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U08_I32(uint8_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U08_I64(uint8_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U16_F32(uint16_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U16_F64(uint16_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U16_I32(uint16_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U16_I64(uint16_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U32_F32(uint32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U32_F64(uint32_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U32_I64(uint32_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (int64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U64_F32(uint64_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cast_multiple_times_U64_F64(uint64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_ceil_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ceilf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_ceil_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ceil((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_choose_size_largest_of_three_U32(uint32_t op1, uint32_t op2, uint32_t op3, uint32_t op4, uint32_t op5, uint32_t op6, uint32_t *res_ptr) {
	if(op1 >= op3) {
		(*res_ptr) = op2;
	} else {
		(*res_ptr) = op4;
	}
	if(op1 >= op3) {
		if(op1 >= op5) {
			(*res_ptr) = op2;
		} else {
			(*res_ptr) = op6;
		}
	} else {
		if(op3 >= op5) {
			(*res_ptr) = op4;
		} else {
			(*res_ptr) = op6;
		}
	}
}

void qb_do_clamp_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_clamp_F32((*op1_ptr), (*op2_ptr), (*op3_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_clamp_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_clamp_F64((*op1_ptr), (*op2_ptr), (*op3_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_clear_array_resize_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, float32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, float64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, int8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, int16_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, int32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, int64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op1], 0);
}

void qb_do_clear_array_resize_update_dimension_F32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, float32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_array_resize_update_dimension_F64(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, float64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_array_resize_update_dimension_I08(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, int8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_array_resize_update_dimension_I16(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, int16_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_array_resize_update_dimension_I32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, int32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_array_resize_update_dimension_I64(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op2, int64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i;
	for(i = 0; i < (*res_count_ptr); i++) {
		res_ptr[i] = 0;
	}
	(*op1_ptr) = 0;
	(*res_count_ptr) = 0;
	qb_resize_segment(&cxt->function->local_storage->segments[op2], 0);
}

void qb_do_clear_element_resize_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, float32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(float32_t));
	}
}

void qb_do_clear_element_resize_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, float64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(float64_t));
	}
}

void qb_do_clear_element_resize_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, int8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(int8_t));
	}
}

void qb_do_clear_element_resize_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, int16_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(int16_t));
	}
}

void qb_do_clear_element_resize_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, int32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(int32_t));
	}
}

void qb_do_clear_element_resize_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t op3, int64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		qb_resize_segment(&cxt->function->local_storage->segments[op3], end * sizeof(int64_t));
	}
}

void qb_do_clear_element_resize_update_dimension_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, float32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_clear_element_resize_update_dimension_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, float64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_clear_element_resize_update_dimension_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, int8_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_clear_element_resize_update_dimension_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, int16_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_clear_element_resize_update_dimension_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, int32_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_clear_element_resize_update_dimension_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *op3_ptr, uint32_t op4, int64_t *res_ptr, uint32_t *res_count_ptr) {
	uint32_t i, shift = op2, start = op1 * op2, end = (*res_count_ptr) - shift;
	if(start <= end) {
		for(i = start; i < end; i++) {
			res_ptr[i] = res_ptr[i + shift];
		}
		for(i = end; i < (*res_count_ptr); i++) {
			res_ptr[i] = 0;
		}
		(*res_count_ptr) = end;
		(*op3_ptr)--;
		qb_resize_segment(&cxt->function->local_storage->segments[op4], end * sizeof(uint32_t));
	}
}

void qb_do_complex_abs_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	res_ptr[0] = (float32_t) sqrt(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
}

void qb_do_complex_abs_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	res_ptr[0] = (float64_t) sqrt(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
}

void qb_do_complex_abs_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_abs_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_abs_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_abs_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_argument_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	res_ptr[0] = (float32_t) atan2(op1_ptr[1], op1_ptr[0]);
}

void qb_do_complex_argument_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	res_ptr[0] = (float64_t) atan2(op1_ptr[1], op1_ptr[0]);
}

void qb_do_complex_argument_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_argument_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_argument_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_argument_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_cos_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = cosf(op1_ptr[0]) * coshf(op1_ptr[1]);
	float32_t i = -sinf(op1_ptr[0]) * sinhf(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_cos_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = cos(op1_ptr[0]) * cosh(op1_ptr[1]);
	float64_t i = -sin(op1_ptr[0]) * sinh(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_cos_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_cos_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_cos_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_cos_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_cosh_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = coshf(op1_ptr[0]) * cosf(op1_ptr[1]);
	float32_t i = sinhf(op1_ptr[0]) * sinf(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_cosh_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = cosh(op1_ptr[0]) * cos(op1_ptr[1]);
	float64_t i = sinh(op1_ptr[0]) * sin(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_cosh_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_cosh_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_cosh_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_cosh_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_divide_2x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t w = op2_ptr[0] * op2_ptr[0] + op2_ptr[1] * op2_ptr[1];
	float32_t r = ((op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1])) / w;
	float32_t i = ((op1_ptr[1] * op2_ptr[0]) - (op1_ptr[0] * op2_ptr[1])) / w;
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_divide_2x_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t w = op2_ptr[0] * op2_ptr[0] + op2_ptr[1] * op2_ptr[1];
	float64_t r = ((op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1])) / w;
	float64_t i = ((op1_ptr[1] * op2_ptr[0]) - (op1_ptr[0] * op2_ptr[1])) / w;
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_divide_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_divide_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_divide_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_divide_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_exp_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t w = expf(op1_ptr[0]);
	float32_t r = w * cosf(op1_ptr[1]);
	float32_t i = w * sinf(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_exp_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t w = exp(op1_ptr[0]);
	float64_t r = w * cos(op1_ptr[1]);
	float64_t i = w * sin(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_exp_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_exp_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_exp_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_exp_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_log_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t w = sqrtf(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
	float32_t r = logf(w);
	float32_t i = atan2f(op1_ptr[1], op1_ptr[0]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_log_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t w = sqrt(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
	float64_t r = log(w);
	float64_t i = atan2(op1_ptr[1], op1_ptr[0]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_log_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_log_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_log_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_log_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_multiply_2x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t r = (op1_ptr[0] * op2_ptr[0]) - (op1_ptr[1] * op2_ptr[1]);
	float32_t i = (op1_ptr[0] * op2_ptr[1]) + (op1_ptr[1] * op2_ptr[0]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_multiply_2x_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t r = (op1_ptr[0] * op2_ptr[0]) - (op1_ptr[1] * op2_ptr[1]);
	float64_t i = (op1_ptr[0] * op2_ptr[1]) + (op1_ptr[1] * op2_ptr[0]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_multiply_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_multiply_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_multiply_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_multiply_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_pow_2x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t u = atan2f(op1_ptr[1], op1_ptr[0]);
	float32_t v = op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1];
	float32_t w = 1;
	float32_t x = powf(v, 0.5f * op2_ptr[0]);
	float32_t y = op2_ptr[0] * u;
	float32_t z = 0;
	if(op2_ptr[1] != 0) {
		z = 0.5f * op2_ptr[1] * logf(v);
		w = expf(-op2_ptr[1] * u);
	}
	res_ptr[0] = x * w * cosf(y + z);
	res_ptr[1] = x * w * sinf(y + z);
}

void qb_do_complex_pow_2x_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t u = atan2(op1_ptr[1], op1_ptr[0]);
	float64_t v = op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1];
	float64_t w = 1;
	float64_t x = pow(v, 0.5 * op2_ptr[0]);
	float64_t y = op2_ptr[0] * u;
	float64_t z = 0;
	if(op2_ptr[1] != 0) {
		z = 0.5 * op2_ptr[1] * log(v);
		w = exp(-op2_ptr[1] * u);
	}
	res_ptr[0] = x * w * cos(y + z);
	res_ptr[1] = x * w * sin(y + z);
}

void qb_do_complex_pow_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_pow_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_pow_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_pow_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_complex_sin_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = sinf(op1_ptr[0]) * coshf(op1_ptr[1]);
	float32_t i = cosf(op1_ptr[0]) * sinhf(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_sin_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = sin(op1_ptr[0]) * cosh(op1_ptr[1]);
	float64_t i = cos(op1_ptr[0]) * sinh(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_sin_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_sin_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_sin_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_sin_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_sinh_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t r = sinhf(op1_ptr[0]) * cosf(op1_ptr[1]);
	float32_t i = coshf(op1_ptr[0]) * sinf(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_sinh_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t r = sinh(op1_ptr[0]) * cos(op1_ptr[1]);
	float64_t i = cosh(op1_ptr[0]) * sin(op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_sinh_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_sinh_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_sinh_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_sinh_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_square_root_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t s = (op1_ptr[1] > 0 ? 1.0f : ((op1_ptr[1] < 0 ? -1.0f : 0.0f)));
	float32_t w = sqrtf(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
	float32_t r = sqrtf(0.5f * (op1_ptr[0] + w));
	float32_t i = (s) ? s * sqrtf(0.5f * (-op1_ptr[0] + w)) : 0;
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_square_root_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t s = (op1_ptr[1] > 0 ? 1.0 : ((op1_ptr[1] < 0 ? -1.0 : 0.0)));
	float64_t w = sqrt(op1_ptr[0] * op1_ptr[0] + op1_ptr[1] * op1_ptr[1]);
	float64_t r = sqrt(0.5 * (op1_ptr[0] + w));
	float64_t i = (s) ? s * sqrt(0.5 * (-op1_ptr[0] + w)) : 0;
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_square_root_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_square_root_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_square_root_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_square_root_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_tan_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t w = 1.0f / (cosf(2.0f * op1_ptr[0]) + coshf(2.0f * op1_ptr[1]));
	float32_t r = w * sinf(2.0f * op1_ptr[0]);
	float32_t i = w * sinhf(2.0f * op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_tan_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t w = 1.0 / (cos(2.0 * op1_ptr[0]) + cosh(2.0 * op1_ptr[1]));
	float64_t r = w * sin(2.0 * op1_ptr[0]);
	float64_t i = w * sinh(2.0 * op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_tan_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_tan_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_tan_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_tan_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_tanh_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t w = 1.0f / (coshf(2.0f * op1_ptr[0]) + cosf(2.0f * op1_ptr[1]));
	float32_t r = w * sinhf(2.0f * op1_ptr[0]);
	float32_t i = w * sinf(2.0f * op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_tanh_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t w = 1.0 / (cosh(2.0 * op1_ptr[0]) + cos(2.0 * op1_ptr[1]));
	float64_t r = w * sinh(2.0 * op1_ptr[0]);
	float64_t i = w * sin(2.0 * op1_ptr[1]);
	res_ptr[0] = r;
	res_ptr[1] = i;
}

void qb_do_complex_tanh_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_tanh_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_complex_tanh_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_complex_tanh_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_convert_from_string_F32(uint8_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = (float32_t) zend_strtod(buffer, NULL);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_F64(uint8_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = zend_strtod(buffer, NULL);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_S08(uint8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = (int8_t) strtol(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_S16(uint8_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = (int16_t) strtol(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_S32(uint8_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = strtol(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_S64(uint8_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = strtoll(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = (uint8_t) strtoul(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_U16(uint8_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = (uint16_t) strtoul(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_U32(uint8_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = strtoul(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_convert_from_string_U64(uint8_t *op1_ptr, uint32_t op1_count, uint64_t *res_ptr) {
	ALLOCA_FLAG(use_heap)
	char *buffer = do_alloca(op1_count + 1, use_heap);
	memcpy(buffer, op1_ptr, op1_count);
	buffer[op1_count] = '\0';
	(*res_ptr) = strtoull(buffer, NULL, 10);
	free_alloca(buffer, use_heap);
}

void qb_do_copy_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
				res_ptr[2] = op1_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
				res_ptr[2] = op1_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
				res_ptr[2] = op1_ptr[2];
				res_ptr[3] = op1_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0];
				res_ptr[1] = op1_ptr[1];
				res_ptr[2] = op1_ptr[2];
				res_ptr[3] = op1_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_copy_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cos_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = cosf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cos_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = cos((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cosh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = coshf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cosh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = cosh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_cross_product_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_cross_product_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_cross_product_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_3x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_cross_product_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_3x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_cross_product_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_4x_F32(op1_ptr, op2_ptr, op3_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			op3_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_cross_product_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_cross_product_4x_F64(op1_ptr, op2_ptr, op3_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			op3_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_decrement_2x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
			}
			
			res_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_2x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
			}
			
			res_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_3x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
				--res_ptr[2];
			}
			
			res_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_3x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
				--res_ptr[2];
			}
			
			res_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_4x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
				--res_ptr[2];
				--res_ptr[3];
			}
			
			res_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_4x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--res_ptr[0];
				--res_ptr[1];
				--res_ptr[2];
				--res_ptr[3];
			}
			
			res_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_I08(int8_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_I16(int16_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_I32(int32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_decrement_multiple_times_I64(int64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				--(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_degree_to_radian_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * ((float32_t) (M_PI / 180.0));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_degree_to_radian_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * ((float64_t) (M_PI / 180.0));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0 * 2 + 0] * op1_ptr[1 * 2 + 1]) - (op1_ptr[0 * 2 + 1] * op1_ptr[1 * 2 + 0]);
			}
			
			res_ptr += 1;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0 * 2 + 0] * op1_ptr[1 * 2 + 1]) - (op1_ptr[0 * 2 + 1] * op1_ptr[1 * 2 + 0]);
			}
			
			res_ptr += 1;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_3x_F32(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_3x_F64(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_4x_F32(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_4x_F64(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr) {
	uint32_t matrix_rows = op2, matrix_cols = op2;
	if(matrix_rows == 4) {
		qb_do_determinant_4x_F32(op1_ptr, res_ptr);
	} else {
		ALLOCA_FLAG(use_heap)
		uint32_t minor_size = (matrix_rows - 1) * (matrix_cols - 1);
		float32_t *__restrict minor = do_alloca(minor_size * sizeof(float32_t), use_heap);
		uint32_t i, j, k, m, n;
		float32_t sign = 1, det = 0;
		for(m = 0; m < matrix_rows; m++) {
			float32_t a = op1_ptr[m];
			float32_t minor_det;
			for(i = 1, n = 0, k = matrix_rows; i < matrix_rows; i++) {
				for(j = 0; j < matrix_rows; j++, k++) {
					if(j != m) {
						minor[n] = op1_ptr[k];
						n++;
					}
				}
			}
			qb_do_determinant_F32(minor, 0, matrix_rows - 1, &minor_det);
			det += a * minor_det * sign;
			sign = -sign;
		}
		free_alloca(minor, use_heap);
		(*res_ptr) = det;
	}
}

void qb_do_determinant_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr) {
	uint32_t matrix_rows = op2, matrix_cols = op2;
	if(matrix_rows == 4) {
		qb_do_determinant_4x_F64(op1_ptr, res_ptr);
	} else {
		ALLOCA_FLAG(use_heap)
		uint32_t minor_size = (matrix_rows - 1) * (matrix_cols - 1);
		float64_t *__restrict minor = do_alloca(minor_size * sizeof(float64_t), use_heap);
		uint32_t i, j, k, m, n;
		float64_t sign = 1, det = 0;
		for(m = 0; m < matrix_rows; m++) {
			float64_t a = op1_ptr[m];
			float64_t minor_det;
			for(i = 1, n = 0, k = matrix_rows; i < matrix_rows; i++) {
				for(j = 0; j < matrix_rows; j++, k++) {
					if(j != m) {
						minor[n] = op1_ptr[k];
						n++;
					}
				}
			}
			qb_do_determinant_F64(minor, 0, matrix_rows - 1, &minor_det);
			det += a * minor_det * sign;
			sign = -sign;
		}
		free_alloca(minor, use_heap);
		(*res_ptr) = det;
	}
}

void qb_do_determinant_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_F32(op1_ptr, op1_count, op2, res_ptr);
			
			res_ptr += 1;
			op1_ptr += op2 * op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_determinant_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_determinant_F64(op1_ptr, op1_count, op2, res_ptr);
			
			res_ptr += 1;
			op1_ptr += op2 * op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_distance_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_2x_F32(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_2x_F64(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_3x_F32(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_3x_F64(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_4x_F32(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_4x_F64(op1_ptr, op2_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr) {
	uint32_t i, vector_width = op3;
	float32_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += (op1_ptr[i] - op2_ptr[i]) * (op1_ptr[i] - op2_ptr[i]);
	}
	(*res_ptr) = qb_fast_sqrtf(sum);
}

void qb_do_distance_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr) {
	uint32_t i, vector_width = op3;
	float64_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += (op1_ptr[i] - op2_ptr[i]) * (op1_ptr[i] - op2_ptr[i]);
	}
	(*res_ptr) = qb_fast_sqrt(sum);
}

void qb_do_distance_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, &(*res_ptr));
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_distance_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_distance_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, &(*res_ptr));
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
				res_ptr[2] = op1_ptr[2] / op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
				res_ptr[2] = op1_ptr[2] / op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
				res_ptr[2] = op1_ptr[2] / op2_ptr[2];
				res_ptr[3] = op1_ptr[3] / op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] / op2_ptr[0];
				res_ptr[1] = op1_ptr[1] / op2_ptr[1];
				res_ptr[2] = op1_ptr[2] / op2_ptr[2];
				res_ptr[3] = op1_ptr[3] / op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) / (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_divide_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) / (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]);
			}
			
			res_ptr += 1;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]);
			}
			
			res_ptr += 1;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]) + (op1_ptr[2] * op2_ptr[2]);
			}
			
			res_ptr += 1;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]) + (op1_ptr[2] * op2_ptr[2]);
			}
			
			res_ptr += 1;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]) + (op1_ptr[2] * op2_ptr[2]) + (op1_ptr[3] * op2_ptr[3]);
			}
			
			res_ptr += 1;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (op1_ptr[0] * op2_ptr[0]) + (op1_ptr[1] * op2_ptr[1]) + (op1_ptr[2] * op2_ptr[2]) + (op1_ptr[3] * op2_ptr[3]);
			}
			
			res_ptr += 1;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr) {
	uint32_t i, vector_width = op3;
	float32_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op2_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_dot_product_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr) {
	uint32_t i, vector_width = op3;
	float64_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op2_ptr[i];
	}
	(*res_ptr) = sum;
}

void qb_do_dot_product_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_dot_product_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_dot_product_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_dot_product_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_equal_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F32(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_equal_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F64(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_equal_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S08(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_equal_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S16(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_equal_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S32(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_equal_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S64(op1_ptr, op1_count, op2_ptr, op2_count) == 0);
}

void qb_do_exp2_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = exp2f((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_exp2_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = exp2((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_exp_m1_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = expm1f((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_exp_m1_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = expm1((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_exp_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = expf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_exp_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = exp((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_face_forward_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_3x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_3x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_4x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_4x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op3;
	float32_t dot_product;
	qb_do_dot_product_F32(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	if(dot_product > 0) {
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op1_ptr[i];
		}
	} else {
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = -op1_ptr[i];
		}
	}
}

void qb_do_face_forward_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op3;
	float64_t dot_product;
	qb_do_dot_product_F64(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	if(dot_product > 0) {
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op1_ptr[i];
		}
	} else {
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = -op1_ptr[i];
		}
	}
}

void qb_do_face_forward_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_face_forward_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_face_forward_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_floor_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) floorf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_floor_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) floor((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_floored_division_modulo_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) ((*op1_ptr) - (*op2_ptr) * floor((*op1_ptr) / (*op2_ptr)));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_floored_division_modulo_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) ((*op1_ptr) - (*op2_ptr) * floor((*op1_ptr) / (*op2_ptr)));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_fract_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - floorf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_fract_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - floor((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_gather_8x_F32(uint32_t op1, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_gather_8x_F64(uint32_t op1, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_gather_8x_I08(uint32_t op1, int8_t *op2_ptr, int8_t *res_ptr) {
	int8_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_gather_8x_I16(uint32_t op1, int16_t *op2_ptr, int16_t *res_ptr) {
	int16_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_gather_8x_I32(uint32_t op1, int32_t *op2_ptr, int32_t *res_ptr) {
	int32_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_gather_8x_I64(uint32_t op1, int64_t *op2_ptr, int64_t *res_ptr) {
	int64_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[(op1 >> 0) & 0x0007];
	v1 = op2_ptr[(op1 >> 3) & 0x0007];
	v2 = op2_ptr[(op1 >> 6) & 0x0007];
	v3 = op2_ptr[(op1 >> 9) & 0x0007];
	v4 = op2_ptr[(op1 >> 12) & 0x0007];
	v5 = op2_ptr[(op1 >> 15) & 0x0007];
	v6 = op2_ptr[(op1 >> 18) & 0x0007];
	v7 = op2_ptr[(op1 >> 21) & 0x0007];
	res_ptr[0] = v0;
	res_ptr[1] = v1;
	res_ptr[2] = v2;
	res_ptr[3] = v3;
	res_ptr[4] = v4;
	res_ptr[5] = v5;
	res_ptr[6] = v6;
	res_ptr[7] = v7;
}

void qb_do_hsl2rgb_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_hsl_to_rgb_F32(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsl2rgb_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_hsl_to_rgb_F64(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsl2rgb_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_hsl2rgb_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsl2rgb_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_hsl2rgb_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsv2rgb_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_hsv_to_rgb_F32(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsv2rgb_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_hsv_to_rgb_F64(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsv2rgb_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_hsv2rgb_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hsv2rgb_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_hsv2rgb_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_hypot_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) hypotf((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_hypot_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) hypot((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_increment_2x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
			}
			
			res_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_2x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
			}
			
			res_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_3x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
				++res_ptr[2];
			}
			
			res_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_3x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
				++res_ptr[2];
			}
			
			res_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_4x_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
				++res_ptr[2];
				++res_ptr[3];
			}
			
			res_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_4x_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++res_ptr[0];
				++res_ptr[1];
				++res_ptr[2];
				++res_ptr[3];
			}
			
			res_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_F32(float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_F64(float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_I08(int8_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_I16(int16_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_I32(int32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_increment_multiple_times_I64(int64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				++(*res_ptr);
			}
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_invert_matrix_2x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t p00 =  op1_ptr[1 * 2 + 1];
	float32_t p01 = -op1_ptr[0 * 2 + 1];
	float32_t p10 = -op1_ptr[1 * 2 + 0];
	float32_t p11 =  op1_ptr[0 * 2 + 0];
	float32_t det = (op1_ptr[0 * 2 + 0] * p00) + (op1_ptr[0 * 2 + 1] * p10);
	if(det != 0) {
		float32_t rdet = 1.0f / det;
		res_ptr[0 * 2 + 0] = p00 * rdet;
		res_ptr[0 * 2 + 1] = p01 * rdet;
		res_ptr[1 * 2 + 0] = p10 * rdet;
		res_ptr[1 * 2 + 1] = p11 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 4; i++) {
			res_ptr[i] = (float32_t) NAN;
		}
	}
}

void qb_do_invert_matrix_2x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t p00 =  op1_ptr[1 * 2 + 1];
	float64_t p01 = -op1_ptr[0 * 2 + 1];
	float64_t p10 = -op1_ptr[1 * 2 + 0];
	float64_t p11 =  op1_ptr[0 * 2 + 0];
	float64_t det = (op1_ptr[0 * 2 + 0] * p00) + (op1_ptr[0 * 2 + 1] * p10);
	if(det != 0) {
		float64_t rdet = 1.0 / det;
		res_ptr[0 * 2 + 0] = p00 * rdet;
		res_ptr[0 * 2 + 1] = p01 * rdet;
		res_ptr[1 * 2 + 0] = p10 * rdet;
		res_ptr[1 * 2 + 1] = p11 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 4; i++) {
			res_ptr[i] = (float64_t) NAN;
		}
	}
}

void qb_do_invert_matrix_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_3x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t p00 = (op1_ptr[1 * 3 + 1] * op1_ptr[2 * 3 + 2]) - (op1_ptr[1 * 3 + 2] * op1_ptr[2 * 3 + 1]);
	float32_t p01 = (op1_ptr[0 * 3 + 2] * op1_ptr[2 * 3 + 1]) - (op1_ptr[0 * 3 + 1] * op1_ptr[2 * 3 + 2]);
	float32_t p02 = (op1_ptr[0 * 3 + 1] * op1_ptr[1 * 3 + 2]) - (op1_ptr[0 * 3 + 2] * op1_ptr[1 * 3 + 1]);
	float32_t p10 = (op1_ptr[1 * 3 + 2] * op1_ptr[2 * 3 + 0]) - (op1_ptr[1 * 3 + 0] * op1_ptr[2 * 3 + 2]);
	float32_t p11 = (op1_ptr[0 * 3 + 0] * op1_ptr[2 * 3 + 2]) - (op1_ptr[0 * 3 + 2] * op1_ptr[2 * 3 + 0]);
	float32_t p12 = (op1_ptr[0 * 3 + 2] * op1_ptr[1 * 3 + 0]) - (op1_ptr[0 * 3 + 0] * op1_ptr[1 * 3 + 2]);
	float32_t p20 = (op1_ptr[1 * 3 + 0] * op1_ptr[2 * 3 + 1]) - (op1_ptr[1 * 3 + 1] * op1_ptr[2 * 3 + 0]);
	float32_t p21 = (op1_ptr[0 * 3 + 1] * op1_ptr[2 * 3 + 0]) - (op1_ptr[0 * 3 + 0] * op1_ptr[2 * 3 + 1]);
	float32_t p22 = (op1_ptr[0 * 3 + 0] * op1_ptr[1 * 3 + 1]) - (op1_ptr[0 * 3 + 1] * op1_ptr[1 * 3 + 0]);
	float32_t det = (op1_ptr[0 * 3 + 0] * p00) + (op1_ptr[0 * 3 + 1] * p10) + (op1_ptr[0 * 3 + 2] * p20);
	if(det != 0) {
		float32_t rdet = 1.0f / det;
		res_ptr[0 * 3 + 0] = p00 * rdet;
		res_ptr[0 * 3 + 1] = p01 * rdet;
		res_ptr[0 * 3 + 2] = p02 * rdet;
		res_ptr[1 * 3 + 0] = p10 * rdet;
		res_ptr[1 * 3 + 1] = p11 * rdet;
		res_ptr[1 * 3 + 2] = p12 * rdet;
		res_ptr[2 * 3 + 0] = p20 * rdet;
		res_ptr[2 * 3 + 1] = p21 * rdet;
		res_ptr[2 * 3 + 2] = p22 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 9; i++) {
			res_ptr[i] = (float32_t) NAN;
		}
	}
}

void qb_do_invert_matrix_3x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t p00 = (op1_ptr[1 * 3 + 1] * op1_ptr[2 * 3 + 2]) - (op1_ptr[1 * 3 + 2] * op1_ptr[2 * 3 + 1]);
	float64_t p01 = (op1_ptr[0 * 3 + 2] * op1_ptr[2 * 3 + 1]) - (op1_ptr[0 * 3 + 1] * op1_ptr[2 * 3 + 2]);
	float64_t p02 = (op1_ptr[0 * 3 + 1] * op1_ptr[1 * 3 + 2]) - (op1_ptr[0 * 3 + 2] * op1_ptr[1 * 3 + 1]);
	float64_t p10 = (op1_ptr[1 * 3 + 2] * op1_ptr[2 * 3 + 0]) - (op1_ptr[1 * 3 + 0] * op1_ptr[2 * 3 + 2]);
	float64_t p11 = (op1_ptr[0 * 3 + 0] * op1_ptr[2 * 3 + 2]) - (op1_ptr[0 * 3 + 2] * op1_ptr[2 * 3 + 0]);
	float64_t p12 = (op1_ptr[0 * 3 + 2] * op1_ptr[1 * 3 + 0]) - (op1_ptr[0 * 3 + 0] * op1_ptr[1 * 3 + 2]);
	float64_t p20 = (op1_ptr[1 * 3 + 0] * op1_ptr[2 * 3 + 1]) - (op1_ptr[1 * 3 + 1] * op1_ptr[2 * 3 + 0]);
	float64_t p21 = (op1_ptr[0 * 3 + 1] * op1_ptr[2 * 3 + 0]) - (op1_ptr[0 * 3 + 0] * op1_ptr[2 * 3 + 1]);
	float64_t p22 = (op1_ptr[0 * 3 + 0] * op1_ptr[1 * 3 + 1]) - (op1_ptr[0 * 3 + 1] * op1_ptr[1 * 3 + 0]);
	float64_t det = (op1_ptr[0 * 3 + 0] * p00) + (op1_ptr[0 * 3 + 1] * p10) + (op1_ptr[0 * 3 + 2] * p20);
	if(det != 0) {
		float64_t rdet = 1.0 / det;
		res_ptr[0 * 3 + 0] = p00 * rdet;
		res_ptr[0 * 3 + 1] = p01 * rdet;
		res_ptr[0 * 3 + 2] = p02 * rdet;
		res_ptr[1 * 3 + 0] = p10 * rdet;
		res_ptr[1 * 3 + 1] = p11 * rdet;
		res_ptr[1 * 3 + 2] = p12 * rdet;
		res_ptr[2 * 3 + 0] = p20 * rdet;
		res_ptr[2 * 3 + 1] = p21 * rdet;
		res_ptr[2 * 3 + 2] = p22 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 9; i++) {
			res_ptr[i] = (float64_t) NAN;
		}
	}
}

void qb_do_invert_matrix_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_3x_F32(op1_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_3x_F64(op1_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_4x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t p00 = (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]) + (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p01 = (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p02 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p03 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3]);
	float32_t p10 = (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p11 = (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p12 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float32_t p13 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3]);
	float32_t p20 = (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float32_t p21 = (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float32_t p22 = (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float32_t p23 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3]);
	float32_t p30 = (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float32_t p31 = (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float32_t p32 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float32_t p33 = (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2]);
	float32_t det = (op1_ptr[0 * 4 + 0] * p00) + (op1_ptr[0 * 4 + 1] * p10) + (op1_ptr[0 * 4 + 2] * p20) + (op1_ptr[0 * 4 + 3] * p30);
	if(det != 0) {
		float32_t rdet = 1.0f / det;
		res_ptr[0 * 4 + 0] = p00 * rdet;
		res_ptr[0 * 4 + 1] = p01 * rdet;
		res_ptr[0 * 4 + 2] = p02 * rdet;
		res_ptr[0 * 4 + 3] = p03 * rdet;
		res_ptr[1 * 4 + 0] = p10 * rdet;
		res_ptr[1 * 4 + 1] = p11 * rdet;
		res_ptr[1 * 4 + 2] = p12 * rdet;
		res_ptr[1 * 4 + 3] = p13 * rdet;
		res_ptr[2 * 4 + 0] = p20 * rdet;
		res_ptr[2 * 4 + 1] = p21 * rdet;
		res_ptr[2 * 4 + 2] = p22 * rdet;
		res_ptr[2 * 4 + 3] = p23 * rdet;
		res_ptr[3 * 4 + 0] = p30 * rdet;
		res_ptr[3 * 4 + 1] = p31 * rdet;
		res_ptr[3 * 4 + 2] = p32 * rdet;
		res_ptr[3 * 4 + 3] = p33 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 16; i++) {
			res_ptr[i] = (float32_t) NAN;
		}
	}
}

void qb_do_invert_matrix_4x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t p00 = (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]) + (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p01 = (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p02 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p03 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3]);
	float64_t p10 = (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p11 = (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p12 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 3]);
	float64_t p13 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 2]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 3]);
	float64_t p20 = (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float64_t p21 = (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 3] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float64_t p22 = (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 3]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 3]);
	float64_t p23 = (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 3] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 3] * op1_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 3]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 3]);
	float64_t p30 = (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float64_t p31 = (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 2] * op1_ptr[3 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[2 * 4 + 0] * op1_ptr[3 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[2 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float64_t p32 = (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[3 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[3 * 4 + 2]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[3 * 4 + 2]);
	float64_t p33 = (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 0]) - (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 2] * op1_ptr[2 * 4 + 1]) - (op1_ptr[0 * 4 + 1] * op1_ptr[1 * 4 + 0] * op1_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 0] * op1_ptr[1 * 4 + 1] * op1_ptr[2 * 4 + 2]);
	float64_t det = (op1_ptr[0 * 4 + 0] * p00) + (op1_ptr[0 * 4 + 1] * p10) + (op1_ptr[0 * 4 + 2] * p20) + (op1_ptr[0 * 4 + 3] * p30);
	if(det != 0) {
		float64_t rdet = 1.0 / det;
		res_ptr[0 * 4 + 0] = p00 * rdet;
		res_ptr[0 * 4 + 1] = p01 * rdet;
		res_ptr[0 * 4 + 2] = p02 * rdet;
		res_ptr[0 * 4 + 3] = p03 * rdet;
		res_ptr[1 * 4 + 0] = p10 * rdet;
		res_ptr[1 * 4 + 1] = p11 * rdet;
		res_ptr[1 * 4 + 2] = p12 * rdet;
		res_ptr[1 * 4 + 3] = p13 * rdet;
		res_ptr[2 * 4 + 0] = p20 * rdet;
		res_ptr[2 * 4 + 1] = p21 * rdet;
		res_ptr[2 * 4 + 2] = p22 * rdet;
		res_ptr[2 * 4 + 3] = p23 * rdet;
		res_ptr[3 * 4 + 0] = p30 * rdet;
		res_ptr[3 * 4 + 1] = p31 * rdet;
		res_ptr[3 * 4 + 2] = p32 * rdet;
		res_ptr[3 * 4 + 3] = p33 * rdet;
	} else {
		uint32_t i;
		for(i = 0; i < 16; i++) {
			res_ptr[i] = (float64_t) NAN;
		}
	}
}

void qb_do_invert_matrix_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap1)
	ALLOCA_FLAG(use_heap2)
	uint32_t i, j, k, m, n, p, q;
	uint32_t matrix_rows = op2, matrix_cols = op2;
	float32_t *__restrict minor = do_alloca((matrix_rows - 1) * (matrix_cols - 1) * sizeof(float32_t), use_heap1);
	float32_t *__restrict cofactors = do_alloca(matrix_rows * matrix_cols * sizeof(float32_t), use_heap2);
	float32_t a, sign_init = 1, sign, det = 0, rdet;
	for(m = 0, p = 0; m < matrix_rows; m++) {
		sign = sign_init;
		sign_init = -sign_init;
		for(n = 0; n < matrix_rows; n++) {
			float32_t minor_det;
			for(i = 0, k = 0, q = 0; i < matrix_rows; i++) {
				for(j = 0; j < matrix_rows; j++, k++) {
					if(j != m && i != n) {
						minor[q] = op1_ptr[k];
						q++;
					}
				}
			}
			qb_do_determinant_F32(minor, 0, matrix_rows - 1, &minor_det);
			cofactors[p] = minor_det * sign;
			p++;
			if(n == 0) {
				a = op1_ptr[m];
				det += a * minor_det * sign;
			}
			sign = -sign;
		}
	}
	if(det != 0) {
		rdet = 1 / det;
		for(p = 0; p < matrix_rows * matrix_cols; p++) {
			res_ptr[p] = cofactors[p] * rdet;
		}
	} else {
		for(p = 0; p < matrix_rows * matrix_cols; p++) {
			res_ptr[p] = (float32_t) NAN;
		}
	}
	free_alloca(minor, use_heap1);
	free_alloca(cofactors, use_heap2);
}

void qb_do_invert_matrix_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap1)
	ALLOCA_FLAG(use_heap2)
	uint32_t i, j, k, m, n, p, q;
	uint32_t matrix_rows = op2, matrix_cols = op2;
	float64_t *__restrict minor = do_alloca((matrix_rows - 1) * (matrix_cols - 1) * sizeof(float64_t), use_heap1);
	float64_t *__restrict cofactors = do_alloca(matrix_rows * matrix_cols * sizeof(float64_t), use_heap2);
	float64_t a, sign_init = 1, sign, det = 0, rdet;
	for(m = 0, p = 0; m < matrix_rows; m++) {
		sign = sign_init;
		sign_init = -sign_init;
		for(n = 0; n < matrix_rows; n++) {
			float64_t minor_det;
			for(i = 0, k = 0, q = 0; i < matrix_rows; i++) {
				for(j = 0; j < matrix_rows; j++, k++) {
					if(j != m && i != n) {
						minor[q] = op1_ptr[k];
						q++;
					}
				}
			}
			qb_do_determinant_F64(minor, 0, matrix_rows - 1, &minor_det);
			cofactors[p] = minor_det * sign;
			p++;
			if(n == 0) {
				a = op1_ptr[m];
				det += a * minor_det * sign;
			}
			sign = -sign;
		}
	}
	if(det != 0) {
		rdet = 1 / det;
		for(p = 0; p < matrix_rows * matrix_cols; p++) {
			res_ptr[p] = cofactors[p] * rdet;
		}
	} else {
		for(p = 0; p < matrix_rows * matrix_cols; p++) {
			res_ptr[p] = (float64_t) NAN;
		}
	}
	free_alloca(minor, use_heap1);
	free_alloca(cofactors, use_heap2);
}

void qb_do_invert_matrix_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_F32(op1_ptr, op1_count, op2, res_ptr, res_count);
			
			res_ptr += op2 * op2;
			op1_ptr += op2 * op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_invert_matrix_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_invert_matrix_F64(op1_ptr, op1_count, op2, res_ptr, res_count);
			
			res_ptr += op2 * op2;
			op1_ptr += op2 * op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_finite_F32(float32_t op1, int32_t *res_ptr) {
	(*res_ptr) = zend_finite(op1);
}

void qb_do_is_finite_F64(float64_t op1, int32_t *res_ptr) {
	(*res_ptr) = zend_finite(op1);
}

void qb_do_is_finite_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_finite_F32((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_finite_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_finite_F64((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_infinite_F32(float32_t op1, int32_t *res_ptr) {
	(*res_ptr) = (zend_isinf(op1) != 0);
}

void qb_do_is_infinite_F64(float64_t op1, int32_t *res_ptr) {
	(*res_ptr) = (zend_isinf(op1) != 0);
}

void qb_do_is_infinite_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_infinite_F32((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_infinite_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_infinite_F64((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_nan_F32(float32_t op1, int32_t *res_ptr) {
	(*res_ptr) = zend_isnan(op1);
}

void qb_do_is_nan_F64(float64_t op1, int32_t *res_ptr) {
	(*res_ptr) = zend_isnan(op1);
}

void qb_do_is_nan_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_nan_F32((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_is_nan_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_is_nan_F64((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_lcg_F32(qb_interpreter_context *__restrict cxt, float32_t *res_ptr) {
	USE_TSRM
	(*res_ptr) = (float32_t) php_combined_lcg(TSRMLS_C);
}

void qb_do_lcg_F64(qb_interpreter_context *__restrict cxt, float64_t *res_ptr) {
	USE_TSRM
	(*res_ptr) = (float64_t) php_combined_lcg(TSRMLS_C);
}

void qb_do_lcg_multiple_times_F32(qb_interpreter_context *__restrict cxt, float32_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_lcg_F32(cxt, &(*res_ptr));
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_lcg_multiple_times_F64(qb_interpreter_context *__restrict cxt, float64_t *res_ptr, uint32_t res_count) {
	if(res_count) {
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_lcg_F64(cxt, &(*res_ptr));
			
			res_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
		}
	}
}

void qb_do_length_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_2x_F32(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_2x_F64(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_3x_F32(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_3x_F64(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_4x_F32(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_4x_F64(op1_ptr, &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr) {
	uint32_t i, vector_width = op2;
	float32_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op1_ptr[i];
	}
	(*res_ptr) = qb_fast_sqrtf(sum);
}

void qb_do_length_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr) {
	uint32_t i, vector_width = op2;
	float64_t sum = 0;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op1_ptr[i];
	}
	(*res_ptr) = qb_fast_sqrt(sum);
}

void qb_do_length_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_F32(op1_ptr, op1_count, op2, &(*res_ptr));
			
			res_ptr += op2;
			op1_ptr += op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_length_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_length_F64(op1_ptr, op1_count, op2, &(*res_ptr));
			
			res_ptr += op2;
			op1_ptr += op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_less_than_equal_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F32(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F64(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S08(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S16(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S32(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S64(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U08(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U16(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U32(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_equal_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U64(op1_ptr, op1_count, op2_ptr, op2_count) != 1);
}

void qb_do_less_than_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F32(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F64(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S08(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S16(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S32(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S64(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U08(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U16(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U32(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_less_than_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_U64(op1_ptr, op1_count, op2_ptr, op2_count) == -1);
}

void qb_do_log10_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log10f((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log10_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log10((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log1p_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log1pf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log1p_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log1p((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log2_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log2f((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log2_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log2((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = logf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_log_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = log((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_max_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_max_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) > (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_min_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) < (*op2_ptr)) ? (*op1_ptr) : (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_mix_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (1 - (*op3_ptr)) + (*op2_ptr) * (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_mix_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (1 - (*op3_ptr)) + (*op2_ptr) * (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_modulo_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmodf(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmodf(op1_ptr[1], op2_ptr[1]);
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmod(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmod(op1_ptr[1], op2_ptr[1]);
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmodf(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmodf(op1_ptr[1], op2_ptr[1]);
				res_ptr[2] = fmodf(op1_ptr[2], op2_ptr[2]);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmod(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmod(op1_ptr[1], op2_ptr[1]);
				res_ptr[2] = fmod(op1_ptr[2], op2_ptr[2]);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmodf(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmodf(op1_ptr[1], op2_ptr[1]);
				res_ptr[2] = fmodf(op1_ptr[2], op2_ptr[2]);
				res_ptr[3] = fmodf(op1_ptr[3], op2_ptr[3]);
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = fmod(op1_ptr[0], op2_ptr[0]);
				res_ptr[1] = fmod(op1_ptr[1], op2_ptr[1]);
				res_ptr[2] = fmod(op1_ptr[2], op2_ptr[2]);
				res_ptr[3] = fmod(op1_ptr[3], op2_ptr[3]);
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = fmodf((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_modulo_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = fmod((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
				res_ptr[2] = op1_ptr[2] * op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
				res_ptr[2] = op1_ptr[2] * op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
				res_ptr[2] = op1_ptr[2] * op2_ptr[2];
				res_ptr[3] = op1_ptr[3] * op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] * op2_ptr[0];
				res_ptr[1] = op1_ptr[1] * op2_ptr[1];
				res_ptr[2] = op1_ptr[2] * op2_ptr[2];
				res_ptr[3] = op1_ptr[3] * op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			op3_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			op3_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
				res_ptr[2] = (op1_ptr[2] * op2_ptr[2]) + op3_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			op3_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
				res_ptr[2] = (op1_ptr[2] * op2_ptr[2]) + op3_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			op3_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
				res_ptr[2] = (op1_ptr[2] * op2_ptr[2]) + op3_ptr[2];
				res_ptr[3] = (op1_ptr[3] * op2_ptr[3]) + op3_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			op3_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = (op1_ptr[0] * op2_ptr[0]) + op3_ptr[0];
				res_ptr[1] = (op1_ptr[1] * op2_ptr[1]) + op3_ptr[1];
				res_ptr[2] = (op1_ptr[2] * op2_ptr[2]) + op3_ptr[2];
				res_ptr[3] = (op1_ptr[3] * op2_ptr[3]) + op3_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			op3_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *op3_ptr, uint32_t op3_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *op3_ptr, uint32_t op3_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *op3_ptr, uint32_t op3_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_accumulate_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *op3_ptr, uint32_t op3_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = ((*op1_ptr) * (*op2_ptr)) + (*op3_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_2x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_2x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_3x_column_major_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t dot_product0 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float32_t dot_product1 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float32_t dot_product2 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	float32_t dot_product3 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float32_t dot_product4 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float32_t dot_product5 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	float32_t dot_product6 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float32_t dot_product7 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float32_t dot_product8 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	res_ptr[0 * 3 + 0] = dot_product0;
	res_ptr[0 * 3 + 1] = dot_product1;
	res_ptr[0 * 3 + 2] = dot_product2;
	res_ptr[1 * 3 + 0] = dot_product3;
	res_ptr[1 * 3 + 1] = dot_product4;
	res_ptr[1 * 3 + 2] = dot_product5;
	res_ptr[2 * 3 + 0] = dot_product6;
	res_ptr[2 * 3 + 1] = dot_product7;
	res_ptr[2 * 3 + 2] = dot_product8;
}

void qb_do_multiply_matrix_by_matrix_3x_column_major_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t dot_product0 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float64_t dot_product1 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float64_t dot_product2 = (op1_ptr[0 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[0 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[0 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	float64_t dot_product3 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float64_t dot_product4 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float64_t dot_product5 = (op1_ptr[1 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[1 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[1 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	float64_t dot_product6 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 0]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 0]);
	float64_t dot_product7 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 1]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 1]);
	float64_t dot_product8 = (op1_ptr[2 * 3 + 0] * op2_ptr[0 * 3 + 2]) + (op1_ptr[2 * 3 + 1] * op2_ptr[1 * 3 + 2]) + (op1_ptr[2 * 3 + 2] * op2_ptr[2 * 3 + 2]);
	res_ptr[0 * 3 + 0] = dot_product0;
	res_ptr[0 * 3 + 1] = dot_product1;
	res_ptr[0 * 3 + 2] = dot_product2;
	res_ptr[1 * 3 + 0] = dot_product3;
	res_ptr[1 * 3 + 1] = dot_product4;
	res_ptr[1 * 3 + 2] = dot_product5;
	res_ptr[2 * 3 + 0] = dot_product6;
	res_ptr[2 * 3 + 1] = dot_product7;
	res_ptr[2 * 3 + 2] = dot_product8;
}

void qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_3x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			op2_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_3x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			op2_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_4x_column_major_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t dot_product0 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float32_t dot_product1 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float32_t dot_product2 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float32_t dot_product3 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float32_t dot_product4 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float32_t dot_product5 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float32_t dot_product6 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float32_t dot_product7 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float32_t dot_product8 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float32_t dot_product9 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float32_t dot_product10 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float32_t dot_product11 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float32_t dot_product12 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float32_t dot_product13 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float32_t dot_product14 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float32_t dot_product15 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	res_ptr[0 * 4 + 0] = dot_product0;
	res_ptr[0 * 4 + 1] = dot_product1;
	res_ptr[0 * 4 + 2] = dot_product2;
	res_ptr[0 * 4 + 3] = dot_product3;
	res_ptr[1 * 4 + 0] = dot_product4;
	res_ptr[1 * 4 + 1] = dot_product5;
	res_ptr[1 * 4 + 2] = dot_product6;
	res_ptr[1 * 4 + 3] = dot_product7;
	res_ptr[2 * 4 + 0] = dot_product8;
	res_ptr[2 * 4 + 1] = dot_product9;
	res_ptr[2 * 4 + 2] = dot_product10;
	res_ptr[2 * 4 + 3] = dot_product11;
	res_ptr[3 * 4 + 0] = dot_product12;
	res_ptr[3 * 4 + 1] = dot_product13;
	res_ptr[3 * 4 + 2] = dot_product14;
	res_ptr[3 * 4 + 3] = dot_product15;
}

void qb_do_multiply_matrix_by_matrix_4x_column_major_F64(float64_t *op1_ptr, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t dot_product0 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float64_t dot_product1 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float64_t dot_product2 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float64_t dot_product3 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[0 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float64_t dot_product4 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float64_t dot_product5 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float64_t dot_product6 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float64_t dot_product7 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[1 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float64_t dot_product8 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float64_t dot_product9 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float64_t dot_product10 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float64_t dot_product11 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[2 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	float64_t dot_product12 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 0]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 0]);
	float64_t dot_product13 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 1]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 1]);
	float64_t dot_product14 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 2]);
	float64_t dot_product15 = (op1_ptr[3 * 4 + 0] * op2_ptr[0 * 4 + 3]) + (op1_ptr[3 * 4 + 1] * op2_ptr[1 * 4 + 3]) + (op1_ptr[3 * 4 + 2] * op2_ptr[2 * 4 + 3]) + (op1_ptr[3 * 4 + 3] * op2_ptr[3 * 4 + 3]);
	res_ptr[0 * 4 + 0] = dot_product0;
	res_ptr[0 * 4 + 1] = dot_product1;
	res_ptr[0 * 4 + 2] = dot_product2;
	res_ptr[0 * 4 + 3] = dot_product3;
	res_ptr[1 * 4 + 0] = dot_product4;
	res_ptr[1 * 4 + 1] = dot_product5;
	res_ptr[1 * 4 + 2] = dot_product6;
	res_ptr[1 * 4 + 3] = dot_product7;
	res_ptr[2 * 4 + 0] = dot_product8;
	res_ptr[2 * 4 + 1] = dot_product9;
	res_ptr[2 * 4 + 2] = dot_product10;
	res_ptr[2 * 4 + 3] = dot_product11;
	res_ptr[3 * 4 + 0] = dot_product12;
	res_ptr[3 * 4 + 1] = dot_product13;
	res_ptr[3 * 4 + 2] = dot_product14;
	res_ptr[3 * 4 + 3] = dot_product15;
}

void qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_4x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			op2_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_4x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			op2_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, uint32_t op5, float32_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k, p, q, res_index = 0;
	uint32_t matrix1_rows = op3, matrix1_cols = op4, matrix2_cols = op5;
	float32_t *__restrict buffer = do_alloca(matrix1_rows * matrix2_cols * sizeof(float32_t), use_heap);
	for(i = 0, q = 0; i < matrix2_cols; ++i) {
		for(j = 0; j < matrix1_rows; ++j) {
			float32_t dot_product = 0;
			for(p = 0, k = 0; p < matrix1_cols; ++p, k += matrix1_rows) {
				dot_product += op1_ptr[k + j] * op2_ptr[p + q];
			}
			buffer[res_index++] = dot_product;
		}
		q += matrix1_cols;
	}
	memcpy(res_ptr, buffer, matrix1_rows * matrix2_cols * sizeof(float32_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_matrix_by_matrix_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, uint32_t op5, float64_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k, p, q, res_index = 0;
	uint32_t matrix1_rows = op3, matrix1_cols = op4, matrix2_cols = op5;
	float64_t *__restrict buffer = do_alloca(matrix1_rows * matrix2_cols * sizeof(float64_t), use_heap);
	for(i = 0, q = 0; i < matrix2_cols; ++i) {
		for(j = 0; j < matrix1_rows; ++j) {
			float64_t dot_product = 0;
			for(p = 0, k = 0; p < matrix1_cols; ++p, k += matrix1_rows) {
				dot_product += op1_ptr[k + j] * op2_ptr[p + q];
			}
			buffer[res_index++] = dot_product;
		}
		q += matrix1_cols;
	}
	memcpy(res_ptr, buffer, matrix1_rows * matrix2_cols * sizeof(float64_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, uint32_t op5, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, op5, res_ptr, res_count);
			
			res_ptr += (op3 * op5);
			op1_ptr += (op3 * op4);
			op2_ptr += (op4 * op5);
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, uint32_t op5, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_matrix_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, op5, res_ptr, res_count);
			
			res_ptr += (op3 * op5);
			op1_ptr += (op3 * op4);
			op2_ptr += (op4 * op5);
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_matrix_padded_3x_F32(float32_t *op1_ptr, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t dot_product0 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 0]);
	float32_t dot_product1 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 1]);
	float32_t dot_product2 = (op1_ptr[0 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[0 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[0 * 4 + 2] * op2_ptr[2 * 4 + 2]);
	float32_t dot_product3 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 0]);
	float32_t dot_product4 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 1]);
	float32_t dot_product5 = (op1_ptr[1 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[1 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[1 * 4 + 2] * op2_ptr[2 * 4 + 2]);
	float32_t dot_product6 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 0]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 0]);
	float32_t dot_product7 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 1]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 1]);
	float32_t dot_product8 = (op1_ptr[2 * 4 + 0] * op2_ptr[0 * 4 + 2]) + (op1_ptr[2 * 4 + 1] * op2_ptr[1 * 4 + 2]) + (op1_ptr[2 * 4 + 2] * op2_ptr[2 * 4 + 2]);
	res_ptr[0 * 4 + 0] = dot_product0;
	res_ptr[0 * 4 + 1] = dot_product1;
	res_ptr[0 * 4 + 2] = dot_product2;
	res_ptr[1 * 4 + 0] = dot_product3;
	res_ptr[1 * 4 + 1] = dot_product4;
	res_ptr[1 * 4 + 2] = dot_product5;
	res_ptr[2 * 4 + 0] = dot_product6;
	res_ptr[2 * 4 + 1] = dot_product7;
	res_ptr[2 * 4 + 2] = dot_product8;
}

void qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_2x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 4;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_2x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 4;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_3x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 9;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_3x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 9;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_4x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 16;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_4x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 16;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k;
	uint32_t matrix1_rows = op3, matrix1_cols = op4;
	float32_t *buffer = do_alloca(matrix1_rows * sizeof(float32_t), use_heap);
	for(i = 0; i < matrix1_rows; ++i) {
		float32_t dot_product = 0;
		for(j = 0, k = i; j < matrix1_cols; ++j, k += matrix1_cols) {
			dot_product += op1_ptr[k] * op2_ptr[j];
		}
		buffer[i] = dot_product;
	}
	memcpy(res_ptr, buffer, matrix1_rows * sizeof(float32_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_matrix_by_vector_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k;
	uint32_t matrix1_rows = op3, matrix1_cols = op4;
	float64_t *buffer = do_alloca(matrix1_rows * sizeof(float64_t), use_heap);
	for(i = 0; i < matrix1_rows; ++i) {
		float64_t dot_product = 0;
		for(j = 0, k = i; j < matrix1_cols; ++j, k += matrix1_cols) {
			dot_product += op1_ptr[k] * op2_ptr[j];
		}
		buffer[i] = dot_product;
	}
	memcpy(res_ptr, buffer, matrix1_rows * sizeof(float64_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_matrix_by_vector_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op4;
			op1_ptr += (op3 * op4);
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_matrix_by_vector_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_matrix_by_vector_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op4;
			op1_ptr += (op3 * op4);
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_2x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_2x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_3x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_3x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_4x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_4x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k;
	uint32_t matrix_rows = op3, matrix_cols = op4;
	float32_t *buffer = do_alloca(matrix_rows * sizeof(float32_t), use_heap);
	for(i = 0, k = 0; i < matrix_cols; ++i) {
		float32_t dot_product = 0;
		for(j = 0; j < matrix_rows; ++j, ++k) {
			dot_product += op1_ptr[j] * op2_ptr[k];
		}
		buffer[i] = dot_product;
	}
	memcpy(res_ptr, buffer, matrix_cols * sizeof(float32_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_vector_by_matrix_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k;
	uint32_t matrix_rows = op3, matrix_cols = op4;
	float64_t *buffer = do_alloca(matrix_rows * sizeof(float64_t), use_heap);
	for(i = 0, k = 0; i < matrix_cols; ++i) {
		float64_t dot_product = 0;
		for(j = 0; j < matrix_rows; ++j, ++k) {
			dot_product += op1_ptr[j] * op2_ptr[k];
		}
		buffer[i] = dot_product;
	}
	memcpy(res_ptr, buffer, matrix_cols * sizeof(float64_t));
	free_alloca(buffer, use_heap);
}

void qb_do_multiply_vector_by_matrix_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op4;
			op2_ptr += (op3 * op4);
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_multiply_vector_by_matrix_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_multiply_vector_by_matrix_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op4;
			op2_ptr += (op3 * op4);
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_negate_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
				res_ptr[2] = - op1_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
				res_ptr[2] = - op1_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
				res_ptr[2] = - op1_ptr[2];
				res_ptr[3] = - op1_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = - op1_ptr[0];
				res_ptr[1] = - op1_ptr[1];
				res_ptr[2] = - op1_ptr[2];
				res_ptr[3] = - op1_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_negate_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = - (*op1_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_3x_F32(op1_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_3x_F64(op1_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op2;
	float32_t sum = 0, r;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op1_ptr[i];
	}
	if(sum) {
		r = qb_fast_rsqrtf(sum);
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op1_ptr[i] * r;
		}
	}
}

void qb_do_normalize_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op2;
	float64_t sum = 0, r;
	for(i = 0; i < vector_width; i++) {
		sum += op1_ptr[i] * op1_ptr[i];
	}
	if(sum) {
		r = qb_fast_rsqrt(sum);
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op1_ptr[i] * r;
		}
	}
}

void qb_do_normalize_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_F32(op1_ptr, op1_count, op2, res_ptr, res_count);
			
			res_ptr += op2;
			op1_ptr += op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_normalize_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_normalize_F64(op1_ptr, op1_count, op2, res_ptr, res_count);
			
			res_ptr += op2;
			op1_ptr += op2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_not_equal_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F32(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_not_equal_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_F64(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_not_equal_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S08(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_not_equal_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S16(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_not_equal_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S32(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_not_equal_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr) {
	(*res_ptr) = (qb_compare_array_S64(op1_ptr, op1_count, op2_ptr, op2_count) != 0);
}

void qb_do_pow_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = powf((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_pow_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = pow((*op1_ptr), (*op2_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_predicate_clear_array_F32(int32_t op1, float32_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_array_F64(int32_t op1, float64_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_array_I08(int32_t op1, int8_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_array_I16(int32_t op1, int16_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_array_I32(int32_t op1, int32_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_array_I64(int32_t op1, int64_t *res_ptr, uint32_t res_count) {
	if(op1) {
		uint32_t i;
		for(i = 0; i < res_count; i++) {
			res_ptr[i] = 0;
		}
	}
}

void qb_do_predicate_clear_element_F32(uint32_t op1, uint32_t op2, int32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_predicate_clear_element_F64(uint32_t op1, uint32_t op2, int32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_predicate_clear_element_I08(uint32_t op1, uint32_t op2, int32_t op3, int8_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_predicate_clear_element_I16(uint32_t op1, uint32_t op2, int32_t op3, int16_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_predicate_clear_element_I32(uint32_t op1, uint32_t op2, int32_t op3, int32_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_predicate_clear_element_I64(uint32_t op1, uint32_t op2, int32_t op3, int64_t *res_ptr, uint32_t res_count) {
	if(op3) {
		uint32_t i, shift = op2, start = op1 * op2, end = res_count - shift;
		if(start <= end) {
			for(i = start; i < end; i++) {
				res_ptr[i] = res_ptr[i + shift];
			}
			for(i = end; i < res_count; i++) {
				res_ptr[i] = 0;
			}
		}
	}
}

void qb_do_print_multidimensional_variable_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	float32_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	float64_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	int8_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	int16_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	int32_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	int64_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	uint8_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	uint16_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	uint32_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_multidimensional_variable_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count) {
	USE_TSRM
	uint64_t *op1_end = op1_ptr + op1_count;
	uint32_t depth = 0, i;
	uint32_t counts[MAX_DIMENSION];
	for(i = 0; i < op2_count; i++) {
		counts[i] = 0;
	}
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end || depth > 0) {
		if(counts[depth] < op2_ptr[depth]) {
			if(counts[depth] > 0) {
				php_write(", ", 2 TSRMLS_CC);
			}
			if(depth + 1 == op2_count) {
				char sprintf_buffer[64];
				uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
				php_write(sprintf_buffer, len TSRMLS_CC);
				op1_ptr++;
				counts[depth]++;
			} else {
				php_write("[", 1 TSRMLS_CC);
				depth++;
			}
		} else {
			php_write("]", 1 TSRMLS_CC);
			counts[depth] = 0;
			depth--;
			counts[depth]++;
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_string_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	php_write(op1_ptr, op1_count TSRMLS_CC);
}

void qb_do_print_variable_F32(qb_interpreter_context *__restrict cxt, float32_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_F64(qb_interpreter_context *__restrict cxt, float64_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_S08(qb_interpreter_context *__restrict cxt, int8_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_S16(qb_interpreter_context *__restrict cxt, int16_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_S32(qb_interpreter_context *__restrict cxt, int32_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_S64(qb_interpreter_context *__restrict cxt, int64_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_U08(qb_interpreter_context *__restrict cxt, uint8_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_U16(qb_interpreter_context *__restrict cxt, uint16_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_U32(qb_interpreter_context *__restrict cxt, uint32_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_U64(qb_interpreter_context *__restrict cxt, uint64_t op1) {
	USE_TSRM
	char sprintf_buffer[64];
	uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, op1);
	php_write(sprintf_buffer, len TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_F32(qb_interpreter_context *__restrict cxt, float32_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	float32_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision / 2, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_F64(qb_interpreter_context *__restrict cxt, float64_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	float64_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%.*G", cxt->floating_point_precision, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	int8_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId8, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	int16_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId16, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	int32_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId32, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	int64_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRId64, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	uint8_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu8, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	uint16_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu16, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	uint32_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu32, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_print_variable_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count) {
	USE_TSRM
	uint64_t *op1_end = op1_ptr + op1_count;
	php_write("[", 1 TSRMLS_CC);
	while(op1_ptr < op1_end) {
		char sprintf_buffer[64];
		uint32_t len = snprintf(sprintf_buffer, sizeof(sprintf_buffer), "%" PRIu64, *op1_ptr);
		php_write(sprintf_buffer, len TSRMLS_CC);
		op1_ptr++;
		if(op1_ptr != op1_end) {
			php_write(", ", 2 TSRMLS_CC);
		}
	}
	php_write("]", 1 TSRMLS_CC);
}

void qb_do_radian_to_degree_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * ((float32_t) (180 / M_PI));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_radian_to_degree_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) * ((float64_t) (180 / M_PI));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_random_S08(qb_interpreter_context *__restrict cxt, int8_t op1, int8_t op2, int8_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (int8_t) number_l;
}

void qb_do_random_S16(qb_interpreter_context *__restrict cxt, int16_t op1, int16_t op2, int16_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (int16_t) number_l;
}

void qb_do_random_S32(qb_interpreter_context *__restrict cxt, int32_t op1, int32_t op2, int32_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (int32_t) number_l;
}

void qb_do_random_S64(qb_interpreter_context *__restrict cxt, int64_t op1, int64_t op2, int64_t *res_ptr) {
	USE_TSRM
	int32_t number_h = php_rand(TSRMLS_C), upper_limit_h = op2 >> 32, lower_limit_h = op1 >> 32;
	uint32_t number_l = php_rand(TSRMLS_C), upper_limit_l = 0xFFFFFFFF, lower_limit_l = 0;
	number_h = lower_limit_h + (int32_t) ((double) ( (double) upper_limit_h - lower_limit_h + 1.0) * (number_h / (PHP_RAND_MAX + 1.0)));
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (uint64_t) number_h << 32 | number_l;
}

void qb_do_random_U08(qb_interpreter_context *__restrict cxt, uint8_t op1, uint8_t op2, uint8_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (uint8_t) number_l;
}

void qb_do_random_U16(qb_interpreter_context *__restrict cxt, uint16_t op1, uint16_t op2, uint16_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (uint16_t) number_l;
}

void qb_do_random_U32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_rand(TSRMLS_C), upper_limit_l = op2, lower_limit_l = op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (uint32_t) number_l;
}

void qb_do_random_U64(qb_interpreter_context *__restrict cxt, uint64_t op1, uint64_t op2, uint64_t *res_ptr) {
	USE_TSRM
	uint32_t number_h = php_rand(TSRMLS_C), upper_limit_h = op2 >> 32, lower_limit_h = op1 >> 32;
	uint32_t number_l = php_rand(TSRMLS_C), upper_limit_l = 0xFFFFFFFF, lower_limit_l = 0;
	number_h = lower_limit_h + (uint32_t) ((double) ( (double) upper_limit_h - lower_limit_h + 1.0) * (number_h / (PHP_RAND_MAX + 1.0)));
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_RAND_MAX + 1.0)));
	(*res_ptr) = (uint64_t) number_h << 32 | number_l;
}

void qb_do_random_mt_S08(qb_interpreter_context *__restrict cxt, int8_t op1, int8_t op2, int8_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (int32_t) op2, lower_limit_l = (int32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (int8_t) number_l;
}

void qb_do_random_mt_S16(qb_interpreter_context *__restrict cxt, int16_t op1, int16_t op2, int16_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (int32_t) op2, lower_limit_l = (int32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (int16_t) number_l;
}

void qb_do_random_mt_S32(qb_interpreter_context *__restrict cxt, int32_t op1, int32_t op2, int32_t *res_ptr) {
	USE_TSRM
	int32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (int32_t) op2, lower_limit_l = (int32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (int32_t) number_l;
}

void qb_do_random_mt_S64(qb_interpreter_context *__restrict cxt, int64_t op1, int64_t op2, int64_t *res_ptr) {
	USE_TSRM
	int32_t number_h = php_mt_rand(TSRMLS_C) >> 1, upper_limit_h = op2 >> 32, lower_limit_h = op1 >> 32;
	uint32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = 0xFFFFFFFF, lower_limit_l = 0;
	number_h = lower_limit_h + (int32_t) ((double) ( (double) upper_limit_h - lower_limit_h + 1.0) * (number_h / (PHP_MT_RAND_MAX + 1.0)));
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (uint64_t) number_h << 32 | number_l;
}

void qb_do_random_mt_U08(qb_interpreter_context *__restrict cxt, uint8_t op1, uint8_t op2, uint8_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (uint32_t) op2, lower_limit_l = (uint32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (uint8_t) number_l;
}

void qb_do_random_mt_U16(qb_interpreter_context *__restrict cxt, uint16_t op1, uint16_t op2, uint16_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (uint32_t) op2, lower_limit_l = (uint32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (uint16_t) number_l;
}

void qb_do_random_mt_U32(qb_interpreter_context *__restrict cxt, uint32_t op1, uint32_t op2, uint32_t *res_ptr) {
	USE_TSRM
	uint32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = (uint32_t) op2, lower_limit_l = (uint32_t) op1;
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (uint32_t) number_l;
}

void qb_do_random_mt_U64(qb_interpreter_context *__restrict cxt, uint64_t op1, uint64_t op2, uint64_t *res_ptr) {
	USE_TSRM
	uint32_t number_h = php_mt_rand(TSRMLS_C) >> 1, upper_limit_h = op2 >> 32, lower_limit_h = op1 >> 32;
	uint32_t number_l = php_mt_rand(TSRMLS_C) >> 1, upper_limit_l = 0xFFFFFFFF, lower_limit_l = 0;
	number_h = lower_limit_h + (uint32_t) ((double) ( (double) upper_limit_h - lower_limit_h + 1.0) * (number_h / (PHP_MT_RAND_MAX + 1.0)));
	number_l = lower_limit_l + (uint32_t) ((double) ( (double) upper_limit_l - lower_limit_l + 1.0) * (number_l / (PHP_MT_RAND_MAX + 1.0)));
	(*res_ptr) = (uint64_t) number_h << 32 | number_l;
}

void qb_do_random_mt_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_S08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_S16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_S32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_S64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_U08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_U16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_U32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_mt_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_mt_U64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_S08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_S16(qb_interpreter_context *__restrict cxt, int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_S16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_S32(qb_interpreter_context *__restrict cxt, int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_S32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_S64(qb_interpreter_context *__restrict cxt, int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_S64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_U08(qb_interpreter_context *__restrict cxt, uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_U08(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_U16(qb_interpreter_context *__restrict cxt, uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_U16(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_U32(qb_interpreter_context *__restrict cxt, uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_U32(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_random_multiple_times_U64(qb_interpreter_context *__restrict cxt, uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_random_U64(cxt, (*op1_ptr), (*op2_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_range_F32(float32_t op1, float32_t op2, float32_t op3, float32_t *res_ptr, uint32_t res_count) {
	float32_t *res_end = res_ptr + res_count;
	float32_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_F64(float64_t op1, float64_t op2, float64_t op3, float64_t *res_ptr, uint32_t res_count) {
	float64_t *res_end = res_ptr + res_count;
	float64_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_S08(int8_t op1, int8_t op2, int8_t op3, int8_t *res_ptr, uint32_t res_count) {
	int8_t *res_end = res_ptr + res_count;
	int8_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_S16(int16_t op1, int16_t op2, int16_t op3, int16_t *res_ptr, uint32_t res_count) {
	int16_t *res_end = res_ptr + res_count;
	int16_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_S32(int32_t op1, int32_t op2, int32_t op3, int32_t *res_ptr, uint32_t res_count) {
	int32_t *res_end = res_ptr + res_count;
	int32_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_S64(int64_t op1, int64_t op2, int64_t op3, int64_t *res_ptr, uint32_t res_count) {
	int64_t *res_end = res_ptr + res_count;
	int64_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_U08(uint8_t op1, uint8_t op2, int8_t op3, uint8_t *res_ptr, uint32_t res_count) {
	uint8_t *res_end = res_ptr + res_count;
	uint8_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_U16(uint16_t op1, uint16_t op2, int16_t op3, uint16_t *res_ptr, uint32_t res_count) {
	uint16_t *res_end = res_ptr + res_count;
	uint16_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_U32(uint32_t op1, uint32_t op2, int32_t op3, uint32_t *res_ptr, uint32_t res_count) {
	uint32_t *res_end = res_ptr + res_count;
	uint32_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_range_U64(uint64_t op1, uint64_t op2, int64_t op3, uint64_t *res_ptr, uint32_t res_count) {
	uint64_t *res_end = res_ptr + res_count;
	uint64_t num = op1;
	while(res_ptr < res_end) {
		*res_ptr = num;
		res_ptr++;
		num += op3;
	}
}

void qb_do_reflect_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_2x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_2x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_3x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_3x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_4x_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_4x_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op3;
	float32_t dot_product;
	qb_do_dot_product_F32(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	for(i = 0; i < vector_width; i++) {
		res_ptr[i] = (float32_t) (op1_ptr[i] - 2.0 * dot_product * op2_ptr[i]);
	}
}

void qb_do_reflect_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op3;
	float64_t dot_product;
	qb_do_dot_product_F64(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	for(i = 0; i < vector_width; i++) {
		res_ptr[i] = (float64_t) (op1_ptr[i] - 2.0 * dot_product * op2_ptr[i]);
	}
}

void qb_do_reflect_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_reflect_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_reflect_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, res_ptr, res_count);
			
			res_ptr += op3;
			op1_ptr += op3;
			op2_ptr += op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_2x_F32(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_2x_F64(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_3x_F32(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_3x_F64(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_4x_F32(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_4x_F64(op1_ptr, op2_ptr, op3, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op4;
	float32_t dot_product, k;
	qb_do_dot_product_F32(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	k = (float32_t) (1.0 - (op3 * op3) * (1.0 - dot_product * dot_product));
	if(k < 0.0) {
		for(i = 0; i < vector_width; i++) {
			res_ptr[0] = 0.0;
		}
	} else {
		float32_t m = op3 * dot_product + qb_fast_sqrtf(k);
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op3 * op1_ptr[i] - m * op2_ptr[i];
		}
	}
}

void qb_do_refract_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	uint32_t i, vector_width = op4;
	float64_t dot_product, k;
	qb_do_dot_product_F64(op1_ptr, op1_count, op2_ptr, op2_count, vector_width, &dot_product);
	k = (float64_t) (1.0 - (op3 * op3) * (1.0 - dot_product * dot_product));
	if(k < 0.0) {
		for(i = 0; i < vector_width; i++) {
			res_ptr[0] = 0.0;
		}
	} else {
		float64_t m = op3 * dot_product + qb_fast_sqrt(k);
		for(i = 0; i < vector_width; i++) {
			res_ptr[i] = op3 * op1_ptr[i] - m * op2_ptr[i];
		}
	}
}

void qb_do_refract_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op4;
			op1_ptr += op4;
			op2_ptr += op4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_refract_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, uint32_t op3, uint32_t op4, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_refract_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
			
			res_ptr += op4;
			op1_ptr += op4;
			op2_ptr += op4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_remove_premultiplication_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_remove_premultiplication_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_remove_premultiplication_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_remove_premultiplication_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_reverse_sort_F32(uint32_t op1, float32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(float32_t) * 1, (void *) qb_compare_descending_F32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(float32_t) * op1, (void *) qb_compare_descending_F32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(float32_t) * op1, (void *) qb_compare_descending_F32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(float32_t) * op1, &op1, (void *) qb_compare_descending_F32_array);
#endif
	}
}

void qb_do_reverse_sort_F64(uint32_t op1, float64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(float64_t) * 1, (void *) qb_compare_descending_F64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(float64_t) * op1, (void *) qb_compare_descending_F64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(float64_t) * op1, (void *) qb_compare_descending_F64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(float64_t) * op1, &op1, (void *) qb_compare_descending_F64_array);
#endif
	}
}

void qb_do_reverse_sort_S08(uint32_t op1, int8_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int8_t) * 1, (void *) qb_compare_descending_S08);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int8_t) * op1, (void *) qb_compare_descending_S08_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int8_t) * op1, (void *) qb_compare_descending_S08_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int8_t) * op1, &op1, (void *) qb_compare_descending_S08_array);
#endif
	}
}

void qb_do_reverse_sort_S16(uint32_t op1, int16_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int16_t) * 1, (void *) qb_compare_descending_S16);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int16_t) * op1, (void *) qb_compare_descending_S16_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int16_t) * op1, (void *) qb_compare_descending_S16_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int16_t) * op1, &op1, (void *) qb_compare_descending_S16_array);
#endif
	}
}

void qb_do_reverse_sort_S32(uint32_t op1, int32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int32_t) * 1, (void *) qb_compare_descending_S32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int32_t) * op1, (void *) qb_compare_descending_S32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int32_t) * op1, (void *) qb_compare_descending_S32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int32_t) * op1, &op1, (void *) qb_compare_descending_S32_array);
#endif
	}
}

void qb_do_reverse_sort_S64(uint32_t op1, int64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int64_t) * 1, (void *) qb_compare_descending_S64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int64_t) * op1, (void *) qb_compare_descending_S64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int64_t) * op1, (void *) qb_compare_descending_S64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int64_t) * op1, &op1, (void *) qb_compare_descending_S64_array);
#endif
	}
}

void qb_do_reverse_sort_U08(uint32_t op1, uint8_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint8_t) * 1, (void *) qb_compare_descending_U08);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint8_t) * op1, (void *) qb_compare_descending_U08_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint8_t) * op1, (void *) qb_compare_descending_U08_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint8_t) * op1, &op1, (void *) qb_compare_descending_U08_array);
#endif
	}
}

void qb_do_reverse_sort_U16(uint32_t op1, uint16_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint16_t) * 1, (void *) qb_compare_descending_U16);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint16_t) * op1, (void *) qb_compare_descending_U16_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint16_t) * op1, (void *) qb_compare_descending_U16_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint16_t) * op1, &op1, (void *) qb_compare_descending_U16_array);
#endif
	}
}

void qb_do_reverse_sort_U32(uint32_t op1, uint32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint32_t) * 1, (void *) qb_compare_descending_U32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint32_t) * op1, (void *) qb_compare_descending_U32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint32_t) * op1, (void *) qb_compare_descending_U32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint32_t) * op1, &op1, (void *) qb_compare_descending_U32_array);
#endif
	}
}

void qb_do_reverse_sort_U64(uint32_t op1, uint64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint64_t) * 1, (void *) qb_compare_descending_U64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint64_t) * op1, (void *) qb_compare_descending_U64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint64_t) * op1, (void *) qb_compare_descending_U64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint64_t) * op1, &op1, (void *) qb_compare_descending_U64_array);
#endif
	}
}

void qb_do_rgb2hsl_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_rgb_to_hsl_F32(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsl_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_rgb_to_hsl_F64(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsl_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_rgb2hsl_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsl_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_rgb2hsl_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsv_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_rgb_to_hsv_F32(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsv_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				qb_convert_rgb_to_hsv_F64(op1_ptr, res_ptr);
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsv_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_rgb2hsv_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rgb2hsv_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_rgb2hsv_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_round_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) _php_math_round((*op1_ptr), (*op2_ptr), (*op3_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_round_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) _php_math_round((*op1_ptr), (*op2_ptr), (*op3_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_rsqrt_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = qb_fast_rsqrtf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_rsqrt_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = qb_fast_rsqrt((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sample_bilinear_2x_F32(float32_t *op1_ptr, uint32_t op2, uint32_t op3, float32_t op4, float32_t op5, float32_t *res_ptr) {
	int32_t ix = (int32_t) floorf(op4 - 0.5f);
	int32_t iy = (int32_t) floorf(op5 - 0.5f);
	float32_t fx = (op4 - 0.5f) - floorf(op4 - 0.5f);
	float32_t fy = (op5 - 0.5f) - floorf(op5 - 0.5f);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 2;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
		}
	} else { 
		float32_t fx1 = 1.0f - fx;
		float32_t fy1 = 1.0f - fy;
		float32_t w00 = fx1 * fy1;
		float32_t w10 = fx * fy1;
		float32_t w01 = fx1 * fy;
		float32_t w11 = fx * fy;
		float32_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 2;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
		} else {
			p00[0] = 0;
			p00[1] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 2;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
		} else {
			p10[0] = 0;
			p10[1] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 2;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
		} else {
			p01[0] = 0;
			p01[1] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 2;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
		} else {
			p11[0] = 0;
			p11[1] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
	}
}

void qb_do_sample_bilinear_2x_F64(float64_t *op1_ptr, uint32_t op2, uint32_t op3, float64_t op4, float64_t op5, float64_t *res_ptr) {
	int32_t ix = (int32_t) floor(op4 - 0.5);
	int32_t iy = (int32_t) floor(op5 - 0.5);
	float64_t fx = (op4 - 0.5) - floor(op4 - 0.5);
	float64_t fy = (op5 - 0.5) - floor(op5 - 0.5);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 2;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
		}
	} else { 
		float64_t fx1 = 1.0 - fx;
		float64_t fy1 = 1.0 - fy;
		float64_t w00 = fx1 * fy1;
		float64_t w10 = fx * fy1;
		float64_t w01 = fx1 * fy;
		float64_t w11 = fx * fy;
		float64_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 2;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
		} else {
			p00[0] = 0;
			p00[1] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 2;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
		} else {
			p10[0] = 0;
			p10[1] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 2;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
		} else {
			p01[0] = 0;
			p01[1] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 2;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
		} else {
			p11[0] = 0;
			p11[1] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
	}
}

void qb_do_sample_bilinear_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_2x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 2;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_2x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 2;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_3x_F32(float32_t *op1_ptr, uint32_t op2, uint32_t op3, float32_t op4, float32_t op5, float32_t *res_ptr) {
	int32_t ix = (int32_t) floorf(op4 - 0.5f);
	int32_t iy = (int32_t) floorf(op5 - 0.5f);
	float32_t fx = (op4 - 0.5f) - floorf(op4 - 0.5f);
	float32_t fy = (op5 - 0.5f) - floorf(op5 - 0.5f);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 3;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
			res_ptr[2] = op1_ptr[index + 2];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
			res_ptr[2] = 0;
		}
	} else { 
		float32_t fx1 = 1.0f - fx;
		float32_t fy1 = 1.0f - fy;
		float32_t w00 = fx1 * fy1;
		float32_t w10 = fx * fy1;
		float32_t w01 = fx1 * fy;
		float32_t w11 = fx * fy;
		float32_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 3;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
			p00[2] = op1_ptr[index + 2];
		} else {
			p00[0] = 0;
			p00[1] = 0;
			p00[2] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 3;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
			p10[2] = op1_ptr[index + 2];
		} else {
			p10[0] = 0;
			p10[1] = 0;
			p10[2] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 3;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
			p01[2] = op1_ptr[index + 2];
		} else {
			p01[0] = 0;
			p01[1] = 0;
			p01[2] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 3;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
			p11[2] = op1_ptr[index + 2];
		} else {
			p11[0] = 0;
			p11[1] = 0;
			p11[2] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
		res_ptr[2] = p00[2] * w00 + p10[2] * w10 + p01[2] * w01 + p11[2] * w11;
	}
}

void qb_do_sample_bilinear_3x_F64(float64_t *op1_ptr, uint32_t op2, uint32_t op3, float64_t op4, float64_t op5, float64_t *res_ptr) {
	int32_t ix = (int32_t) floor(op4 - 0.5);
	int32_t iy = (int32_t) floor(op5 - 0.5);
	float64_t fx = (op4 - 0.5) - floor(op4 - 0.5);
	float64_t fy = (op5 - 0.5) - floor(op5 - 0.5);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 3;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
			res_ptr[2] = op1_ptr[index + 2];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
			res_ptr[2] = 0;
		}
	} else { 
		float64_t fx1 = 1.0 - fx;
		float64_t fy1 = 1.0 - fy;
		float64_t w00 = fx1 * fy1;
		float64_t w10 = fx * fy1;
		float64_t w01 = fx1 * fy;
		float64_t w11 = fx * fy;
		float64_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 3;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
			p00[2] = op1_ptr[index + 2];
		} else {
			p00[0] = 0;
			p00[1] = 0;
			p00[2] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 3;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
			p10[2] = op1_ptr[index + 2];
		} else {
			p10[0] = 0;
			p10[1] = 0;
			p10[2] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 3;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
			p01[2] = op1_ptr[index + 2];
		} else {
			p01[0] = 0;
			p01[1] = 0;
			p01[2] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 3;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
			p11[2] = op1_ptr[index + 2];
		} else {
			p11[0] = 0;
			p11[1] = 0;
			p11[2] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
		res_ptr[2] = p00[2] * w00 + p10[2] * w10 + p01[2] * w01 + p11[2] * w11;
	}
}

void qb_do_sample_bilinear_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_3x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 3;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_3x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 3;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_4x_F32(float32_t *op1_ptr, uint32_t op2, uint32_t op3, float32_t op4, float32_t op5, float32_t *res_ptr) {
	int32_t ix = (int32_t) floorf(op4 - 0.5f);
	int32_t iy = (int32_t) floorf(op5 - 0.5f);
	float32_t fx = (op4 - 0.5f) - floorf(op4 - 0.5f);
	float32_t fy = (op5 - 0.5f) - floorf(op5 - 0.5f);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 4;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
			res_ptr[2] = op1_ptr[index + 2];
			res_ptr[3] = op1_ptr[index + 3];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
			res_ptr[2] = 0;
			res_ptr[3] = 0;
		}
	} else { 
		float32_t fx1 = 1.0f - fx;
		float32_t fy1 = 1.0f - fy;
		float32_t w00 = fx1 * fy1;
		float32_t w10 = fx * fy1;
		float32_t w01 = fx1 * fy;
		float32_t w11 = fx * fy;
		float32_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 4;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
			p00[2] = op1_ptr[index + 2];
			p00[3] = op1_ptr[index + 3];
		} else {
			p00[0] = 0;
			p00[1] = 0;
			p00[2] = 0;
			p00[3] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 4;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
			p10[2] = op1_ptr[index + 2];
			p10[3] = op1_ptr[index + 3];
		} else {
			p10[0] = 0;
			p10[1] = 0;
			p10[2] = 0;
			p10[3] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 4;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
			p01[2] = op1_ptr[index + 2];
			p01[3] = op1_ptr[index + 3];
		} else {
			p01[0] = 0;
			p01[1] = 0;
			p01[2] = 0;
			p01[3] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 4;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
			p11[2] = op1_ptr[index + 2];
			p11[3] = op1_ptr[index + 3];
		} else {
			p11[0] = 0;
			p11[1] = 0;
			p11[2] = 0;
			p11[3] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
		res_ptr[2] = p00[2] * w00 + p10[2] * w10 + p01[2] * w01 + p11[2] * w11;
		res_ptr[3] = p00[3] * w00 + p10[3] * w10 + p01[3] * w01 + p11[3] * w11;
	}
}

void qb_do_sample_bilinear_4x_F64(float64_t *op1_ptr, uint32_t op2, uint32_t op3, float64_t op4, float64_t op5, float64_t *res_ptr) {
	int32_t ix = (int32_t) floor(op4 - 0.5);
	int32_t iy = (int32_t) floor(op5 - 0.5);
	float64_t fx = (op4 - 0.5) - floor(op4 - 0.5);
	float64_t fy = (op5 - 0.5) - floor(op5 - 0.5);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 4;
			res_ptr[0] = op1_ptr[index + 0];
			res_ptr[1] = op1_ptr[index + 1];
			res_ptr[2] = op1_ptr[index + 2];
			res_ptr[3] = op1_ptr[index + 3];
		} else {
			res_ptr[0] = 0;
			res_ptr[1] = 0;
			res_ptr[2] = 0;
			res_ptr[3] = 0;
		}
	} else { 
		float64_t fx1 = 1.0 - fx;
		float64_t fy1 = 1.0 - fy;
		float64_t w00 = fx1 * fy1;
		float64_t w10 = fx * fy1;
		float64_t w01 = fx1 * fy;
		float64_t w11 = fx * fy;
		float64_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 4;
			p00[0] = op1_ptr[index + 0];
			p00[1] = op1_ptr[index + 1];
			p00[2] = op1_ptr[index + 2];
			p00[3] = op1_ptr[index + 3];
		} else {
			p00[0] = 0;
			p00[1] = 0;
			p00[2] = 0;
			p00[3] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 4;
			p10[0] = op1_ptr[index + 0];
			p10[1] = op1_ptr[index + 1];
			p10[2] = op1_ptr[index + 2];
			p10[3] = op1_ptr[index + 3];
		} else {
			p10[0] = 0;
			p10[1] = 0;
			p10[2] = 0;
			p10[3] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 4;
			p01[0] = op1_ptr[index + 0];
			p01[1] = op1_ptr[index + 1];
			p01[2] = op1_ptr[index + 2];
			p01[3] = op1_ptr[index + 3];
		} else {
			p01[0] = 0;
			p01[1] = 0;
			p01[2] = 0;
			p01[3] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 4;
			p11[0] = op1_ptr[index + 0];
			p11[1] = op1_ptr[index + 1];
			p11[2] = op1_ptr[index + 2];
			p11[3] = op1_ptr[index + 3];
		} else {
			p11[0] = 0;
			p11[1] = 0;
			p11[2] = 0;
			p11[3] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
		res_ptr[1] = p00[1] * w00 + p10[1] * w10 + p01[1] * w01 + p11[1] * w11;
		res_ptr[2] = p00[2] * w00 + p10[2] * w10 + p01[2] * w01 + p11[2] * w11;
		res_ptr[3] = p00[3] * w00 + p10[3] * w10 + p01[3] * w01 + p11[3] * w11;
	}
}

void qb_do_sample_bilinear_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_4x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 4;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_4x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 4;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_F32(float32_t *op1_ptr, uint32_t op2, uint32_t op3, float32_t op4, float32_t op5, float32_t *res_ptr) {
	int32_t ix = (int32_t) floorf(op4 - 0.5f);
	int32_t iy = (int32_t) floorf(op5 - 0.5f);
	float32_t fx = (op4 - 0.5f) - floorf(op4 - 0.5f);
	float32_t fy = (op5 - 0.5f) - floorf(op5 - 0.5f);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 1;
			res_ptr[0] = op1_ptr[index + 0];
		} else {
			res_ptr[0] = 0;
		}
	} else { 
		float32_t fx1 = 1.0f - fx;
		float32_t fy1 = 1.0f - fy;
		float32_t w00 = fx1 * fy1;
		float32_t w10 = fx * fy1;
		float32_t w01 = fx1 * fy;
		float32_t w11 = fx * fy;
		float32_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 1;
			p00[0] = op1_ptr[index + 0];
		} else {
			p00[0] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 1;
			p10[0] = op1_ptr[index + 0];
		} else {
			p10[0] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 1;
			p01[0] = op1_ptr[index + 0];
		} else {
			p01[0] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 1;
			p11[0] = op1_ptr[index + 0];
		} else {
			p11[0] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
	}
}

void qb_do_sample_bilinear_F64(float64_t *op1_ptr, uint32_t op2, uint32_t op3, float64_t op4, float64_t op5, float64_t *res_ptr) {
	int32_t ix = (int32_t) floor(op4 - 0.5);
	int32_t iy = (int32_t) floor(op5 - 0.5);
	float64_t fx = (op4 - 0.5) - floor(op4 - 0.5);
	float64_t fy = (op5 - 0.5) - floor(op5 - 0.5);
	if(fx + fy == 0) {
		if(((uint32_t) ix < op2) && ((uint32_t) iy < op3)) {
			uint32_t index = ((iy * op2) + ix) * 1;
			res_ptr[0] = op1_ptr[index + 0];
		} else {
			res_ptr[0] = 0;
		}
	} else { 
		float64_t fx1 = 1.0 - fx;
		float64_t fy1 = 1.0 - fy;
		float64_t w00 = fx1 * fy1;
		float64_t w10 = fx * fy1;
		float64_t w01 = fx1 * fy;
		float64_t w11 = fx * fy;
		float64_t p00[4], p01[4], p10[4], p11[4];
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 0)) * 1;
			p00[0] = op1_ptr[index + 0];
		} else {
			p00[0] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 0) < op3)) {
			uint32_t index = (((iy + 0) * op2) + (ix + 1)) * 1;
			p10[0] = op1_ptr[index + 0];
		} else {
			p10[0] = 0;
		}
		if((((uint32_t) ix + 0) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 0)) * 1;
			p01[0] = op1_ptr[index + 0];
		} else {
			p01[0] = 0;
		}
		if((((uint32_t) ix + 1) < op2) && (((uint32_t) iy + 1) < op3)) {
			uint32_t index = (((iy + 1) * op2) + (ix + 1)) * 1;
			p11[0] = op1_ptr[index + 0];
		} else {
			p11[0] = 0;
		}
		res_ptr[0] = p00[0] * w00 + p10[0] * w10 + p01[0] * w01 + p11[0] * w11;
	}
}

void qb_do_sample_bilinear_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 1;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_bilinear_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_bilinear_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 1;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_2x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 2;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_2x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 2;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_3x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 3;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_3x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 3;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_4x_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 4;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_4x_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 4;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *op4_ptr, uint32_t op4_count, float32_t *op5_ptr, uint32_t op5_count, float32_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float32_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float32_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_F32(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 1;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_sample_nearest_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *op4_ptr, uint32_t op4_count, float64_t *op5_ptr, uint32_t op5_count, float64_t *res_ptr, uint32_t res_count) {
	if(op4_count && op5_count && res_count) {
		float64_t *op4_start = op4_ptr, *op4_end = op4_ptr + op4_count;
		float64_t *op5_start = op5_ptr, *op5_end = op5_ptr + op5_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sample_nearest_F64(op1_ptr, op2, op3, (*op4_ptr), (*op5_ptr), res_ptr);
			
			res_ptr += 1;
			op4_ptr += 1;
			op5_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op4_ptr >= op4_end) {
				op4_ptr = op4_start;
			}
			if(op5_ptr >= op5_end) {
				op5_ptr = op5_start;
			}
		}
	}
}

void qb_do_scatter_8x_F32(uint32_t op1, float32_t *op2_ptr, float32_t *res_ptr) {
	float32_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_scatter_8x_F64(uint32_t op1, float64_t *op2_ptr, float64_t *res_ptr) {
	float64_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_scatter_8x_I08(uint32_t op1, int8_t *op2_ptr, int8_t *res_ptr) {
	int8_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_scatter_8x_I16(uint32_t op1, int16_t *op2_ptr, int16_t *res_ptr) {
	int16_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_scatter_8x_I32(uint32_t op1, int32_t *op2_ptr, int32_t *res_ptr) {
	int32_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_scatter_8x_I64(uint32_t op1, int64_t *op2_ptr, int64_t *res_ptr) {
	int64_t v0, v1, v2, v3, v4, v5, v6, v7;
	v0 = op2_ptr[0];
	v1 = op2_ptr[1];
	v2 = op2_ptr[2];
	v3 = op2_ptr[3];
	v4 = op2_ptr[4];
	v5 = op2_ptr[5];
	v6 = op2_ptr[6];
	v7 = op2_ptr[7];
	res_ptr[(op1 >> 0) & 0x0007] = v0;
	res_ptr[(op1 >> 3) & 0x0007] = v1;
	res_ptr[(op1 >> 6) & 0x0007] = v2;
	res_ptr[(op1 >> 9) & 0x0007] = v3;
	res_ptr[(op1 >> 12) & 0x0007] = v4;
	res_ptr[(op1 >> 15) & 0x0007] = v5;
	res_ptr[(op1 >> 18) & 0x0007] = v6;
	res_ptr[(op1 >> 21) & 0x0007] = v7;
}

void qb_do_set_all_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	int32_t *op1_end = op1_ptr + op1_count;
	(*res_ptr) = 1;
	while(op1_ptr != op1_end) {
		if(!(*op1_ptr)) {
			(*res_ptr) = 0;
			break;
		}
		op1_ptr++;
	}
}

void qb_do_set_any_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr) {
	int32_t *op1_end = op1_ptr + op1_count;
	(*res_ptr) = 0;
	while(op1_ptr != op1_end) {
		if((*op1_ptr)) {
			(*res_ptr) = 1;
			break;
		}
		op1_ptr++;
	}
}

void qb_do_set_equal_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_equal_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_equal_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_equal_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_equal_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_equal_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) == (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) < (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_less_than_equal_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) <= (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = (!(*op1_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_set_not_equal_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_equal_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_equal_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_equal_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_equal_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_set_not_equal_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			(*res_ptr) = ((*op1_ptr) != (*op2_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_left_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) << (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_S08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_S16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_S32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_S64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_U08(uint8_t *op1_ptr, uint32_t op1_count, uint8_t *op2_ptr, uint32_t op2_count, uint8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_U16(uint16_t *op1_ptr, uint32_t op1_count, uint16_t *op2_ptr, uint32_t op2_count, uint16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *op2_ptr, uint32_t op2_count, uint32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shift_right_multiple_times_U64(uint64_t *op1_ptr, uint32_t op1_count, uint64_t *op2_ptr, uint32_t op2_count, uint64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		uint64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		uint64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		uint64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) >> (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_shuffle_F32(qb_interpreter_context *__restrict cxt, uint32_t op1, float32_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	float32_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(float32_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(float32_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(float32_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(float32_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_shuffle_F64(qb_interpreter_context *__restrict cxt, uint32_t op1, float64_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	float64_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(float64_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(float64_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(float64_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(float64_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_shuffle_I08(qb_interpreter_context *__restrict cxt, uint32_t op1, int8_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	int8_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(int8_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(int8_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(int8_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(int8_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_shuffle_I16(qb_interpreter_context *__restrict cxt, uint32_t op1, int16_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	int16_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(int16_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(int16_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(int16_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(int16_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_shuffle_I32(qb_interpreter_context *__restrict cxt, uint32_t op1, int32_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	int32_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(int32_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(int32_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(int32_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(int32_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_shuffle_I64(qb_interpreter_context *__restrict cxt, uint32_t op1, int64_t *res_ptr, uint32_t res_count) {
	USE_TSRM
	uint32_t n_elems, n_left, rnd_idx;
	int64_t temp, *temps = NULL, *elems = res_ptr;
	ALLOCA_FLAG(use_heap);
	if(op1 == 1) {
		n_elems = res_count;
		temps = NULL;
	} else {
		n_elems = res_count / op1;
		temps = do_alloca(sizeof(int64_t) * op1, use_heap);
	}
	n_left = n_elems;
	while(--n_left) {
		rnd_idx = php_rand(TSRMLS_C);
		RAND_RANGE(rnd_idx, 0, n_left, PHP_RAND_MAX);
		if(rnd_idx != n_left) {
			if(op1 == 1) {
				temp = elems[n_left];
				elems[n_left] = elems[rnd_idx];
				elems[rnd_idx] = temp;
			} else {
				memcpy(temps, &elems[n_left * op1], sizeof(int64_t) * op1);
				memcpy(&elems[n_left * op1], &elems[rnd_idx * op1], sizeof(int64_t) * op1);
				memcpy(&elems[rnd_idx * op1], temps, sizeof(int64_t) * op1);
			}
		}
	}
	if(temps) {
		free_alloca(temps, use_heap);
	}
}

void qb_do_sign_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sign_F32((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sign_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_sign_F64((*op1_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sin_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float32_t) sinf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sin_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (float64_t) sin((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sinh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = sinhf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sinh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = sinh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_smooth_step_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *op3_ptr, uint32_t op3_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_smooth_step_F32((*op1_ptr), (*op2_ptr), (*op3_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_smooth_step_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *op3_ptr, uint32_t op3_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && op3_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *op3_start = op3_ptr, *op3_end = op3_ptr + op3_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_smooth_step_F64((*op1_ptr), (*op2_ptr), (*op3_ptr), &(*res_ptr));
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			op3_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
			if(op3_ptr >= op3_end) {
				op3_ptr = op3_start;
			}
		}
	}
}

void qb_do_sort_F32(uint32_t op1, float32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(float32_t) * 1, (void *) qb_compare_ascending_F32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(float32_t) * op1, (void *) qb_compare_ascending_F32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(float32_t) * op1, (void *) qb_compare_ascending_F32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(float32_t) * op1, &op1, (void *) qb_compare_ascending_F32_array);
#endif
	}
}

void qb_do_sort_F64(uint32_t op1, float64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(float64_t) * 1, (void *) qb_compare_ascending_F64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(float64_t) * op1, (void *) qb_compare_ascending_F64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(float64_t) * op1, (void *) qb_compare_ascending_F64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(float64_t) * op1, &op1, (void *) qb_compare_ascending_F64_array);
#endif
	}
}

void qb_do_sort_S08(uint32_t op1, int8_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int8_t) * 1, (void *) qb_compare_ascending_S08);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int8_t) * op1, (void *) qb_compare_ascending_S08_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int8_t) * op1, (void *) qb_compare_ascending_S08_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int8_t) * op1, &op1, (void *) qb_compare_ascending_S08_array);
#endif
	}
}

void qb_do_sort_S16(uint32_t op1, int16_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int16_t) * 1, (void *) qb_compare_ascending_S16);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int16_t) * op1, (void *) qb_compare_ascending_S16_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int16_t) * op1, (void *) qb_compare_ascending_S16_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int16_t) * op1, &op1, (void *) qb_compare_ascending_S16_array);
#endif
	}
}

void qb_do_sort_S32(uint32_t op1, int32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int32_t) * 1, (void *) qb_compare_ascending_S32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int32_t) * op1, (void *) qb_compare_ascending_S32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int32_t) * op1, (void *) qb_compare_ascending_S32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int32_t) * op1, &op1, (void *) qb_compare_ascending_S32_array);
#endif
	}
}

void qb_do_sort_S64(uint32_t op1, int64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(int64_t) * 1, (void *) qb_compare_ascending_S64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(int64_t) * op1, (void *) qb_compare_ascending_S64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(int64_t) * op1, (void *) qb_compare_ascending_S64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(int64_t) * op1, &op1, (void *) qb_compare_ascending_S64_array);
#endif
	}
}

void qb_do_sort_U08(uint32_t op1, uint8_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint8_t) * 1, (void *) qb_compare_ascending_U08);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint8_t) * op1, (void *) qb_compare_ascending_U08_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint8_t) * op1, (void *) qb_compare_ascending_U08_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint8_t) * op1, &op1, (void *) qb_compare_ascending_U08_array);
#endif
	}
}

void qb_do_sort_U16(uint32_t op1, uint16_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint16_t) * 1, (void *) qb_compare_ascending_U16);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint16_t) * op1, (void *) qb_compare_ascending_U16_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint16_t) * op1, (void *) qb_compare_ascending_U16_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint16_t) * op1, &op1, (void *) qb_compare_ascending_U16_array);
#endif
	}
}

void qb_do_sort_U32(uint32_t op1, uint32_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint32_t) * 1, (void *) qb_compare_ascending_U32);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint32_t) * op1, (void *) qb_compare_ascending_U32_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint32_t) * op1, (void *) qb_compare_ascending_U32_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint32_t) * op1, &op1, (void *) qb_compare_ascending_U32_array);
#endif
	}
}

void qb_do_sort_U64(uint32_t op1, uint64_t *res_ptr, uint32_t res_count) {
	if(op1 == 1) {
		qsort(res_ptr, res_count, sizeof(uint64_t) * 1, (void *) qb_compare_ascending_U64);
	} else {
#if defined(__linux__)
		qsort_r(res_ptr, res_count / op1, sizeof(uint64_t) * op1, (void *) qb_compare_ascending_U64_array, &op1);
#elif defined(_MSC_VER)
		qsort_s(res_ptr, res_count / op1, sizeof(uint64_t) * op1, (void *) qb_compare_ascending_U64_array, &op1);
#else
		qsort_r(res_ptr, res_count / op1, sizeof(uint64_t) * op1, &op1, (void *) qb_compare_ascending_U64_array);
#endif
	}
}

void qb_do_sqrt_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = sqrtf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_sqrt_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = sqrt((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_step_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (((*op2_ptr) < (*op1_ptr)) ? 0.0f : 1.0f);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_step_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (((*op2_ptr) < (*op1_ptr)) ? 0.0 : 1.0);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subarray_position_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		for(i = op3; i < op1_count - op2_count; i++) {
			if(op1_ptr[i] == op2_ptr[0]) {
				for(j = 1; j < op2_count; j++) {
					if(op1_ptr[i + j] != op2_ptr[j]) {
						break;
					}
				}
				if(j == op2_count) {
					index = i;
					break;
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subarray_position_from_end_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int32_t op3, int32_t *res_ptr) {
	int32_t index = -1;
	if(op2_count > 0) {
		uint32_t i, j;
		if(op3 < 0) {
			for(i = op1_count + op3; (int32_t) i >= 0; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		} else {
			for(i = op1_count - 1; (int32_t) i >= op3; i--) {
				if(op1_ptr[i] == op2_ptr[0]) {
					for(j = 1; j < op2_count; j++) {
						if(op1_ptr[i + j] != op2_ptr[j]) {
							break;
						}
					}
					if(j == op2_count) {
						index = i;
						break;
					}
				}
			}
		}
	}
	(*res_ptr) = index;
}

void qb_do_subtract_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
			}
			
			res_ptr += 2;
			op1_ptr += 2;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
				res_ptr[2] = op1_ptr[2] - op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
				res_ptr[2] = op1_ptr[2] - op2_ptr[2];
			}
			
			res_ptr += 3;
			op1_ptr += 3;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
				res_ptr[2] = op1_ptr[2] - op2_ptr[2];
				res_ptr[3] = op1_ptr[3] - op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				res_ptr[0] = op1_ptr[0] - op2_ptr[0];
				res_ptr[1] = op1_ptr[1] - op2_ptr[1];
				res_ptr[2] = op1_ptr[2] - op2_ptr[2];
				res_ptr[3] = op1_ptr[3] - op2_ptr[3];
			}
			
			res_ptr += 4;
			op1_ptr += 4;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_I08(int8_t *op1_ptr, uint32_t op1_count, int8_t *op2_ptr, uint32_t op2_count, int8_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int8_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int8_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int8_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_I16(int16_t *op1_ptr, uint32_t op1_count, int16_t *op2_ptr, uint32_t op2_count, int16_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int16_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int16_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int16_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_I32(int32_t *op1_ptr, uint32_t op1_count, int32_t *op2_ptr, uint32_t op2_count, int32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_subtract_multiple_times_I64(int64_t *op1_ptr, uint32_t op1_count, int64_t *op2_ptr, uint32_t op2_count, int64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		int64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		int64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		int64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = (*op1_ptr) - (*op2_ptr);
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			op2_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_tan_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = tanf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_tan_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = tan((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_tanh_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = tanhf((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_tanh_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			{
				(*res_ptr) = tanh((*op1_ptr));
			}
			
			res_ptr += 1;
			op1_ptr += 1;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transform_vector_2x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_2x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 6;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_2x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_2x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 6;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_2x_multiple_times_row_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_2x_row_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 6;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_2x_multiple_times_row_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_2x_row_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 2;
			op1_ptr += 6;
			op2_ptr += 2;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_3x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_3x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 12;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_3x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_3x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 12;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_3x_multiple_times_row_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_3x_row_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 12;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_3x_multiple_times_row_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_3x_row_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 3;
			op1_ptr += 12;
			op2_ptr += 3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_4x_multiple_times_column_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_4x_column_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 20;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_4x_multiple_times_column_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_4x_column_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 20;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_4x_multiple_times_row_major_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *op2_ptr, uint32_t op2_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_4x_row_major_F32(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 20;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transform_vector_4x_multiple_times_row_major_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *op2_ptr, uint32_t op2_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && op2_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *op2_start = op2_ptr, *op2_end = op2_ptr + op2_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transform_vector_4x_row_major_F64(op1_ptr, op2_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 20;
			op2_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
			if(op2_ptr >= op2_end) {
				op2_ptr = op2_start;
			}
		}
	}
}

void qb_do_transpose_matrix_2x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_2x_F32(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_2x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_2x_F64(op1_ptr, res_ptr);
			
			res_ptr += 4;
			op1_ptr += 4;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_3x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t m00 = op1_ptr[0 * 3 + 0];
	float32_t m10 = op1_ptr[0 * 3 + 1];
	float32_t m20 = op1_ptr[0 * 3 + 2];
	float32_t m01 = op1_ptr[1 * 3 + 0];
	float32_t m11 = op1_ptr[1 * 3 + 1];
	float32_t m21 = op1_ptr[1 * 3 + 2];
	float32_t m02 = op1_ptr[2 * 3 + 0];
	float32_t m12 = op1_ptr[2 * 3 + 1];
	float32_t m22 = op1_ptr[2 * 3 + 2];
	res_ptr[0 * 3 + 0] = m00;
	res_ptr[0 * 3 + 1] = m01;
	res_ptr[0 * 3 + 2] = m02;
	res_ptr[1 * 3 + 0] = m10;
	res_ptr[1 * 3 + 1] = m11;
	res_ptr[1 * 3 + 2] = m12;
	res_ptr[2 * 3 + 0] = m20;
	res_ptr[2 * 3 + 1] = m21;
	res_ptr[2 * 3 + 2] = m22;
}

void qb_do_transpose_matrix_3x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t m00 = op1_ptr[0 * 3 + 0];
	float64_t m10 = op1_ptr[0 * 3 + 1];
	float64_t m20 = op1_ptr[0 * 3 + 2];
	float64_t m01 = op1_ptr[1 * 3 + 0];
	float64_t m11 = op1_ptr[1 * 3 + 1];
	float64_t m21 = op1_ptr[1 * 3 + 2];
	float64_t m02 = op1_ptr[2 * 3 + 0];
	float64_t m12 = op1_ptr[2 * 3 + 1];
	float64_t m22 = op1_ptr[2 * 3 + 2];
	res_ptr[0 * 3 + 0] = m00;
	res_ptr[0 * 3 + 1] = m01;
	res_ptr[0 * 3 + 2] = m02;
	res_ptr[1 * 3 + 0] = m10;
	res_ptr[1 * 3 + 1] = m11;
	res_ptr[1 * 3 + 2] = m12;
	res_ptr[2 * 3 + 0] = m20;
	res_ptr[2 * 3 + 1] = m21;
	res_ptr[2 * 3 + 2] = m22;
}

void qb_do_transpose_matrix_3x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_3x_F32(op1_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_3x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_3x_F64(op1_ptr, res_ptr);
			
			res_ptr += 9;
			op1_ptr += 9;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_4x_F32(float32_t *op1_ptr, float32_t *res_ptr) {
	float32_t m00 = op1_ptr[0 * 4 + 0];
	float32_t m10 = op1_ptr[0 * 4 + 1];
	float32_t m20 = op1_ptr[0 * 4 + 2];
	float32_t m30 = op1_ptr[0 * 4 + 3];
	float32_t m01 = op1_ptr[1 * 4 + 0];
	float32_t m11 = op1_ptr[1 * 4 + 1];
	float32_t m21 = op1_ptr[1 * 4 + 2];
	float32_t m31 = op1_ptr[1 * 4 + 3];
	float32_t m02 = op1_ptr[2 * 4 + 0];
	float32_t m12 = op1_ptr[2 * 4 + 1];
	float32_t m22 = op1_ptr[2 * 4 + 2];
	float32_t m32 = op1_ptr[2 * 4 + 3];
	float32_t m03 = op1_ptr[3 * 4 + 0];
	float32_t m13 = op1_ptr[3 * 4 + 1];
	float32_t m23 = op1_ptr[3 * 4 + 2];
	float32_t m33 = op1_ptr[3 * 4 + 3];
	res_ptr[0 * 4 + 0] = m00;
	res_ptr[0 * 4 + 1] = m01;
	res_ptr[0 * 4 + 2] = m02;
	res_ptr[0 * 4 + 3] = m03;
	res_ptr[1 * 4 + 0] = m10;
	res_ptr[1 * 4 + 1] = m11;
	res_ptr[1 * 4 + 2] = m12;
	res_ptr[1 * 4 + 3] = m13;
	res_ptr[2 * 4 + 0] = m20;
	res_ptr[2 * 4 + 1] = m21;
	res_ptr[2 * 4 + 2] = m22;
	res_ptr[2 * 4 + 3] = m23;
	res_ptr[3 * 4 + 0] = m30;
	res_ptr[3 * 4 + 1] = m31;
	res_ptr[3 * 4 + 2] = m32;
	res_ptr[3 * 4 + 3] = m33;
}

void qb_do_transpose_matrix_4x_F64(float64_t *op1_ptr, float64_t *res_ptr) {
	float64_t m00 = op1_ptr[0 * 4 + 0];
	float64_t m10 = op1_ptr[0 * 4 + 1];
	float64_t m20 = op1_ptr[0 * 4 + 2];
	float64_t m30 = op1_ptr[0 * 4 + 3];
	float64_t m01 = op1_ptr[1 * 4 + 0];
	float64_t m11 = op1_ptr[1 * 4 + 1];
	float64_t m21 = op1_ptr[1 * 4 + 2];
	float64_t m31 = op1_ptr[1 * 4 + 3];
	float64_t m02 = op1_ptr[2 * 4 + 0];
	float64_t m12 = op1_ptr[2 * 4 + 1];
	float64_t m22 = op1_ptr[2 * 4 + 2];
	float64_t m32 = op1_ptr[2 * 4 + 3];
	float64_t m03 = op1_ptr[3 * 4 + 0];
	float64_t m13 = op1_ptr[3 * 4 + 1];
	float64_t m23 = op1_ptr[3 * 4 + 2];
	float64_t m33 = op1_ptr[3 * 4 + 3];
	res_ptr[0 * 4 + 0] = m00;
	res_ptr[0 * 4 + 1] = m01;
	res_ptr[0 * 4 + 2] = m02;
	res_ptr[0 * 4 + 3] = m03;
	res_ptr[1 * 4 + 0] = m10;
	res_ptr[1 * 4 + 1] = m11;
	res_ptr[1 * 4 + 2] = m12;
	res_ptr[1 * 4 + 3] = m13;
	res_ptr[2 * 4 + 0] = m20;
	res_ptr[2 * 4 + 1] = m21;
	res_ptr[2 * 4 + 2] = m22;
	res_ptr[2 * 4 + 3] = m23;
	res_ptr[3 * 4 + 0] = m30;
	res_ptr[3 * 4 + 1] = m31;
	res_ptr[3 * 4 + 2] = m32;
	res_ptr[3 * 4 + 3] = m33;
}

void qb_do_transpose_matrix_4x_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_4x_F32(op1_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_4x_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_4x_F64(op1_ptr, res_ptr);
			
			res_ptr += 16;
			op1_ptr += 16;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k, p;
	uint32_t matrix_rows = op2, matrix_cols = op3;
	float32_t *__restrict buffer = do_alloca(matrix_rows * matrix_cols * sizeof(float32_t), use_heap);
	for(i = 0, p = 0; i < matrix_rows; i++) {
		for(j = 0, k = i; j < matrix_cols; j++, p++, k += matrix_rows) {
			buffer[k] = op1_ptr[p];
		}
	}
	memcpy(res_ptr, buffer, matrix_rows * matrix_cols * sizeof(float32_t));
	free_alloca(buffer, use_heap);
}

void qb_do_transpose_matrix_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	ALLOCA_FLAG(use_heap)
	uint32_t i, j, k, p;
	uint32_t matrix_rows = op2, matrix_cols = op3;
	float64_t *__restrict buffer = do_alloca(matrix_rows * matrix_cols * sizeof(float64_t), use_heap);
	for(i = 0, p = 0; i < matrix_rows; i++) {
		for(j = 0, k = i; j < matrix_cols; j++, p++, k += matrix_rows) {
			buffer[k] = op1_ptr[p];
		}
	}
	memcpy(res_ptr, buffer, matrix_rows * matrix_cols * sizeof(float64_t));
	free_alloca(buffer, use_heap);
}

void qb_do_transpose_matrix_multiple_times_F32(float32_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float32_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float32_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float32_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_F32(op1_ptr, op1_count, op2, op3, res_ptr, res_count);
			
			res_ptr += op2 * op3;
			op1_ptr += op2 * op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_transpose_matrix_multiple_times_F64(float64_t *op1_ptr, uint32_t op1_count, uint32_t op2, uint32_t op3, float64_t *res_ptr, uint32_t res_count) {
	if(op1_count && res_count) {
		float64_t *op1_start = op1_ptr, *op1_end = op1_ptr + op1_count;
		float64_t *res_end = res_ptr + res_count;
		for(;;) {
			qb_do_transpose_matrix_F64(op1_ptr, op1_count, op2, op3, res_ptr, res_count);
			
			res_ptr += op2 * op3;
			op1_ptr += op2 * op3;
			if(res_ptr >= res_end) {
				break;
			}
			if(op1_ptr >= op1_end) {
				op1_ptr = op1_start;
			}
		}
	}
}

void qb_do_utf8decode_U16(uint8_t *op1_ptr, uint32_t op1_count, uint16_t *res_ptr, uint32_t res_count) {
	uint32_t codepoint, state = 0, i, j;
	for(i = 0, j = 0; i < op1_count; i++) {
		if(!decode(&state, &codepoint, op1_ptr[i])) {
			res_ptr[j++] = codepoint;
		}
	}
}

void qb_do_utf8decode_U32(uint8_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr, uint32_t res_count) {
	uint32_t codepoint, state = 0, i, j;
	for(i = 0, j = 0; i < op1_count; i++) {
		if(!decode(&state, &codepoint, op1_ptr[i])) {
			res_ptr[j++] = codepoint;
		}
	}
}

void qb_do_utf8decode_count_U16(uint8_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	uint32_t codepoint, state = 0, count = 0, i;
	for(i = 0; i < op1_count; i++) {
		if(!decode(&state, &codepoint, op1_ptr[i])) {
			count++;
		}
	}
	(*res_ptr) = count;
}

void qb_do_utf8encode_U16(uint16_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr, uint32_t res_count) {
	uint32_t length = 0, i;
	for(i = 0; i < op1_count; i++) {
		length += encode(op1_ptr[i], res_ptr + length);
	}
}

void qb_do_utf8encode_U32(uint32_t *op1_ptr, uint32_t op1_count, uint8_t *res_ptr, uint32_t res_count) {
	uint32_t length = 0, i;
	for(i = 0; i < op1_count; i++) {
		length += encode(op1_ptr[i], res_ptr + length);
	}
}

void qb_do_utf8encode_count_U16(uint16_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	uint32_t length = 0, i;
	for(i = 0; i < op1_count; i++) {
		uint8_t buffer[4];
		length += encode(op1_ptr[i], buffer);
	}
	(*res_ptr) = length;
}

void qb_do_utf8encode_count_U32(uint32_t *op1_ptr, uint32_t op1_count, uint32_t *res_ptr) {
	uint32_t length = 0, i;
	for(i = 0; i < op1_count; i++) {
		uint8_t buffer[4];
		length += encode(op1_ptr[i], buffer);
	}
	(*res_ptr) = length;
}

void qb_redirect_alpha_blend_2x_multiple_times_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_alpha_blend_2x_multiple_times_F32, (qb_instruction_ARR_ARR_ARR *) ip, 2, 2, 2, 1024)) {
		qb_do_alpha_blend_2x_multiple_times_F32(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_alpha_blend_4x_multiple_times_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_alpha_blend_4x_multiple_times_F32, (qb_instruction_ARR_ARR_ARR *) ip, 4, 4, 4, 1024)) {
		qb_do_alpha_blend_4x_multiple_times_F32(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_apply_premultiplication_4x_multiple_times_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define res_count	INSTR->operand2.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR(cxt, qb_redirect_apply_premultiplication_4x_multiple_times_F32, (qb_instruction_ARR_ARR *) ip, 4, 4, 1024)) {
		qb_do_apply_premultiplication_4x_multiple_times_F32(op1_ptr, op1_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef res_ptr
#undef res_count
}

void qb_redirect_remove_premultiplication_4x_multiple_times_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define res_count	INSTR->operand2.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR(cxt, qb_redirect_remove_premultiplication_4x_multiple_times_F32, (qb_instruction_ARR_ARR *) ip, 4, 4, 1024)) {
		qb_do_remove_premultiplication_4x_multiple_times_F32(op1_ptr, op1_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F32, (qb_instruction_ARR_ARR_ARR *) ip, 16, 4, 4, 1024)) {
		qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F32, (qb_instruction_ARR_ARR_ARR *) ip, 9, 3, 3, 1024)) {
		qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float32_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F32, (qb_instruction_ARR_ARR_ARR *) ip, 4, 2, 2, 1024)) {
		qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_SCA_SCA_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define op3	((uint32_t *) INSTR->operand3.data_pointer)[0]
#define op4	((uint32_t *) INSTR->operand4.data_pointer)[0]
#define res_ptr		(((float32_t *) INSTR->operand5.data_pointer) + INSTR->operand5.index_pointer[0])
#define res_count	INSTR->operand5.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_SCA_SCA_ARR(cxt, qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F32, (qb_instruction_ARR_ARR_SCA_SCA_ARR *) ip, (op3 * op4), op3, op4, 1024)) {
		qb_do_multiply_matrix_by_vector_multiple_times_column_major_F32(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef op3
#undef op4
#undef res_ptr
#undef res_count
}

void qb_redirect_alpha_blend_2x_multiple_times_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_alpha_blend_2x_multiple_times_F64, (qb_instruction_ARR_ARR_ARR *) ip, 2, 2, 2, 1024)) {
		qb_do_alpha_blend_2x_multiple_times_F64(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_alpha_blend_4x_multiple_times_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_alpha_blend_4x_multiple_times_F64, (qb_instruction_ARR_ARR_ARR *) ip, 4, 4, 4, 1024)) {
		qb_do_alpha_blend_4x_multiple_times_F64(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_apply_premultiplication_4x_multiple_times_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define res_count	INSTR->operand2.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR(cxt, qb_redirect_apply_premultiplication_4x_multiple_times_F64, (qb_instruction_ARR_ARR *) ip, 4, 4, 1024)) {
		qb_do_apply_premultiplication_4x_multiple_times_F64(op1_ptr, op1_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef res_ptr
#undef res_count
}

void qb_redirect_remove_premultiplication_4x_multiple_times_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define res_count	INSTR->operand2.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR(cxt, qb_redirect_remove_premultiplication_4x_multiple_times_F64, (qb_instruction_ARR_ARR *) ip, 4, 4, 1024)) {
		qb_do_remove_premultiplication_4x_multiple_times_F64(op1_ptr, op1_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F64, (qb_instruction_ARR_ARR_ARR *) ip, 16, 4, 4, 1024)) {
		qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F64, (qb_instruction_ARR_ARR_ARR *) ip, 9, 3, 3, 1024)) {
		qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define res_ptr		(((float64_t *) INSTR->operand3.data_pointer) + INSTR->operand3.index_pointer[0])
#define res_count	INSTR->operand3.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_ARR(cxt, qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F64, (qb_instruction_ARR_ARR_ARR *) ip, 4, 2, 2, 1024)) {
		qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef res_ptr
#undef res_count
}

void qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR_SCA_SCA_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((float64_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
#define op3	((uint32_t *) INSTR->operand3.data_pointer)[0]
#define op4	((uint32_t *) INSTR->operand4.data_pointer)[0]
#define res_ptr		(((float64_t *) INSTR->operand5.data_pointer) + INSTR->operand5.index_pointer[0])
#define res_count	INSTR->operand5.count_pointer[0]
	if(!cxt->thread_count || !qb_dispatch_instruction_ARR_ARR_SCA_SCA_ARR(cxt, qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F64, (qb_instruction_ARR_ARR_SCA_SCA_ARR *) ip, (op3 * op4), op3, op4, 1024)) {
		qb_do_multiply_matrix_by_vector_multiple_times_column_major_F64(op1_ptr, op1_count, op2_ptr, op2_count, op3, op4, res_ptr, res_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
#undef op3
#undef op4
#undef res_ptr
#undef res_count
}

void qb_redirect_print_variable_U32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((uint32_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_U32, ip);
	} else {
		qb_do_print_variable_U32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_U32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((uint32_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_U32, ip);
	} else {
		qb_do_print_variable_U32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_U32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((uint32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_U32, ip);
	} else {
		qb_do_print_variable_multiple_times_U32(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_U32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((uint32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_U32, ip);
	} else {
		qb_do_print_multidimensional_variable_U32(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_S32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((int32_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_S32, ip);
	} else {
		qb_do_print_variable_S32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_S32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((int32_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_S32, ip);
	} else {
		qb_do_print_variable_S32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_S32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((int32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_S32, ip);
	} else {
		qb_do_print_variable_multiple_times_S32(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_S32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((int32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_S32, ip);
	} else {
		qb_do_print_multidimensional_variable_S32(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((float32_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_F32, ip);
	} else {
		qb_do_print_variable_F32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((float32_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_F32, ip);
	} else {
		qb_do_print_variable_F32(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_F32, ip);
	} else {
		qb_do_print_variable_multiple_times_F32(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_F32(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float32_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_F32, ip);
	} else {
		qb_do_print_multidimensional_variable_F32(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((float64_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_F64, ip);
	} else {
		qb_do_print_variable_F64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((float64_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_F64, ip);
	} else {
		qb_do_print_variable_F64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_F64, ip);
	} else {
		qb_do_print_variable_multiple_times_F64(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_F64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((float64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_F64, ip);
	} else {
		qb_do_print_multidimensional_variable_F64(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_S08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((int8_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_S08, ip);
	} else {
		qb_do_print_variable_S08(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_S08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((int8_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_S08, ip);
	} else {
		qb_do_print_variable_S08(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_S08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((int8_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_S08, ip);
	} else {
		qb_do_print_variable_multiple_times_S08(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_S08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((int8_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_S08, ip);
	} else {
		qb_do_print_multidimensional_variable_S08(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_string_U08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((uint8_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_string_U08, ip);
	} else {
		qb_do_print_string_U08(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_variable_U08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((uint8_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_U08, ip);
	} else {
		qb_do_print_variable_U08(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_U08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((uint8_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_U08, ip);
	} else {
		qb_do_print_variable_U08(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_U08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((uint8_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_U08, ip);
	} else {
		qb_do_print_variable_multiple_times_U08(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_U08(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((uint8_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_U08, ip);
	} else {
		qb_do_print_multidimensional_variable_U08(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_S16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((int16_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_S16, ip);
	} else {
		qb_do_print_variable_S16(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_S16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((int16_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_S16, ip);
	} else {
		qb_do_print_variable_S16(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_S16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((int16_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_S16, ip);
	} else {
		qb_do_print_variable_multiple_times_S16(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_S16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((int16_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_S16, ip);
	} else {
		qb_do_print_multidimensional_variable_S16(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_U16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((uint16_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_U16, ip);
	} else {
		qb_do_print_variable_U16(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_U16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((uint16_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_U16, ip);
	} else {
		qb_do_print_variable_U16(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_U16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((uint16_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_U16, ip);
	} else {
		qb_do_print_variable_multiple_times_U16(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_U16(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((uint16_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_U16, ip);
	} else {
		qb_do_print_multidimensional_variable_U16(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_S64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((int64_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_S64, ip);
	} else {
		qb_do_print_variable_S64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_S64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((int64_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_S64, ip);
	} else {
		qb_do_print_variable_S64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_S64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((int64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_S64, ip);
	} else {
		qb_do_print_variable_multiple_times_S64(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_S64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((int64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_S64, ip);
	} else {
		qb_do_print_multidimensional_variable_S64(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

void qb_redirect_print_variable_U64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_SCA * __restrict) ip)
#define op1	((uint64_t *) INSTR->operand1.data_pointer)[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_U64, ip);
	} else {
		qb_do_print_variable_U64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_array_element_U64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ELE * __restrict) ip)
#define op1	((uint64_t *) INSTR->operand1.data_pointer)[INSTR->operand1.index_pointer[0]]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_array_element_U64, ip);
	} else {
		qb_do_print_variable_U64(cxt, op1);
	}
#undef INSTR
#undef op1
}

void qb_redirect_print_variable_multiple_times_U64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR * __restrict) ip)
#define op1_ptr		(((uint64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_variable_multiple_times_U64, ip);
	} else {
		qb_do_print_variable_multiple_times_U64(cxt, op1_ptr, op1_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
}

void qb_redirect_print_multidimensional_variable_U64(qb_interpreter_context *__restrict cxt, int8_t *__restrict ip, int unused) {
#define INSTR		((qb_instruction_ARR_ARR * __restrict) ip)
#define op1_ptr		(((uint64_t *) INSTR->operand1.data_pointer) + INSTR->operand1.index_pointer[0])
#define op1_count	INSTR->operand1.count_pointer[0]
#define op2_ptr		(((uint32_t *) INSTR->operand2.data_pointer) + INSTR->operand2.index_pointer[0])
#define op2_count	INSTR->operand2.count_pointer[0]
	if(!qb_in_main_thread()) {
		qb_dispatch_instruction_to_main_thread(cxt, qb_redirect_print_multidimensional_variable_U64, ip);
	} else {
		qb_do_print_multidimensional_variable_U64(cxt, op1_ptr, op1_count, op2_ptr, op2_count);
	}
#undef INSTR
#undef op1_ptr
#undef op1_count
#undef op2_ptr
#undef op2_count
}

int32_t qb_dispatch_instruction_ARR_ARR(qb_interpreter_context *__restrict cxt, void *control_func, qb_instruction_ARR_ARR *__restrict instr, uint32_t operand1_size, uint32_t operand2_size, uint32_t threshold) {
	int32_t use_multithreading = TRUE;
	uint32_t op2_count = instr->operand2.count_pointer[0];
	if(op2_count >= threshold * operand2_size) {
		USE_TSRM
		uint32_t res_unit_count = op2_count / operand2_size;
		uint32_t thread_count = (cxt->thread_count * threshold <= res_unit_count) ? cxt->thread_count : res_unit_count / threshold + 1;
		uint32_t chunk_size = res_unit_count / thread_count;
		uint32_t op1_count = instr->operand1.count_pointer[0], op1_unit_count = op1_count / operand1_size, op1_shift, op1_chunk_size;
		uint32_t op2_shift = operand2_size * chunk_size, op2_chunk_size = operand2_size * chunk_size;
		if(op1_unit_count == res_unit_count) {
			op1_shift = operand1_size * chunk_size;
			op1_chunk_size = operand1_size * chunk_size;
		} else if(op1_unit_count == 1) {
			op1_shift = 0;
			op1_chunk_size = operand1_size;
		} else {
			use_multithreading = FALSE;
		}
		if(use_multithreading) {
			// create temporary instruction structures
			qb_instruction_ARR_ARR new_instr_list[MAX_THREAD_COUNT];
			uint32_t new_indices[MAX_THREAD_COUNT][2];
			uint32_t new_counts[MAX_THREAD_COUNT][2];
			int8_t *new_ips[MAX_THREAD_COUNT];
			uint32_t i;
			for(i = 0; i < thread_count; i++) {
				qb_instruction_ARR_ARR *new_instr = &new_instr_list[i];
				new_indices[i][0] = i * op1_shift;
				new_counts[i][0] = (i == thread_count - 1) ? op1_count - (i * op1_shift) : op1_chunk_size;
				new_instr->operand1.data_pointer = instr->operand1.data_pointer;
				new_instr->operand1.index_pointer = &new_indices[i][0];
				new_instr->operand1.count_pointer = &new_counts[i][0];
				new_indices[i][1] = i * op2_shift;
				new_counts[i][1] = (i == thread_count - 1) ? op2_count - (i * op2_shift) : op2_chunk_size;
				new_instr->operand2.data_pointer = instr->operand2.data_pointer;
				new_instr->operand2.index_pointer = &new_indices[i][1];
				new_instr->operand2.count_pointer = &new_counts[i][1];
				new_ips[i] = (int8_t *) new_instr;
			}
			qb_dispatch_instruction_to_threads(cxt, control_func, new_ips, thread_count);
			return TRUE;
		}
	}
	return FALSE;
}

int32_t qb_dispatch_instruction_ARR_ARR_ARR(qb_interpreter_context *__restrict cxt, void *control_func, qb_instruction_ARR_ARR_ARR *__restrict instr, uint32_t operand1_size, uint32_t operand2_size, uint32_t operand3_size, uint32_t threshold) {
	int32_t use_multithreading = TRUE;
	uint32_t op3_count = instr->operand3.count_pointer[0];
	if(op3_count >= threshold * operand3_size) {
		USE_TSRM
		uint32_t res_unit_count = op3_count / operand3_size;
		uint32_t thread_count = (cxt->thread_count * threshold <= res_unit_count) ? cxt->thread_count : res_unit_count / threshold + 1;
		uint32_t chunk_size = res_unit_count / thread_count;
		uint32_t op1_count = instr->operand1.count_pointer[0], op1_unit_count = op1_count / operand1_size, op1_shift, op1_chunk_size;
		uint32_t op2_count = instr->operand2.count_pointer[0], op2_unit_count = op2_count / operand2_size, op2_shift, op2_chunk_size;
		uint32_t op3_shift = operand3_size * chunk_size, op3_chunk_size = operand3_size * chunk_size;
		if(op1_unit_count == res_unit_count) {
			op1_shift = operand1_size * chunk_size;
			op1_chunk_size = operand1_size * chunk_size;
		} else if(op1_unit_count == 1) {
			op1_shift = 0;
			op1_chunk_size = operand1_size;
		} else {
			use_multithreading = FALSE;
		}
		if(op2_unit_count == res_unit_count) {
			op2_shift = operand2_size * chunk_size;
			op2_chunk_size = operand2_size * chunk_size;
		} else if(op2_unit_count == 1) {
			op2_shift = 0;
			op2_chunk_size = operand2_size;
		} else {
			use_multithreading = FALSE;
		}
		if(use_multithreading) {
			// create temporary instruction structures
			qb_instruction_ARR_ARR_ARR new_instr_list[MAX_THREAD_COUNT];
			uint32_t new_indices[MAX_THREAD_COUNT][3];
			uint32_t new_counts[MAX_THREAD_COUNT][3];
			int8_t *new_ips[MAX_THREAD_COUNT];
			uint32_t i;
			for(i = 0; i < thread_count; i++) {
				qb_instruction_ARR_ARR_ARR *new_instr = &new_instr_list[i];
				new_indices[i][0] = i * op1_shift;
				new_counts[i][0] = (i == thread_count - 1) ? op1_count - (i * op1_shift) : op1_chunk_size;
				new_instr->operand1.data_pointer = instr->operand1.data_pointer;
				new_instr->operand1.index_pointer = &new_indices[i][0];
				new_instr->operand1.count_pointer = &new_counts[i][0];
				new_indices[i][1] = i * op2_shift;
				new_counts[i][1] = (i == thread_count - 1) ? op2_count - (i * op2_shift) : op2_chunk_size;
				new_instr->operand2.data_pointer = instr->operand2.data_pointer;
				new_instr->operand2.index_pointer = &new_indices[i][1];
				new_instr->operand2.count_pointer = &new_counts[i][1];
				new_indices[i][2] = i * op3_shift;
				new_counts[i][2] = (i == thread_count - 1) ? op3_count - (i * op3_shift) : op3_chunk_size;
				new_instr->operand3.data_pointer = instr->operand3.data_pointer;
				new_instr->operand3.index_pointer = &new_indices[i][2];
				new_instr->operand3.count_pointer = &new_counts[i][2];
				new_ips[i] = (int8_t *) new_instr;
			}
			qb_dispatch_instruction_to_threads(cxt, control_func, new_ips, thread_count);
			return TRUE;
		}
	}
	return FALSE;
}

int32_t qb_dispatch_instruction_ARR_ARR_SCA_SCA_ARR(qb_interpreter_context *__restrict cxt, void *control_func, qb_instruction_ARR_ARR_SCA_SCA_ARR *__restrict instr, uint32_t operand1_size, uint32_t operand2_size, uint32_t operand5_size, uint32_t threshold) {
	int32_t use_multithreading = TRUE;
	uint32_t op5_count = instr->operand5.count_pointer[0];
	if(op5_count >= threshold * operand5_size) {
		USE_TSRM
		uint32_t res_unit_count = op5_count / operand5_size;
		uint32_t thread_count = (cxt->thread_count * threshold <= res_unit_count) ? cxt->thread_count : res_unit_count / threshold + 1;
		uint32_t chunk_size = res_unit_count / thread_count;
		uint32_t op1_count = instr->operand1.count_pointer[0], op1_unit_count = op1_count / operand1_size, op1_shift, op1_chunk_size;
		uint32_t op2_count = instr->operand2.count_pointer[0], op2_unit_count = op2_count / operand2_size, op2_shift, op2_chunk_size;
		uint32_t op5_shift = operand5_size * chunk_size, op5_chunk_size = operand5_size * chunk_size;
		if(op1_unit_count == res_unit_count) {
			op1_shift = operand1_size * chunk_size;
			op1_chunk_size = operand1_size * chunk_size;
		} else if(op1_unit_count == 1) {
			op1_shift = 0;
			op1_chunk_size = operand1_size;
		} else {
			use_multithreading = FALSE;
		}
		if(op2_unit_count == res_unit_count) {
			op2_shift = operand2_size * chunk_size;
			op2_chunk_size = operand2_size * chunk_size;
		} else if(op2_unit_count == 1) {
			op2_shift = 0;
			op2_chunk_size = operand2_size;
		} else {
			use_multithreading = FALSE;
		}
		if(use_multithreading) {
			// create temporary instruction structures
			qb_instruction_ARR_ARR_SCA_SCA_ARR new_instr_list[MAX_THREAD_COUNT];
			uint32_t new_indices[MAX_THREAD_COUNT][3];
			uint32_t new_counts[MAX_THREAD_COUNT][3];
			int8_t *new_ips[MAX_THREAD_COUNT];
			uint32_t i;
			for(i = 0; i < thread_count; i++) {
				qb_instruction_ARR_ARR_SCA_SCA_ARR *new_instr = &new_instr_list[i];
				new_indices[i][0] = i * op1_shift;
				new_counts[i][0] = (i == thread_count - 1) ? op1_count - (i * op1_shift) : op1_chunk_size;
				new_instr->operand1.data_pointer = instr->operand1.data_pointer;
				new_instr->operand1.index_pointer = &new_indices[i][0];
				new_instr->operand1.count_pointer = &new_counts[i][0];
				new_indices[i][1] = i * op2_shift;
				new_counts[i][1] = (i == thread_count - 1) ? op2_count - (i * op2_shift) : op2_chunk_size;
				new_instr->operand2.data_pointer = instr->operand2.data_pointer;
				new_instr->operand2.index_pointer = &new_indices[i][1];
				new_instr->operand2.count_pointer = &new_counts[i][1];
				new_instr->operand3 = instr->operand3;
				new_instr->operand4 = instr->operand4;
				new_indices[i][2] = i * op5_shift;
				new_counts[i][2] = (i == thread_count - 1) ? op5_count - (i * op5_shift) : op5_chunk_size;
				new_instr->operand5.data_pointer = instr->operand5.data_pointer;
				new_instr->operand5.index_pointer = &new_indices[i][2];
				new_instr->operand5.count_pointer = &new_counts[i][2];
				new_ips[i] = (int8_t *) new_instr;
			}
			qb_dispatch_instruction_to_threads(cxt, control_func, new_ips, thread_count);
			return TRUE;
		}
	}
	return FALSE;
}


qb_native_symbol global_native_symbols[] = {
	{	"_fpclass",	_fpclass,	0,	0	},
	{	"_isnan",	_isnan,	0,	0	},
	{	"_finite",	_finite,	0,	0	},
	{	"fmodf",	fmodf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"hypotf",	hypotf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"fabsf",	fabsf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"floorf",	floorf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"ceilf",	ceilf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"sqrtf",	sqrtf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"powf",	powf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"log2f",	log2f,	0,	0	},
	{	"log10f",	log10f,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"log1pf",	log1pf,	0,	0	},
	{	"logf",	logf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"exp2f",	exp2f,	0,	0	},
	{	"expm1f",	expm1f,	0,	0	},
	{	"expf",	expf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atanhf",	atanhf,	0,	0	},
	{	"tanhf",	tanhf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"acoshf",	acoshf,	0,	0	},
	{	"coshf",	coshf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"asinhf",	asinhf,	0,	0	},
	{	"sinhf",	sinhf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atan2f",	atan2f,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atanf",	atanf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"tanf",	tanf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"acosf",	acosf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"cosf",	cosf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"asinf",	asinf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"sinf",	sinf,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_byteswap_uint64",	_byteswap_uint64,	0,	0	},
	{	"_byteswap_ulong",	_byteswap_ulong,	0,	0	},
	{	"_byteswap_ushort",	_byteswap_ushort,	0,	0	},
	{	"zend_strtod",	zend_strtod,	0,	0	},
	{	"strtoull",	strtoull,	0,	0	},
	{	"strtoul",	strtoul,	0,	0	},
	{	"strtoll",	strtoll,	0,	0	},
	{	"strtol",	strtol,	0,	0	},
	{	"qb_report_not_square_matrix_exception",	qb_report_not_square_matrix_exception,	0,	0	},
	{	"qb_report_invalid_matrix_multiplication_exception",	qb_report_invalid_matrix_multiplication_exception,	0,	0	},
	{	"qb_report_invalid_transform_exception",	qb_report_invalid_transform_exception,	0,	0	},
	{	"qb_report_invalid_4d_cross_product_exception",	qb_report_invalid_4d_cross_product_exception,	0,	0	},
	{	"qb_report_invalid_cross_product_exception",	qb_report_invalid_cross_product_exception,	0,	0	},
	{	"qb_report_vector_width_mismatch_exception",	qb_report_vector_width_mismatch_exception,	0,	0	},
	{	"qb_report_divide_by_zero_exception",	qb_report_divide_by_zero_exception,	0,	0	},
	{	"qb_report_missing_column_exception",	qb_report_missing_column_exception,	0,	0	},
	{	"qb_report_out_of_bound_exception",	qb_report_out_of_bound_exception,	0,	0	},
	{	"qb_dispatch_instruction_to_main_thread",	qb_dispatch_instruction_to_main_thread,	0,	0	},
	{	"qb_dispatch_instruction_to_threads",	qb_dispatch_instruction_to_threads,	0,	0	},
	{	"qb_fast_sqrt",	qb_fast_sqrt,	0,	0	},
	{	"qb_fast_sqrtf",	qb_fast_sqrtf,	0,	0	},
	{	"qb_fast_rsqrt",	qb_fast_rsqrt,	0,	0	},
	{	"qb_fast_rsqrtf",	qb_fast_rsqrtf,	0,	0	},
	{	"qb_run_zend_extension_op",	qb_run_zend_extension_op,	0,	0	},
	{	"qb_resize_segment",	qb_resize_segment,	0,	0	},
	{	"qb_dispatch_function_call",	qb_dispatch_function_call,	0,	0	},
	{	"php_write",	php_write,	0,	0	},
	{	"llabs",	llabs,	0,	0	},
	{	"abs",	abs,	0,	0	},
	{	"_php_math_round",	_php_math_round,	0,	0	},
	{	"php_combined_lcg",	php_combined_lcg,	0,	0	},
	{	"fmod",	fmod,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"hypot",	hypot,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"fabs",	fabs,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"floor",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"ceil",	ceil,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"sqrt",	sqrt,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"pow",	pow,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"log2",	log2,	0,	0	},
	{	"log10",	log10,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"log1p",	log1p,	0,	0	},
	{	"log",	log,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"exp2",	exp2,	0,	0	},
	{	"expm1",	expm1,	0,	0	},
	{	"exp",	exp,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atanh",	atanh,	0,	0	},
	{	"tanh",	tanh,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"acosh",	acosh,	0,	0	},
	{	"cosh",	cosh,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"asinh",	asinh,	0,	0	},
	{	"sinh",	sinh,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atan2",	atan2,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"atan",	atan,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"tan",	tan,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"acos",	acos,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"cos",	cos,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"asin",	asin,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"sin",	sin,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"memmove",	memmove,	0,	0	},
	{	"memcpy",	memcpy,	0,	0	},
	{	"qb_compare_ascending_F32",	qb_compare_ascending_F32,	0,	0	},
	{	"qb_compare_ascending_F32_array",	qb_compare_ascending_F32_array,	0,	0	},
	{	"qb_compare_ascending_F64",	qb_compare_ascending_F64,	0,	0	},
	{	"qb_compare_ascending_F64_array",	qb_compare_ascending_F64_array,	0,	0	},
	{	"qb_compare_ascending_S08",	qb_compare_ascending_S08,	0,	0	},
	{	"qb_compare_ascending_S08_array",	qb_compare_ascending_S08_array,	0,	0	},
	{	"qb_compare_ascending_S16",	qb_compare_ascending_S16,	0,	0	},
	{	"qb_compare_ascending_S16_array",	qb_compare_ascending_S16_array,	0,	0	},
	{	"qb_compare_ascending_S32",	qb_compare_ascending_S32,	0,	0	},
	{	"qb_compare_ascending_S32_array",	qb_compare_ascending_S32_array,	0,	0	},
	{	"qb_compare_ascending_S64",	qb_compare_ascending_S64,	0,	0	},
	{	"qb_compare_ascending_S64_array",	qb_compare_ascending_S64_array,	0,	0	},
	{	"qb_compare_ascending_U08",	qb_compare_ascending_U08,	0,	0	},
	{	"qb_compare_ascending_U08_array",	qb_compare_ascending_U08_array,	0,	0	},
	{	"qb_compare_ascending_U16",	qb_compare_ascending_U16,	0,	0	},
	{	"qb_compare_ascending_U16_array",	qb_compare_ascending_U16_array,	0,	0	},
	{	"qb_compare_ascending_U32",	qb_compare_ascending_U32,	0,	0	},
	{	"qb_compare_ascending_U32_array",	qb_compare_ascending_U32_array,	0,	0	},
	{	"qb_compare_ascending_U64",	qb_compare_ascending_U64,	0,	0	},
	{	"qb_compare_ascending_U64_array",	qb_compare_ascending_U64_array,	0,	0	},
	{	"qb_compare_descending_F32",	qb_compare_descending_F32,	0,	0	},
	{	"qb_compare_descending_F32_array",	qb_compare_descending_F32_array,	0,	0	},
	{	"qb_compare_descending_F64",	qb_compare_descending_F64,	0,	0	},
	{	"qb_compare_descending_F64_array",	qb_compare_descending_F64_array,	0,	0	},
	{	"qb_compare_descending_S08",	qb_compare_descending_S08,	0,	0	},
	{	"qb_compare_descending_S08_array",	qb_compare_descending_S08_array,	0,	0	},
	{	"qb_compare_descending_S16",	qb_compare_descending_S16,	0,	0	},
	{	"qb_compare_descending_S16_array",	qb_compare_descending_S16_array,	0,	0	},
	{	"qb_compare_descending_S32",	qb_compare_descending_S32,	0,	0	},
	{	"qb_compare_descending_S32_array",	qb_compare_descending_S32_array,	0,	0	},
	{	"qb_compare_descending_S64",	qb_compare_descending_S64,	0,	0	},
	{	"qb_compare_descending_S64_array",	qb_compare_descending_S64_array,	0,	0	},
	{	"qb_compare_descending_U08",	qb_compare_descending_U08,	0,	0	},
	{	"qb_compare_descending_U08_array",	qb_compare_descending_U08_array,	0,	0	},
	{	"qb_compare_descending_U16",	qb_compare_descending_U16,	0,	0	},
	{	"qb_compare_descending_U16_array",	qb_compare_descending_U16_array,	0,	0	},
	{	"qb_compare_descending_U32",	qb_compare_descending_U32,	0,	0	},
	{	"qb_compare_descending_U32_array",	qb_compare_descending_U32_array,	0,	0	},
	{	"qb_compare_descending_U64",	qb_compare_descending_U64,	0,	0	},
	{	"qb_compare_descending_U64_array",	qb_compare_descending_U64_array,	0,	0	},
	{	"qb_compare_array_F32",	qb_compare_array_F32,	0,	0	},
	{	"qb_compare_array_F64",	qb_compare_array_F64,	0,	0	},
	{	"qb_compare_array_S08",	qb_compare_array_S08,	0,	0	},
	{	"qb_compare_array_S16",	qb_compare_array_S16,	0,	0	},
	{	"qb_compare_array_S32",	qb_compare_array_S32,	0,	0	},
	{	"qb_compare_array_S64",	qb_compare_array_S64,	0,	0	},
	{	"qb_compare_array_U08",	qb_compare_array_U08,	0,	0	},
	{	"qb_compare_array_U16",	qb_compare_array_U16,	0,	0	},
	{	"qb_compare_array_U32",	qb_compare_array_U32,	0,	0	},
	{	"qb_compare_array_U64",	qb_compare_array_U64,	0,	0	},
	{	"qb_convert_hsl_to_rgb_F32",	qb_convert_hsl_to_rgb_F32,	0,	0	},
	{	"qb_convert_hsl_to_rgb_F64",	qb_convert_hsl_to_rgb_F64,	0,	0	},
	{	"qb_convert_hsv_to_rgb_F32",	qb_convert_hsv_to_rgb_F32,	0,	0	},
	{	"qb_convert_hsv_to_rgb_F64",	qb_convert_hsv_to_rgb_F64,	0,	0	},
	{	"qb_convert_rgb_to_hsl_F32",	qb_convert_rgb_to_hsl_F32,	0,	0	},
	{	"qb_convert_rgb_to_hsl_F64",	qb_convert_rgb_to_hsl_F64,	0,	0	},
	{	"qb_convert_rgb_to_hsv_F32",	qb_convert_rgb_to_hsv_F32,	0,	0	},
	{	"qb_convert_rgb_to_hsv_F64",	qb_convert_rgb_to_hsv_F64,	0,	0	},
	{	"qb_relocate_elements_F32",	qb_relocate_elements_F32,	0,	0	},
	{	"qb_relocate_elements_F64",	qb_relocate_elements_F64,	0,	0	},
	{	"qb_relocate_elements_I08",	qb_relocate_elements_I08,	0,	0	},
	{	"qb_relocate_elements_I16",	qb_relocate_elements_I16,	0,	0	},
	{	"qb_relocate_elements_I32",	qb_relocate_elements_I32,	0,	0	},
	{	"qb_relocate_elements_I64",	qb_relocate_elements_I64,	0,	0	},
	{	"qb_do_array_column_F32",	qb_do_array_column_F32,	0,	0	},
	{	"qb_do_array_column_F64",	qb_do_array_column_F64,	0,	0	},
	{	"qb_do_array_column_I08",	qb_do_array_column_I08,	0,	0	},
	{	"qb_do_array_column_I16",	qb_do_array_column_I16,	0,	0	},
	{	"qb_do_array_column_I32",	qb_do_array_column_I32,	0,	0	},
	{	"qb_do_array_column_I64",	qb_do_array_column_I64,	0,	0	},
	{	"qb_do_divide_multiple_times_S08",	qb_do_divide_multiple_times_S08,	0,	0	},
	{	"qb_do_divide_multiple_times_S16",	qb_do_divide_multiple_times_S16,	0,	0	},
	{	"qb_do_divide_multiple_times_S32",	qb_do_divide_multiple_times_S32,	0,	0	},
	{	"qb_do_divide_multiple_times_S64",	qb_do_divide_multiple_times_S64,	0,	0	},
	{	"qb_do_divide_multiple_times_U08",	qb_do_divide_multiple_times_U08,	0,	0	},
	{	"qb_do_divide_multiple_times_U16",	qb_do_divide_multiple_times_U16,	0,	0	},
	{	"qb_do_divide_multiple_times_U32",	qb_do_divide_multiple_times_U32,	0,	0	},
	{	"qb_do_divide_multiple_times_U64",	qb_do_divide_multiple_times_U64,	0,	0	},
	{	"qb_do_modulo_multiple_times_S08",	qb_do_modulo_multiple_times_S08,	0,	0	},
	{	"qb_do_modulo_multiple_times_S16",	qb_do_modulo_multiple_times_S16,	0,	0	},
	{	"qb_do_modulo_multiple_times_S32",	qb_do_modulo_multiple_times_S32,	0,	0	},
	{	"qb_do_modulo_multiple_times_S64",	qb_do_modulo_multiple_times_S64,	0,	0	},
	{	"qb_do_modulo_multiple_times_U08",	qb_do_modulo_multiple_times_U08,	0,	0	},
	{	"qb_do_modulo_multiple_times_U16",	qb_do_modulo_multiple_times_U16,	0,	0	},
	{	"qb_do_modulo_multiple_times_U32",	qb_do_modulo_multiple_times_U32,	0,	0	},
	{	"qb_do_modulo_multiple_times_U64",	qb_do_modulo_multiple_times_U64,	0,	0	},
	{	"qb_do_abs_multiple_times_F32",	qb_do_abs_multiple_times_F32,	0,	0	},
	{	"qb_do_abs_multiple_times_F64",	qb_do_abs_multiple_times_F64,	0,	0	},
	{	"qb_do_abs_multiple_times_S08",	qb_do_abs_multiple_times_S08,	0,	0	},
	{	"qb_do_abs_multiple_times_S16",	qb_do_abs_multiple_times_S16,	0,	0	},
	{	"qb_do_abs_multiple_times_S32",	qb_do_abs_multiple_times_S32,	0,	0	},
	{	"qb_do_abs_multiple_times_S64",	qb_do_abs_multiple_times_S64,	0,	0	},
	{	"qb_do_accommodate_size_copy_dimension_8_U32",	qb_do_accommodate_size_copy_dimension_8_U32,	0,	0	},
	{	"qb_do_acos_multiple_times_F32",	qb_do_acos_multiple_times_F32,	0,	0	},
	{	"qb_do_acos_multiple_times_F64",	qb_do_acos_multiple_times_F64,	0,	0	},
	{	"qb_do_acosh_multiple_times_F32",	qb_do_acosh_multiple_times_F32,	0,	0	},
	{	"qb_do_acosh_multiple_times_F64",	qb_do_acosh_multiple_times_F64,	0,	0	},
	{	"qb_do_add_2x_multiple_times_F32",	qb_do_add_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_add_2x_multiple_times_F64",	qb_do_add_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_add_3x_multiple_times_F32",	qb_do_add_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_add_3x_multiple_times_F64",	qb_do_add_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_add_4x_multiple_times_F32",	qb_do_add_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_add_4x_multiple_times_F64",	qb_do_add_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_add_multiple_times_F32",	qb_do_add_multiple_times_F32,	0,	0	},
	{	"qb_do_add_multiple_times_F64",	qb_do_add_multiple_times_F64,	0,	0	},
	{	"qb_do_add_multiple_times_I08",	qb_do_add_multiple_times_I08,	0,	0	},
	{	"qb_do_add_multiple_times_I16",	qb_do_add_multiple_times_I16,	0,	0	},
	{	"qb_do_add_multiple_times_I32",	qb_do_add_multiple_times_I32,	0,	0	},
	{	"qb_do_add_multiple_times_I64",	qb_do_add_multiple_times_I64,	0,	0	},
	{	"qb_do_alpha_blend_2x_F32",	qb_do_alpha_blend_2x_F32,	0,	0	},
	{	"qb_do_alpha_blend_2x_F64",	qb_do_alpha_blend_2x_F64,	0,	0	},
	{	"qb_do_alpha_blend_2x_multiple_times_F32",	qb_do_alpha_blend_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_alpha_blend_2x_multiple_times_F64",	qb_do_alpha_blend_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_alpha_blend_4x_F32",	qb_do_alpha_blend_4x_F32,	0,	0	},
	{	"qb_do_alpha_blend_4x_F64",	qb_do_alpha_blend_4x_F64,	0,	0	},
	{	"qb_do_alpha_blend_4x_multiple_times_F32",	qb_do_alpha_blend_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_alpha_blend_4x_multiple_times_F64",	qb_do_alpha_blend_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_append_multidimensional_variable_F32",	qb_do_append_multidimensional_variable_F32,	0,	0	},
	{	"qb_do_append_multidimensional_variable_F64",	qb_do_append_multidimensional_variable_F64,	0,	0	},
	{	"qb_do_append_multidimensional_variable_S08",	qb_do_append_multidimensional_variable_S08,	0,	0	},
	{	"qb_do_append_multidimensional_variable_S16",	qb_do_append_multidimensional_variable_S16,	0,	0	},
	{	"qb_do_append_multidimensional_variable_S32",	qb_do_append_multidimensional_variable_S32,	0,	0	},
	{	"qb_do_append_multidimensional_variable_S64",	qb_do_append_multidimensional_variable_S64,	0,	0	},
	{	"qb_do_append_multidimensional_variable_U08",	qb_do_append_multidimensional_variable_U08,	0,	0	},
	{	"qb_do_append_multidimensional_variable_U16",	qb_do_append_multidimensional_variable_U16,	0,	0	},
	{	"qb_do_append_multidimensional_variable_U32",	qb_do_append_multidimensional_variable_U32,	0,	0	},
	{	"qb_do_append_multidimensional_variable_U64",	qb_do_append_multidimensional_variable_U64,	0,	0	},
	{	"qb_do_append_string_U08",	qb_do_append_string_U08,	0,	0	},
	{	"qb_do_append_variable_F32",	qb_do_append_variable_F32,	0,	0	},
	{	"qb_do_append_variable_F64",	qb_do_append_variable_F64,	0,	0	},
	{	"qb_do_append_variable_S08",	qb_do_append_variable_S08,	0,	0	},
	{	"qb_do_append_variable_S16",	qb_do_append_variable_S16,	0,	0	},
	{	"qb_do_append_variable_S32",	qb_do_append_variable_S32,	0,	0	},
	{	"qb_do_append_variable_S64",	qb_do_append_variable_S64,	0,	0	},
	{	"qb_do_append_variable_U08",	qb_do_append_variable_U08,	0,	0	},
	{	"qb_do_append_variable_U16",	qb_do_append_variable_U16,	0,	0	},
	{	"qb_do_append_variable_U32",	qb_do_append_variable_U32,	0,	0	},
	{	"qb_do_append_variable_U64",	qb_do_append_variable_U64,	0,	0	},
	{	"qb_do_append_variable_multiple_times_F32",	qb_do_append_variable_multiple_times_F32,	0,	0	},
	{	"qb_do_append_variable_multiple_times_F64",	qb_do_append_variable_multiple_times_F64,	0,	0	},
	{	"qb_do_append_variable_multiple_times_S08",	qb_do_append_variable_multiple_times_S08,	0,	0	},
	{	"qb_do_append_variable_multiple_times_S16",	qb_do_append_variable_multiple_times_S16,	0,	0	},
	{	"qb_do_append_variable_multiple_times_S32",	qb_do_append_variable_multiple_times_S32,	0,	0	},
	{	"qb_do_append_variable_multiple_times_S64",	qb_do_append_variable_multiple_times_S64,	0,	0	},
	{	"qb_do_append_variable_multiple_times_U08",	qb_do_append_variable_multiple_times_U08,	0,	0	},
	{	"qb_do_append_variable_multiple_times_U16",	qb_do_append_variable_multiple_times_U16,	0,	0	},
	{	"qb_do_append_variable_multiple_times_U32",	qb_do_append_variable_multiple_times_U32,	0,	0	},
	{	"qb_do_append_variable_multiple_times_U64",	qb_do_append_variable_multiple_times_U64,	0,	0	},
	{	"qb_do_apply_premultiplication_4x_multiple_times_F32",	qb_do_apply_premultiplication_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_apply_premultiplication_4x_multiple_times_F64",	qb_do_apply_premultiplication_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_array_difference_F32",	qb_do_array_difference_F32,	0,	0	},
	{	"qb_do_array_difference_F64",	qb_do_array_difference_F64,	0,	0	},
	{	"qb_do_array_difference_I08",	qb_do_array_difference_I08,	0,	0	},
	{	"qb_do_array_difference_I16",	qb_do_array_difference_I16,	0,	0	},
	{	"qb_do_array_difference_I32",	qb_do_array_difference_I32,	0,	0	},
	{	"qb_do_array_difference_I64",	qb_do_array_difference_I64,	0,	0	},
	{	"qb_do_array_difference_count_F32",	qb_do_array_difference_count_F32,	0,	0	},
	{	"qb_do_array_difference_count_F64",	qb_do_array_difference_count_F64,	0,	0	},
	{	"qb_do_array_difference_count_I08",	qb_do_array_difference_count_I08,	0,	0	},
	{	"qb_do_array_difference_count_I16",	qb_do_array_difference_count_I16,	0,	0	},
	{	"qb_do_array_difference_count_I32",	qb_do_array_difference_count_I32,	0,	0	},
	{	"qb_do_array_difference_count_I64",	qb_do_array_difference_count_I64,	0,	0	},
	{	"qb_do_array_fill_F32",	qb_do_array_fill_F32,	0,	0	},
	{	"qb_do_array_fill_F64",	qb_do_array_fill_F64,	0,	0	},
	{	"qb_do_array_fill_I08",	qb_do_array_fill_I08,	0,	0	},
	{	"qb_do_array_fill_I16",	qb_do_array_fill_I16,	0,	0	},
	{	"qb_do_array_fill_I32",	qb_do_array_fill_I32,	0,	0	},
	{	"qb_do_array_fill_I64",	qb_do_array_fill_I64,	0,	0	},
	{	"qb_do_array_fill_multiple_times_F32",	qb_do_array_fill_multiple_times_F32,	0,	0	},
	{	"qb_do_array_fill_multiple_times_F64",	qb_do_array_fill_multiple_times_F64,	0,	0	},
	{	"qb_do_array_fill_multiple_times_I08",	qb_do_array_fill_multiple_times_I08,	0,	0	},
	{	"qb_do_array_fill_multiple_times_I16",	qb_do_array_fill_multiple_times_I16,	0,	0	},
	{	"qb_do_array_fill_multiple_times_I32",	qb_do_array_fill_multiple_times_I32,	0,	0	},
	{	"qb_do_array_fill_multiple_times_I64",	qb_do_array_fill_multiple_times_I64,	0,	0	},
	{	"qb_do_array_intersect_F32",	qb_do_array_intersect_F32,	0,	0	},
	{	"qb_do_array_intersect_F64",	qb_do_array_intersect_F64,	0,	0	},
	{	"qb_do_array_intersect_I08",	qb_do_array_intersect_I08,	0,	0	},
	{	"qb_do_array_intersect_I16",	qb_do_array_intersect_I16,	0,	0	},
	{	"qb_do_array_intersect_I32",	qb_do_array_intersect_I32,	0,	0	},
	{	"qb_do_array_intersect_I64",	qb_do_array_intersect_I64,	0,	0	},
	{	"qb_do_array_intersect_count_F32",	qb_do_array_intersect_count_F32,	0,	0	},
	{	"qb_do_array_intersect_count_F64",	qb_do_array_intersect_count_F64,	0,	0	},
	{	"qb_do_array_intersect_count_I08",	qb_do_array_intersect_count_I08,	0,	0	},
	{	"qb_do_array_intersect_count_I16",	qb_do_array_intersect_count_I16,	0,	0	},
	{	"qb_do_array_intersect_count_I32",	qb_do_array_intersect_count_I32,	0,	0	},
	{	"qb_do_array_intersect_count_I64",	qb_do_array_intersect_count_I64,	0,	0	},
	{	"qb_do_array_max_F32",	qb_do_array_max_F32,	0,	0	},
	{	"qb_do_array_max_F64",	qb_do_array_max_F64,	0,	0	},
	{	"qb_do_array_max_S08",	qb_do_array_max_S08,	0,	0	},
	{	"qb_do_array_max_S16",	qb_do_array_max_S16,	0,	0	},
	{	"qb_do_array_max_S32",	qb_do_array_max_S32,	0,	0	},
	{	"qb_do_array_max_S64",	qb_do_array_max_S64,	0,	0	},
	{	"qb_do_array_max_U08",	qb_do_array_max_U08,	0,	0	},
	{	"qb_do_array_max_U16",	qb_do_array_max_U16,	0,	0	},
	{	"qb_do_array_max_U32",	qb_do_array_max_U32,	0,	0	},
	{	"qb_do_array_max_U64",	qb_do_array_max_U64,	0,	0	},
	{	"qb_do_array_min_F32",	qb_do_array_min_F32,	0,	0	},
	{	"qb_do_array_min_F64",	qb_do_array_min_F64,	0,	0	},
	{	"qb_do_array_min_S08",	qb_do_array_min_S08,	0,	0	},
	{	"qb_do_array_min_S16",	qb_do_array_min_S16,	0,	0	},
	{	"qb_do_array_min_S32",	qb_do_array_min_S32,	0,	0	},
	{	"qb_do_array_min_S64",	qb_do_array_min_S64,	0,	0	},
	{	"qb_do_array_min_U08",	qb_do_array_min_U08,	0,	0	},
	{	"qb_do_array_min_U16",	qb_do_array_min_U16,	0,	0	},
	{	"qb_do_array_min_U32",	qb_do_array_min_U32,	0,	0	},
	{	"qb_do_array_min_U64",	qb_do_array_min_U64,	0,	0	},
	{	"qb_do_array_pad_F32",	qb_do_array_pad_F32,	0,	0	},
	{	"qb_do_array_pad_F64",	qb_do_array_pad_F64,	0,	0	},
	{	"qb_do_array_pad_I08",	qb_do_array_pad_I08,	0,	0	},
	{	"qb_do_array_pad_I16",	qb_do_array_pad_I16,	0,	0	},
	{	"qb_do_array_pad_I32",	qb_do_array_pad_I32,	0,	0	},
	{	"qb_do_array_pad_I64",	qb_do_array_pad_I64,	0,	0	},
	{	"qb_do_array_product_F32",	qb_do_array_product_F32,	0,	0	},
	{	"qb_do_array_product_F64",	qb_do_array_product_F64,	0,	0	},
	{	"qb_do_array_product_S08",	qb_do_array_product_S08,	0,	0	},
	{	"qb_do_array_product_S16",	qb_do_array_product_S16,	0,	0	},
	{	"qb_do_array_product_S32",	qb_do_array_product_S32,	0,	0	},
	{	"qb_do_array_product_S64",	qb_do_array_product_S64,	0,	0	},
	{	"qb_do_array_product_U08",	qb_do_array_product_U08,	0,	0	},
	{	"qb_do_array_product_U16",	qb_do_array_product_U16,	0,	0	},
	{	"qb_do_array_product_U32",	qb_do_array_product_U32,	0,	0	},
	{	"qb_do_array_product_U64",	qb_do_array_product_U64,	0,	0	},
	{	"qb_do_array_random_U32",	qb_do_array_random_U32,	0,	0	},
	{	"qb_do_array_replace_F32",	qb_do_array_replace_F32,	0,	0	},
	{	"qb_do_array_replace_F64",	qb_do_array_replace_F64,	0,	0	},
	{	"qb_do_array_replace_I08",	qb_do_array_replace_I08,	0,	0	},
	{	"qb_do_array_replace_I16",	qb_do_array_replace_I16,	0,	0	},
	{	"qb_do_array_replace_I32",	qb_do_array_replace_I32,	0,	0	},
	{	"qb_do_array_replace_I64",	qb_do_array_replace_I64,	0,	0	},
	{	"qb_do_array_resize_1_F32",	qb_do_array_resize_1_F32,	0,	0	},
	{	"qb_do_array_resize_1_F64",	qb_do_array_resize_1_F64,	0,	0	},
	{	"qb_do_array_resize_1_I08",	qb_do_array_resize_1_I08,	0,	0	},
	{	"qb_do_array_resize_1_I16",	qb_do_array_resize_1_I16,	0,	0	},
	{	"qb_do_array_resize_1_I32",	qb_do_array_resize_1_I32,	0,	0	},
	{	"qb_do_array_resize_1_I64",	qb_do_array_resize_1_I64,	0,	0	},
	{	"qb_do_array_resize_2_F32",	qb_do_array_resize_2_F32,	0,	0	},
	{	"qb_do_array_resize_2_F64",	qb_do_array_resize_2_F64,	0,	0	},
	{	"qb_do_array_resize_2_I08",	qb_do_array_resize_2_I08,	0,	0	},
	{	"qb_do_array_resize_2_I16",	qb_do_array_resize_2_I16,	0,	0	},
	{	"qb_do_array_resize_2_I32",	qb_do_array_resize_2_I32,	0,	0	},
	{	"qb_do_array_resize_2_I64",	qb_do_array_resize_2_I64,	0,	0	},
	{	"qb_do_array_resize_3_F32",	qb_do_array_resize_3_F32,	0,	0	},
	{	"qb_do_array_resize_3_F64",	qb_do_array_resize_3_F64,	0,	0	},
	{	"qb_do_array_resize_3_I08",	qb_do_array_resize_3_I08,	0,	0	},
	{	"qb_do_array_resize_3_I16",	qb_do_array_resize_3_I16,	0,	0	},
	{	"qb_do_array_resize_3_I32",	qb_do_array_resize_3_I32,	0,	0	},
	{	"qb_do_array_resize_3_I64",	qb_do_array_resize_3_I64,	0,	0	},
	{	"qb_do_array_resize_4_F32",	qb_do_array_resize_4_F32,	0,	0	},
	{	"qb_do_array_resize_4_F64",	qb_do_array_resize_4_F64,	0,	0	},
	{	"qb_do_array_resize_4_I08",	qb_do_array_resize_4_I08,	0,	0	},
	{	"qb_do_array_resize_4_I16",	qb_do_array_resize_4_I16,	0,	0	},
	{	"qb_do_array_resize_4_I32",	qb_do_array_resize_4_I32,	0,	0	},
	{	"qb_do_array_resize_4_I64",	qb_do_array_resize_4_I64,	0,	0	},
	{	"qb_do_array_resize_5_F32",	qb_do_array_resize_5_F32,	0,	0	},
	{	"qb_do_array_resize_5_F64",	qb_do_array_resize_5_F64,	0,	0	},
	{	"qb_do_array_resize_5_I08",	qb_do_array_resize_5_I08,	0,	0	},
	{	"qb_do_array_resize_5_I16",	qb_do_array_resize_5_I16,	0,	0	},
	{	"qb_do_array_resize_5_I32",	qb_do_array_resize_5_I32,	0,	0	},
	{	"qb_do_array_resize_5_I64",	qb_do_array_resize_5_I64,	0,	0	},
	{	"qb_do_array_resize_6_F32",	qb_do_array_resize_6_F32,	0,	0	},
	{	"qb_do_array_resize_6_F64",	qb_do_array_resize_6_F64,	0,	0	},
	{	"qb_do_array_resize_6_I08",	qb_do_array_resize_6_I08,	0,	0	},
	{	"qb_do_array_resize_6_I16",	qb_do_array_resize_6_I16,	0,	0	},
	{	"qb_do_array_resize_6_I32",	qb_do_array_resize_6_I32,	0,	0	},
	{	"qb_do_array_resize_6_I64",	qb_do_array_resize_6_I64,	0,	0	},
	{	"qb_do_array_resize_7_F32",	qb_do_array_resize_7_F32,	0,	0	},
	{	"qb_do_array_resize_7_F64",	qb_do_array_resize_7_F64,	0,	0	},
	{	"qb_do_array_resize_7_I08",	qb_do_array_resize_7_I08,	0,	0	},
	{	"qb_do_array_resize_7_I16",	qb_do_array_resize_7_I16,	0,	0	},
	{	"qb_do_array_resize_7_I32",	qb_do_array_resize_7_I32,	0,	0	},
	{	"qb_do_array_resize_7_I64",	qb_do_array_resize_7_I64,	0,	0	},
	{	"qb_do_array_resize_8_F32",	qb_do_array_resize_8_F32,	0,	0	},
	{	"qb_do_array_resize_8_F64",	qb_do_array_resize_8_F64,	0,	0	},
	{	"qb_do_array_resize_8_I08",	qb_do_array_resize_8_I08,	0,	0	},
	{	"qb_do_array_resize_8_I16",	qb_do_array_resize_8_I16,	0,	0	},
	{	"qb_do_array_resize_8_I32",	qb_do_array_resize_8_I32,	0,	0	},
	{	"qb_do_array_resize_8_I64",	qb_do_array_resize_8_I64,	0,	0	},
	{	"qb_do_array_reverse_F32",	qb_do_array_reverse_F32,	0,	0	},
	{	"qb_do_array_reverse_F64",	qb_do_array_reverse_F64,	0,	0	},
	{	"qb_do_array_reverse_I08",	qb_do_array_reverse_I08,	0,	0	},
	{	"qb_do_array_reverse_I16",	qb_do_array_reverse_I16,	0,	0	},
	{	"qb_do_array_reverse_I32",	qb_do_array_reverse_I32,	0,	0	},
	{	"qb_do_array_reverse_I64",	qb_do_array_reverse_I64,	0,	0	},
	{	"qb_do_array_search_F32",	qb_do_array_search_F32,	0,	0	},
	{	"qb_do_array_search_F64",	qb_do_array_search_F64,	0,	0	},
	{	"qb_do_array_search_I08",	qb_do_array_search_I08,	0,	0	},
	{	"qb_do_array_search_I16",	qb_do_array_search_I16,	0,	0	},
	{	"qb_do_array_search_I32",	qb_do_array_search_I32,	0,	0	},
	{	"qb_do_array_search_I64",	qb_do_array_search_I64,	0,	0	},
	{	"qb_do_array_search_multiple_times_F32",	qb_do_array_search_multiple_times_F32,	0,	0	},
	{	"qb_do_array_search_multiple_times_F64",	qb_do_array_search_multiple_times_F64,	0,	0	},
	{	"qb_do_array_search_multiple_times_I08",	qb_do_array_search_multiple_times_I08,	0,	0	},
	{	"qb_do_array_search_multiple_times_I16",	qb_do_array_search_multiple_times_I16,	0,	0	},
	{	"qb_do_array_search_multiple_times_I32",	qb_do_array_search_multiple_times_I32,	0,	0	},
	{	"qb_do_array_search_multiple_times_I64",	qb_do_array_search_multiple_times_I64,	0,	0	},
	{	"qb_do_array_slice_F32",	qb_do_array_slice_F32,	0,	0	},
	{	"qb_do_array_slice_F64",	qb_do_array_slice_F64,	0,	0	},
	{	"qb_do_array_slice_I08",	qb_do_array_slice_I08,	0,	0	},
	{	"qb_do_array_slice_I16",	qb_do_array_slice_I16,	0,	0	},
	{	"qb_do_array_slice_I32",	qb_do_array_slice_I32,	0,	0	},
	{	"qb_do_array_slice_I64",	qb_do_array_slice_I64,	0,	0	},
	{	"qb_do_array_slice_count_I32",	qb_do_array_slice_count_I32,	0,	0	},
	{	"qb_do_array_sum_F32",	qb_do_array_sum_F32,	0,	0	},
	{	"qb_do_array_sum_F64",	qb_do_array_sum_F64,	0,	0	},
	{	"qb_do_array_sum_S08",	qb_do_array_sum_S08,	0,	0	},
	{	"qb_do_array_sum_S16",	qb_do_array_sum_S16,	0,	0	},
	{	"qb_do_array_sum_S32",	qb_do_array_sum_S32,	0,	0	},
	{	"qb_do_array_sum_S64",	qb_do_array_sum_S64,	0,	0	},
	{	"qb_do_array_sum_U08",	qb_do_array_sum_U08,	0,	0	},
	{	"qb_do_array_sum_U16",	qb_do_array_sum_U16,	0,	0	},
	{	"qb_do_array_sum_U32",	qb_do_array_sum_U32,	0,	0	},
	{	"qb_do_array_sum_U64",	qb_do_array_sum_U64,	0,	0	},
	{	"qb_do_array_unique_F32",	qb_do_array_unique_F32,	0,	0	},
	{	"qb_do_array_unique_F64",	qb_do_array_unique_F64,	0,	0	},
	{	"qb_do_array_unique_I08",	qb_do_array_unique_I08,	0,	0	},
	{	"qb_do_array_unique_I16",	qb_do_array_unique_I16,	0,	0	},
	{	"qb_do_array_unique_I32",	qb_do_array_unique_I32,	0,	0	},
	{	"qb_do_array_unique_I64",	qb_do_array_unique_I64,	0,	0	},
	{	"qb_do_array_unique_count_F32",	qb_do_array_unique_count_F32,	0,	0	},
	{	"qb_do_array_unique_count_F64",	qb_do_array_unique_count_F64,	0,	0	},
	{	"qb_do_array_unique_count_I08",	qb_do_array_unique_count_I08,	0,	0	},
	{	"qb_do_array_unique_count_I16",	qb_do_array_unique_count_I16,	0,	0	},
	{	"qb_do_array_unique_count_I32",	qb_do_array_unique_count_I32,	0,	0	},
	{	"qb_do_array_unique_count_I64",	qb_do_array_unique_count_I64,	0,	0	},
	{	"qb_do_asin_multiple_times_F32",	qb_do_asin_multiple_times_F32,	0,	0	},
	{	"qb_do_asin_multiple_times_F64",	qb_do_asin_multiple_times_F64,	0,	0	},
	{	"qb_do_asinh_multiple_times_F32",	qb_do_asinh_multiple_times_F32,	0,	0	},
	{	"qb_do_asinh_multiple_times_F64",	qb_do_asinh_multiple_times_F64,	0,	0	},
	{	"qb_do_atan2_multiple_times_F32",	qb_do_atan2_multiple_times_F32,	0,	0	},
	{	"qb_do_atan2_multiple_times_F64",	qb_do_atan2_multiple_times_F64,	0,	0	},
	{	"qb_do_atan_multiple_times_F32",	qb_do_atan_multiple_times_F32,	0,	0	},
	{	"qb_do_atan_multiple_times_F64",	qb_do_atan_multiple_times_F64,	0,	0	},
	{	"qb_do_atanh_multiple_times_F32",	qb_do_atanh_multiple_times_F32,	0,	0	},
	{	"qb_do_atanh_multiple_times_F64",	qb_do_atanh_multiple_times_F64,	0,	0	},
	{	"qb_do_bitwise_and_multiple_times_I08",	qb_do_bitwise_and_multiple_times_I08,	0,	0	},
	{	"qb_do_bitwise_and_multiple_times_I16",	qb_do_bitwise_and_multiple_times_I16,	0,	0	},
	{	"qb_do_bitwise_and_multiple_times_I32",	qb_do_bitwise_and_multiple_times_I32,	0,	0	},
	{	"qb_do_bitwise_and_multiple_times_I64",	qb_do_bitwise_and_multiple_times_I64,	0,	0	},
	{	"qb_do_bitwise_not_multiple_times_I08",	qb_do_bitwise_not_multiple_times_I08,	0,	0	},
	{	"qb_do_bitwise_not_multiple_times_I16",	qb_do_bitwise_not_multiple_times_I16,	0,	0	},
	{	"qb_do_bitwise_not_multiple_times_I32",	qb_do_bitwise_not_multiple_times_I32,	0,	0	},
	{	"qb_do_bitwise_not_multiple_times_I64",	qb_do_bitwise_not_multiple_times_I64,	0,	0	},
	{	"qb_do_bitwise_or_multiple_times_I08",	qb_do_bitwise_or_multiple_times_I08,	0,	0	},
	{	"qb_do_bitwise_or_multiple_times_I16",	qb_do_bitwise_or_multiple_times_I16,	0,	0	},
	{	"qb_do_bitwise_or_multiple_times_I32",	qb_do_bitwise_or_multiple_times_I32,	0,	0	},
	{	"qb_do_bitwise_or_multiple_times_I64",	qb_do_bitwise_or_multiple_times_I64,	0,	0	},
	{	"qb_do_bitwise_xor_multiple_times_I08",	qb_do_bitwise_xor_multiple_times_I08,	0,	0	},
	{	"qb_do_bitwise_xor_multiple_times_I16",	qb_do_bitwise_xor_multiple_times_I16,	0,	0	},
	{	"qb_do_bitwise_xor_multiple_times_I32",	qb_do_bitwise_xor_multiple_times_I32,	0,	0	},
	{	"qb_do_bitwise_xor_multiple_times_I64",	qb_do_bitwise_xor_multiple_times_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_F64",	qb_do_cast_multiple_times_F32_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_S08",	qb_do_cast_multiple_times_F32_S08,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_S16",	qb_do_cast_multiple_times_F32_S16,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_S32",	qb_do_cast_multiple_times_F32_S32,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_S64",	qb_do_cast_multiple_times_F32_S64,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_U08",	qb_do_cast_multiple_times_F32_U08,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_U16",	qb_do_cast_multiple_times_F32_U16,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_U32",	qb_do_cast_multiple_times_F32_U32,	0,	0	},
	{	"qb_do_cast_multiple_times_F32_U64",	qb_do_cast_multiple_times_F32_U64,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_F32",	qb_do_cast_multiple_times_F64_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_S08",	qb_do_cast_multiple_times_F64_S08,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_S16",	qb_do_cast_multiple_times_F64_S16,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_S32",	qb_do_cast_multiple_times_F64_S32,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_S64",	qb_do_cast_multiple_times_F64_S64,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_U08",	qb_do_cast_multiple_times_F64_U08,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_U16",	qb_do_cast_multiple_times_F64_U16,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_U32",	qb_do_cast_multiple_times_F64_U32,	0,	0	},
	{	"qb_do_cast_multiple_times_F64_U64",	qb_do_cast_multiple_times_F64_U64,	0,	0	},
	{	"qb_do_cast_multiple_times_I16_I08",	qb_do_cast_multiple_times_I16_I08,	0,	0	},
	{	"qb_do_cast_multiple_times_I32_I08",	qb_do_cast_multiple_times_I32_I08,	0,	0	},
	{	"qb_do_cast_multiple_times_I32_I16",	qb_do_cast_multiple_times_I32_I16,	0,	0	},
	{	"qb_do_cast_multiple_times_I64_I08",	qb_do_cast_multiple_times_I64_I08,	0,	0	},
	{	"qb_do_cast_multiple_times_I64_I16",	qb_do_cast_multiple_times_I64_I16,	0,	0	},
	{	"qb_do_cast_multiple_times_I64_I32",	qb_do_cast_multiple_times_I64_I32,	0,	0	},
	{	"qb_do_cast_multiple_times_S08_F32",	qb_do_cast_multiple_times_S08_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_S08_F64",	qb_do_cast_multiple_times_S08_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_S08_I16",	qb_do_cast_multiple_times_S08_I16,	0,	0	},
	{	"qb_do_cast_multiple_times_S08_I32",	qb_do_cast_multiple_times_S08_I32,	0,	0	},
	{	"qb_do_cast_multiple_times_S08_I64",	qb_do_cast_multiple_times_S08_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_S16_F32",	qb_do_cast_multiple_times_S16_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_S16_F64",	qb_do_cast_multiple_times_S16_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_S16_I32",	qb_do_cast_multiple_times_S16_I32,	0,	0	},
	{	"qb_do_cast_multiple_times_S16_I64",	qb_do_cast_multiple_times_S16_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_S32_F32",	qb_do_cast_multiple_times_S32_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_S32_F64",	qb_do_cast_multiple_times_S32_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_S32_I64",	qb_do_cast_multiple_times_S32_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_S64_F32",	qb_do_cast_multiple_times_S64_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_S64_F64",	qb_do_cast_multiple_times_S64_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_U08_F32",	qb_do_cast_multiple_times_U08_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_U08_F64",	qb_do_cast_multiple_times_U08_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_U08_I16",	qb_do_cast_multiple_times_U08_I16,	0,	0	},
	{	"qb_do_cast_multiple_times_U08_I32",	qb_do_cast_multiple_times_U08_I32,	0,	0	},
	{	"qb_do_cast_multiple_times_U08_I64",	qb_do_cast_multiple_times_U08_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_U16_F32",	qb_do_cast_multiple_times_U16_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_U16_F64",	qb_do_cast_multiple_times_U16_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_U16_I32",	qb_do_cast_multiple_times_U16_I32,	0,	0	},
	{	"qb_do_cast_multiple_times_U16_I64",	qb_do_cast_multiple_times_U16_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_U32_F32",	qb_do_cast_multiple_times_U32_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_U32_F64",	qb_do_cast_multiple_times_U32_F64,	0,	0	},
	{	"qb_do_cast_multiple_times_U32_I64",	qb_do_cast_multiple_times_U32_I64,	0,	0	},
	{	"qb_do_cast_multiple_times_U64_F32",	qb_do_cast_multiple_times_U64_F32,	0,	0	},
	{	"qb_do_cast_multiple_times_U64_F64",	qb_do_cast_multiple_times_U64_F64,	0,	0	},
	{	"qb_do_ceil_multiple_times_F32",	qb_do_ceil_multiple_times_F32,	0,	0	},
	{	"qb_do_ceil_multiple_times_F64",	qb_do_ceil_multiple_times_F64,	0,	0	},
	{	"qb_do_choose_size_largest_of_three_U32",	qb_do_choose_size_largest_of_three_U32,	0,	0	},
	{	"qb_do_clamp_multiple_times_F32",	qb_do_clamp_multiple_times_F32,	0,	0	},
	{	"qb_do_clamp_multiple_times_F64",	qb_do_clamp_multiple_times_F64,	0,	0	},
	{	"qb_do_clear_array_resize_F32",	qb_do_clear_array_resize_F32,	0,	0	},
	{	"qb_do_clear_array_resize_F64",	qb_do_clear_array_resize_F64,	0,	0	},
	{	"qb_do_clear_array_resize_I08",	qb_do_clear_array_resize_I08,	0,	0	},
	{	"qb_do_clear_array_resize_I16",	qb_do_clear_array_resize_I16,	0,	0	},
	{	"qb_do_clear_array_resize_I32",	qb_do_clear_array_resize_I32,	0,	0	},
	{	"qb_do_clear_array_resize_I64",	qb_do_clear_array_resize_I64,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_F32",	qb_do_clear_array_resize_update_dimension_F32,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_F64",	qb_do_clear_array_resize_update_dimension_F64,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_I08",	qb_do_clear_array_resize_update_dimension_I08,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_I16",	qb_do_clear_array_resize_update_dimension_I16,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_I32",	qb_do_clear_array_resize_update_dimension_I32,	0,	0	},
	{	"qb_do_clear_array_resize_update_dimension_I64",	qb_do_clear_array_resize_update_dimension_I64,	0,	0	},
	{	"qb_do_clear_element_resize_F32",	qb_do_clear_element_resize_F32,	0,	0	},
	{	"qb_do_clear_element_resize_F64",	qb_do_clear_element_resize_F64,	0,	0	},
	{	"qb_do_clear_element_resize_I08",	qb_do_clear_element_resize_I08,	0,	0	},
	{	"qb_do_clear_element_resize_I16",	qb_do_clear_element_resize_I16,	0,	0	},
	{	"qb_do_clear_element_resize_I32",	qb_do_clear_element_resize_I32,	0,	0	},
	{	"qb_do_clear_element_resize_I64",	qb_do_clear_element_resize_I64,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_F32",	qb_do_clear_element_resize_update_dimension_F32,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_F64",	qb_do_clear_element_resize_update_dimension_F64,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_I08",	qb_do_clear_element_resize_update_dimension_I08,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_I16",	qb_do_clear_element_resize_update_dimension_I16,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_I32",	qb_do_clear_element_resize_update_dimension_I32,	0,	0	},
	{	"qb_do_clear_element_resize_update_dimension_I64",	qb_do_clear_element_resize_update_dimension_I64,	0,	0	},
	{	"qb_do_complex_abs_2x_F32",	qb_do_complex_abs_2x_F32,	0,	0	},
	{	"qb_do_complex_abs_2x_F64",	qb_do_complex_abs_2x_F64,	0,	0	},
	{	"qb_do_complex_abs_2x_multiple_times_F32",	qb_do_complex_abs_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_abs_2x_multiple_times_F64",	qb_do_complex_abs_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_argument_2x_F32",	qb_do_complex_argument_2x_F32,	0,	0	},
	{	"qb_do_complex_argument_2x_F64",	qb_do_complex_argument_2x_F64,	0,	0	},
	{	"qb_do_complex_argument_2x_multiple_times_F32",	qb_do_complex_argument_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_argument_2x_multiple_times_F64",	qb_do_complex_argument_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_cos_2x_F32",	qb_do_complex_cos_2x_F32,	0,	0	},
	{	"qb_do_complex_cos_2x_F64",	qb_do_complex_cos_2x_F64,	0,	0	},
	{	"qb_do_complex_cos_2x_multiple_times_F32",	qb_do_complex_cos_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_cos_2x_multiple_times_F64",	qb_do_complex_cos_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_cosh_2x_F32",	qb_do_complex_cosh_2x_F32,	0,	0	},
	{	"qb_do_complex_cosh_2x_F64",	qb_do_complex_cosh_2x_F64,	0,	0	},
	{	"qb_do_complex_cosh_2x_multiple_times_F32",	qb_do_complex_cosh_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_cosh_2x_multiple_times_F64",	qb_do_complex_cosh_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_divide_2x_F32",	qb_do_complex_divide_2x_F32,	0,	0	},
	{	"qb_do_complex_divide_2x_F64",	qb_do_complex_divide_2x_F64,	0,	0	},
	{	"qb_do_complex_divide_2x_multiple_times_F32",	qb_do_complex_divide_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_divide_2x_multiple_times_F64",	qb_do_complex_divide_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_exp_2x_F32",	qb_do_complex_exp_2x_F32,	0,	0	},
	{	"qb_do_complex_exp_2x_F64",	qb_do_complex_exp_2x_F64,	0,	0	},
	{	"qb_do_complex_exp_2x_multiple_times_F32",	qb_do_complex_exp_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_exp_2x_multiple_times_F64",	qb_do_complex_exp_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_log_2x_F32",	qb_do_complex_log_2x_F32,	0,	0	},
	{	"qb_do_complex_log_2x_F64",	qb_do_complex_log_2x_F64,	0,	0	},
	{	"qb_do_complex_log_2x_multiple_times_F32",	qb_do_complex_log_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_log_2x_multiple_times_F64",	qb_do_complex_log_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_multiply_2x_F32",	qb_do_complex_multiply_2x_F32,	0,	0	},
	{	"qb_do_complex_multiply_2x_F64",	qb_do_complex_multiply_2x_F64,	0,	0	},
	{	"qb_do_complex_multiply_2x_multiple_times_F32",	qb_do_complex_multiply_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_multiply_2x_multiple_times_F64",	qb_do_complex_multiply_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_pow_2x_F32",	qb_do_complex_pow_2x_F32,	0,	0	},
	{	"qb_do_complex_pow_2x_F64",	qb_do_complex_pow_2x_F64,	0,	0	},
	{	"qb_do_complex_pow_2x_multiple_times_F32",	qb_do_complex_pow_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_pow_2x_multiple_times_F64",	qb_do_complex_pow_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_sin_2x_F32",	qb_do_complex_sin_2x_F32,	0,	0	},
	{	"qb_do_complex_sin_2x_F64",	qb_do_complex_sin_2x_F64,	0,	0	},
	{	"qb_do_complex_sin_2x_multiple_times_F32",	qb_do_complex_sin_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_sin_2x_multiple_times_F64",	qb_do_complex_sin_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_sinh_2x_F32",	qb_do_complex_sinh_2x_F32,	0,	0	},
	{	"qb_do_complex_sinh_2x_F64",	qb_do_complex_sinh_2x_F64,	0,	0	},
	{	"qb_do_complex_sinh_2x_multiple_times_F32",	qb_do_complex_sinh_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_sinh_2x_multiple_times_F64",	qb_do_complex_sinh_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_square_root_2x_F32",	qb_do_complex_square_root_2x_F32,	0,	0	},
	{	"qb_do_complex_square_root_2x_F64",	qb_do_complex_square_root_2x_F64,	0,	0	},
	{	"qb_do_complex_square_root_2x_multiple_times_F32",	qb_do_complex_square_root_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_square_root_2x_multiple_times_F64",	qb_do_complex_square_root_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_tan_2x_F32",	qb_do_complex_tan_2x_F32,	0,	0	},
	{	"qb_do_complex_tan_2x_F64",	qb_do_complex_tan_2x_F64,	0,	0	},
	{	"qb_do_complex_tan_2x_multiple_times_F32",	qb_do_complex_tan_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_tan_2x_multiple_times_F64",	qb_do_complex_tan_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_complex_tanh_2x_F32",	qb_do_complex_tanh_2x_F32,	0,	0	},
	{	"qb_do_complex_tanh_2x_F64",	qb_do_complex_tanh_2x_F64,	0,	0	},
	{	"qb_do_complex_tanh_2x_multiple_times_F32",	qb_do_complex_tanh_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_complex_tanh_2x_multiple_times_F64",	qb_do_complex_tanh_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_convert_from_string_F32",	qb_do_convert_from_string_F32,	0,	0	},
	{	"qb_do_convert_from_string_F64",	qb_do_convert_from_string_F64,	0,	0	},
	{	"qb_do_convert_from_string_S08",	qb_do_convert_from_string_S08,	0,	0	},
	{	"qb_do_convert_from_string_S16",	qb_do_convert_from_string_S16,	0,	0	},
	{	"qb_do_convert_from_string_S32",	qb_do_convert_from_string_S32,	0,	0	},
	{	"qb_do_convert_from_string_S64",	qb_do_convert_from_string_S64,	0,	0	},
	{	"qb_do_convert_from_string_U08",	qb_do_convert_from_string_U08,	0,	0	},
	{	"qb_do_convert_from_string_U16",	qb_do_convert_from_string_U16,	0,	0	},
	{	"qb_do_convert_from_string_U32",	qb_do_convert_from_string_U32,	0,	0	},
	{	"qb_do_convert_from_string_U64",	qb_do_convert_from_string_U64,	0,	0	},
	{	"qb_do_copy_2x_multiple_times_F32",	qb_do_copy_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_copy_2x_multiple_times_F64",	qb_do_copy_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_copy_3x_multiple_times_F32",	qb_do_copy_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_copy_3x_multiple_times_F64",	qb_do_copy_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_copy_4x_multiple_times_F32",	qb_do_copy_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_copy_4x_multiple_times_F64",	qb_do_copy_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_copy_multiple_times_F32",	qb_do_copy_multiple_times_F32,	0,	0	},
	{	"qb_do_copy_multiple_times_F64",	qb_do_copy_multiple_times_F64,	0,	0	},
	{	"qb_do_copy_multiple_times_I08",	qb_do_copy_multiple_times_I08,	0,	0	},
	{	"qb_do_copy_multiple_times_I16",	qb_do_copy_multiple_times_I16,	0,	0	},
	{	"qb_do_copy_multiple_times_I32",	qb_do_copy_multiple_times_I32,	0,	0	},
	{	"qb_do_copy_multiple_times_I64",	qb_do_copy_multiple_times_I64,	0,	0	},
	{	"qb_do_cos_multiple_times_F32",	qb_do_cos_multiple_times_F32,	0,	0	},
	{	"qb_do_cos_multiple_times_F64",	qb_do_cos_multiple_times_F64,	0,	0	},
	{	"qb_do_cosh_multiple_times_F32",	qb_do_cosh_multiple_times_F32,	0,	0	},
	{	"qb_do_cosh_multiple_times_F64",	qb_do_cosh_multiple_times_F64,	0,	0	},
	{	"qb_do_cross_product_2x_multiple_times_F32",	qb_do_cross_product_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_cross_product_2x_multiple_times_F64",	qb_do_cross_product_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_cross_product_3x_multiple_times_F32",	qb_do_cross_product_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_cross_product_3x_multiple_times_F64",	qb_do_cross_product_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_cross_product_4x_multiple_times_F32",	qb_do_cross_product_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_cross_product_4x_multiple_times_F64",	qb_do_cross_product_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_decrement_2x_multiple_times_F32",	qb_do_decrement_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_decrement_2x_multiple_times_F64",	qb_do_decrement_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_decrement_3x_multiple_times_F32",	qb_do_decrement_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_decrement_3x_multiple_times_F64",	qb_do_decrement_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_decrement_4x_multiple_times_F32",	qb_do_decrement_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_decrement_4x_multiple_times_F64",	qb_do_decrement_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_decrement_multiple_times_F32",	qb_do_decrement_multiple_times_F32,	0,	0	},
	{	"qb_do_decrement_multiple_times_F64",	qb_do_decrement_multiple_times_F64,	0,	0	},
	{	"qb_do_decrement_multiple_times_I08",	qb_do_decrement_multiple_times_I08,	0,	0	},
	{	"qb_do_decrement_multiple_times_I16",	qb_do_decrement_multiple_times_I16,	0,	0	},
	{	"qb_do_decrement_multiple_times_I32",	qb_do_decrement_multiple_times_I32,	0,	0	},
	{	"qb_do_decrement_multiple_times_I64",	qb_do_decrement_multiple_times_I64,	0,	0	},
	{	"qb_do_degree_to_radian_multiple_times_F32",	qb_do_degree_to_radian_multiple_times_F32,	0,	0	},
	{	"qb_do_degree_to_radian_multiple_times_F64",	qb_do_degree_to_radian_multiple_times_F64,	0,	0	},
	{	"qb_do_determinant_2x_multiple_times_F32",	qb_do_determinant_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_determinant_2x_multiple_times_F64",	qb_do_determinant_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_determinant_3x_multiple_times_F32",	qb_do_determinant_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_determinant_3x_multiple_times_F64",	qb_do_determinant_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_determinant_4x_multiple_times_F32",	qb_do_determinant_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_determinant_4x_multiple_times_F64",	qb_do_determinant_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_determinant_F32",	qb_do_determinant_F32,	0,	0	},
	{	"qb_do_determinant_F64",	qb_do_determinant_F64,	0,	0	},
	{	"qb_do_determinant_multiple_times_F32",	qb_do_determinant_multiple_times_F32,	0,	0	},
	{	"qb_do_determinant_multiple_times_F64",	qb_do_determinant_multiple_times_F64,	0,	0	},
	{	"qb_do_distance_2x_multiple_times_F32",	qb_do_distance_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_distance_2x_multiple_times_F64",	qb_do_distance_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_distance_3x_multiple_times_F32",	qb_do_distance_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_distance_3x_multiple_times_F64",	qb_do_distance_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_distance_4x_multiple_times_F32",	qb_do_distance_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_distance_4x_multiple_times_F64",	qb_do_distance_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_distance_F32",	qb_do_distance_F32,	0,	0	},
	{	"qb_do_distance_F64",	qb_do_distance_F64,	0,	0	},
	{	"qb_do_distance_multiple_times_F32",	qb_do_distance_multiple_times_F32,	0,	0	},
	{	"qb_do_distance_multiple_times_F64",	qb_do_distance_multiple_times_F64,	0,	0	},
	{	"qb_do_divide_2x_multiple_times_F32",	qb_do_divide_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_divide_2x_multiple_times_F64",	qb_do_divide_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_divide_3x_multiple_times_F32",	qb_do_divide_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_divide_3x_multiple_times_F64",	qb_do_divide_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_divide_4x_multiple_times_F32",	qb_do_divide_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_divide_4x_multiple_times_F64",	qb_do_divide_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_divide_multiple_times_F32",	qb_do_divide_multiple_times_F32,	0,	0	},
	{	"qb_do_divide_multiple_times_F64",	qb_do_divide_multiple_times_F64,	0,	0	},
	{	"qb_do_dot_product_2x_multiple_times_F32",	qb_do_dot_product_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_dot_product_2x_multiple_times_F64",	qb_do_dot_product_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_dot_product_3x_multiple_times_F32",	qb_do_dot_product_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_dot_product_3x_multiple_times_F64",	qb_do_dot_product_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_dot_product_4x_multiple_times_F32",	qb_do_dot_product_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_dot_product_4x_multiple_times_F64",	qb_do_dot_product_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_dot_product_F32",	qb_do_dot_product_F32,	0,	0	},
	{	"qb_do_dot_product_F64",	qb_do_dot_product_F64,	0,	0	},
	{	"qb_do_dot_product_multiple_times_F32",	qb_do_dot_product_multiple_times_F32,	0,	0	},
	{	"qb_do_dot_product_multiple_times_F64",	qb_do_dot_product_multiple_times_F64,	0,	0	},
	{	"qb_do_equal_multiple_times_F32",	qb_do_equal_multiple_times_F32,	0,	0	},
	{	"qb_do_equal_multiple_times_F64",	qb_do_equal_multiple_times_F64,	0,	0	},
	{	"qb_do_equal_multiple_times_I08",	qb_do_equal_multiple_times_I08,	0,	0	},
	{	"qb_do_equal_multiple_times_I16",	qb_do_equal_multiple_times_I16,	0,	0	},
	{	"qb_do_equal_multiple_times_I32",	qb_do_equal_multiple_times_I32,	0,	0	},
	{	"qb_do_equal_multiple_times_I64",	qb_do_equal_multiple_times_I64,	0,	0	},
	{	"qb_do_exp2_multiple_times_F32",	qb_do_exp2_multiple_times_F32,	0,	0	},
	{	"qb_do_exp2_multiple_times_F64",	qb_do_exp2_multiple_times_F64,	0,	0	},
	{	"qb_do_exp_m1_multiple_times_F32",	qb_do_exp_m1_multiple_times_F32,	0,	0	},
	{	"qb_do_exp_m1_multiple_times_F64",	qb_do_exp_m1_multiple_times_F64,	0,	0	},
	{	"qb_do_exp_multiple_times_F32",	qb_do_exp_multiple_times_F32,	0,	0	},
	{	"qb_do_exp_multiple_times_F64",	qb_do_exp_multiple_times_F64,	0,	0	},
	{	"qb_do_face_forward_2x_multiple_times_F32",	qb_do_face_forward_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_face_forward_2x_multiple_times_F64",	qb_do_face_forward_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_face_forward_3x_multiple_times_F32",	qb_do_face_forward_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_face_forward_3x_multiple_times_F64",	qb_do_face_forward_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_face_forward_4x_multiple_times_F32",	qb_do_face_forward_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_face_forward_4x_multiple_times_F64",	qb_do_face_forward_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_face_forward_F32",	qb_do_face_forward_F32,	0,	0	},
	{	"qb_do_face_forward_F64",	qb_do_face_forward_F64,	0,	0	},
	{	"qb_do_face_forward_multiple_times_F32",	qb_do_face_forward_multiple_times_F32,	0,	0	},
	{	"qb_do_face_forward_multiple_times_F64",	qb_do_face_forward_multiple_times_F64,	0,	0	},
	{	"qb_do_floor_multiple_times_F32",	qb_do_floor_multiple_times_F32,	0,	0	},
	{	"qb_do_floor_multiple_times_F64",	qb_do_floor_multiple_times_F64,	0,	0	},
	{	"qb_do_floored_division_modulo_multiple_times_F32",	qb_do_floored_division_modulo_multiple_times_F32,	0,	0	},
	{	"qb_do_floored_division_modulo_multiple_times_F64",	qb_do_floored_division_modulo_multiple_times_F64,	0,	0	},
	{	"qb_do_fract_multiple_times_F32",	qb_do_fract_multiple_times_F32,	0,	0	},
	{	"qb_do_fract_multiple_times_F64",	qb_do_fract_multiple_times_F64,	0,	0	},
	{	"qb_do_gather_8x_F32",	qb_do_gather_8x_F32,	0,	0	},
	{	"qb_do_gather_8x_F64",	qb_do_gather_8x_F64,	0,	0	},
	{	"qb_do_gather_8x_I08",	qb_do_gather_8x_I08,	0,	0	},
	{	"qb_do_gather_8x_I16",	qb_do_gather_8x_I16,	0,	0	},
	{	"qb_do_gather_8x_I32",	qb_do_gather_8x_I32,	0,	0	},
	{	"qb_do_gather_8x_I64",	qb_do_gather_8x_I64,	0,	0	},
	{	"qb_do_hsl2rgb_3x_multiple_times_F32",	qb_do_hsl2rgb_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_hsl2rgb_3x_multiple_times_F64",	qb_do_hsl2rgb_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_hsl2rgb_4x_multiple_times_F32",	qb_do_hsl2rgb_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_hsl2rgb_4x_multiple_times_F64",	qb_do_hsl2rgb_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_hsv2rgb_3x_multiple_times_F32",	qb_do_hsv2rgb_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_hsv2rgb_3x_multiple_times_F64",	qb_do_hsv2rgb_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_hsv2rgb_4x_multiple_times_F32",	qb_do_hsv2rgb_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_hsv2rgb_4x_multiple_times_F64",	qb_do_hsv2rgb_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_hypot_multiple_times_F32",	qb_do_hypot_multiple_times_F32,	0,	0	},
	{	"qb_do_hypot_multiple_times_F64",	qb_do_hypot_multiple_times_F64,	0,	0	},
	{	"qb_do_increment_2x_multiple_times_F32",	qb_do_increment_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_increment_2x_multiple_times_F64",	qb_do_increment_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_increment_3x_multiple_times_F32",	qb_do_increment_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_increment_3x_multiple_times_F64",	qb_do_increment_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_increment_4x_multiple_times_F32",	qb_do_increment_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_increment_4x_multiple_times_F64",	qb_do_increment_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_increment_multiple_times_F32",	qb_do_increment_multiple_times_F32,	0,	0	},
	{	"qb_do_increment_multiple_times_F64",	qb_do_increment_multiple_times_F64,	0,	0	},
	{	"qb_do_increment_multiple_times_I08",	qb_do_increment_multiple_times_I08,	0,	0	},
	{	"qb_do_increment_multiple_times_I16",	qb_do_increment_multiple_times_I16,	0,	0	},
	{	"qb_do_increment_multiple_times_I32",	qb_do_increment_multiple_times_I32,	0,	0	},
	{	"qb_do_increment_multiple_times_I64",	qb_do_increment_multiple_times_I64,	0,	0	},
	{	"qb_do_invert_matrix_2x_F32",	qb_do_invert_matrix_2x_F32,	0,	0	},
	{	"qb_do_invert_matrix_2x_F64",	qb_do_invert_matrix_2x_F64,	0,	0	},
	{	"qb_do_invert_matrix_2x_multiple_times_F32",	qb_do_invert_matrix_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_invert_matrix_2x_multiple_times_F64",	qb_do_invert_matrix_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_invert_matrix_3x_F32",	qb_do_invert_matrix_3x_F32,	0,	0	},
	{	"qb_do_invert_matrix_3x_F64",	qb_do_invert_matrix_3x_F64,	0,	0	},
	{	"qb_do_invert_matrix_3x_multiple_times_F32",	qb_do_invert_matrix_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_invert_matrix_3x_multiple_times_F64",	qb_do_invert_matrix_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_invert_matrix_4x_F32",	qb_do_invert_matrix_4x_F32,	0,	0	},
	{	"qb_do_invert_matrix_4x_F64",	qb_do_invert_matrix_4x_F64,	0,	0	},
	{	"qb_do_invert_matrix_4x_multiple_times_F32",	qb_do_invert_matrix_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_invert_matrix_4x_multiple_times_F64",	qb_do_invert_matrix_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_invert_matrix_F32",	qb_do_invert_matrix_F32,	0,	0	},
	{	"qb_do_invert_matrix_F64",	qb_do_invert_matrix_F64,	0,	0	},
	{	"qb_do_invert_matrix_multiple_times_F32",	qb_do_invert_matrix_multiple_times_F32,	0,	0	},
	{	"qb_do_invert_matrix_multiple_times_F64",	qb_do_invert_matrix_multiple_times_F64,	0,	0	},
	{	"qb_do_is_finite_F32",	qb_do_is_finite_F32,	0,	0	},
	{	"qb_do_is_finite_F64",	qb_do_is_finite_F64,	0,	0	},
	{	"qb_do_is_finite_multiple_times_F32",	qb_do_is_finite_multiple_times_F32,	0,	0	},
	{	"qb_do_is_finite_multiple_times_F64",	qb_do_is_finite_multiple_times_F64,	0,	0	},
	{	"qb_do_is_infinite_F32",	qb_do_is_infinite_F32,	0,	0	},
	{	"qb_do_is_infinite_F64",	qb_do_is_infinite_F64,	0,	0	},
	{	"qb_do_is_infinite_multiple_times_F32",	qb_do_is_infinite_multiple_times_F32,	0,	0	},
	{	"qb_do_is_infinite_multiple_times_F64",	qb_do_is_infinite_multiple_times_F64,	0,	0	},
	{	"qb_do_is_nan_F32",	qb_do_is_nan_F32,	0,	0	},
	{	"qb_do_is_nan_F64",	qb_do_is_nan_F64,	0,	0	},
	{	"qb_do_is_nan_multiple_times_F32",	qb_do_is_nan_multiple_times_F32,	0,	0	},
	{	"qb_do_is_nan_multiple_times_F64",	qb_do_is_nan_multiple_times_F64,	0,	0	},
	{	"qb_do_lcg_F32",	qb_do_lcg_F32,	0,	0	},
	{	"qb_do_lcg_F64",	qb_do_lcg_F64,	0,	0	},
	{	"qb_do_lcg_multiple_times_F32",	qb_do_lcg_multiple_times_F32,	0,	0	},
	{	"qb_do_lcg_multiple_times_F64",	qb_do_lcg_multiple_times_F64,	0,	0	},
	{	"qb_do_length_2x_multiple_times_F32",	qb_do_length_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_length_2x_multiple_times_F64",	qb_do_length_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_length_3x_multiple_times_F32",	qb_do_length_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_length_3x_multiple_times_F64",	qb_do_length_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_length_4x_multiple_times_F32",	qb_do_length_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_length_4x_multiple_times_F64",	qb_do_length_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_length_F32",	qb_do_length_F32,	0,	0	},
	{	"qb_do_length_F64",	qb_do_length_F64,	0,	0	},
	{	"qb_do_length_multiple_times_F32",	qb_do_length_multiple_times_F32,	0,	0	},
	{	"qb_do_length_multiple_times_F64",	qb_do_length_multiple_times_F64,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_F32",	qb_do_less_than_equal_multiple_times_F32,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_F64",	qb_do_less_than_equal_multiple_times_F64,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_S08",	qb_do_less_than_equal_multiple_times_S08,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_S16",	qb_do_less_than_equal_multiple_times_S16,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_S32",	qb_do_less_than_equal_multiple_times_S32,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_S64",	qb_do_less_than_equal_multiple_times_S64,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_U08",	qb_do_less_than_equal_multiple_times_U08,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_U16",	qb_do_less_than_equal_multiple_times_U16,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_U32",	qb_do_less_than_equal_multiple_times_U32,	0,	0	},
	{	"qb_do_less_than_equal_multiple_times_U64",	qb_do_less_than_equal_multiple_times_U64,	0,	0	},
	{	"qb_do_less_than_multiple_times_F32",	qb_do_less_than_multiple_times_F32,	0,	0	},
	{	"qb_do_less_than_multiple_times_F64",	qb_do_less_than_multiple_times_F64,	0,	0	},
	{	"qb_do_less_than_multiple_times_S08",	qb_do_less_than_multiple_times_S08,	0,	0	},
	{	"qb_do_less_than_multiple_times_S16",	qb_do_less_than_multiple_times_S16,	0,	0	},
	{	"qb_do_less_than_multiple_times_S32",	qb_do_less_than_multiple_times_S32,	0,	0	},
	{	"qb_do_less_than_multiple_times_S64",	qb_do_less_than_multiple_times_S64,	0,	0	},
	{	"qb_do_less_than_multiple_times_U08",	qb_do_less_than_multiple_times_U08,	0,	0	},
	{	"qb_do_less_than_multiple_times_U16",	qb_do_less_than_multiple_times_U16,	0,	0	},
	{	"qb_do_less_than_multiple_times_U32",	qb_do_less_than_multiple_times_U32,	0,	0	},
	{	"qb_do_less_than_multiple_times_U64",	qb_do_less_than_multiple_times_U64,	0,	0	},
	{	"qb_do_log10_multiple_times_F32",	qb_do_log10_multiple_times_F32,	0,	0	},
	{	"qb_do_log10_multiple_times_F64",	qb_do_log10_multiple_times_F64,	0,	0	},
	{	"qb_do_log1p_multiple_times_F32",	qb_do_log1p_multiple_times_F32,	0,	0	},
	{	"qb_do_log1p_multiple_times_F64",	qb_do_log1p_multiple_times_F64,	0,	0	},
	{	"qb_do_log2_multiple_times_F32",	qb_do_log2_multiple_times_F32,	0,	0	},
	{	"qb_do_log2_multiple_times_F64",	qb_do_log2_multiple_times_F64,	0,	0	},
	{	"qb_do_log_multiple_times_F32",	qb_do_log_multiple_times_F32,	0,	0	},
	{	"qb_do_log_multiple_times_F64",	qb_do_log_multiple_times_F64,	0,	0	},
	{	"qb_do_max_multiple_times_F32",	qb_do_max_multiple_times_F32,	0,	0	},
	{	"qb_do_max_multiple_times_F64",	qb_do_max_multiple_times_F64,	0,	0	},
	{	"qb_do_max_multiple_times_S08",	qb_do_max_multiple_times_S08,	0,	0	},
	{	"qb_do_max_multiple_times_S16",	qb_do_max_multiple_times_S16,	0,	0	},
	{	"qb_do_max_multiple_times_S32",	qb_do_max_multiple_times_S32,	0,	0	},
	{	"qb_do_max_multiple_times_S64",	qb_do_max_multiple_times_S64,	0,	0	},
	{	"qb_do_max_multiple_times_U08",	qb_do_max_multiple_times_U08,	0,	0	},
	{	"qb_do_max_multiple_times_U16",	qb_do_max_multiple_times_U16,	0,	0	},
	{	"qb_do_max_multiple_times_U32",	qb_do_max_multiple_times_U32,	0,	0	},
	{	"qb_do_max_multiple_times_U64",	qb_do_max_multiple_times_U64,	0,	0	},
	{	"qb_do_min_multiple_times_F32",	qb_do_min_multiple_times_F32,	0,	0	},
	{	"qb_do_min_multiple_times_F64",	qb_do_min_multiple_times_F64,	0,	0	},
	{	"qb_do_min_multiple_times_S08",	qb_do_min_multiple_times_S08,	0,	0	},
	{	"qb_do_min_multiple_times_S16",	qb_do_min_multiple_times_S16,	0,	0	},
	{	"qb_do_min_multiple_times_S32",	qb_do_min_multiple_times_S32,	0,	0	},
	{	"qb_do_min_multiple_times_S64",	qb_do_min_multiple_times_S64,	0,	0	},
	{	"qb_do_min_multiple_times_U08",	qb_do_min_multiple_times_U08,	0,	0	},
	{	"qb_do_min_multiple_times_U16",	qb_do_min_multiple_times_U16,	0,	0	},
	{	"qb_do_min_multiple_times_U32",	qb_do_min_multiple_times_U32,	0,	0	},
	{	"qb_do_min_multiple_times_U64",	qb_do_min_multiple_times_U64,	0,	0	},
	{	"qb_do_mix_multiple_times_F32",	qb_do_mix_multiple_times_F32,	0,	0	},
	{	"qb_do_mix_multiple_times_F64",	qb_do_mix_multiple_times_F64,	0,	0	},
	{	"qb_do_modulo_2x_multiple_times_F32",	qb_do_modulo_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_modulo_2x_multiple_times_F64",	qb_do_modulo_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_modulo_3x_multiple_times_F32",	qb_do_modulo_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_modulo_3x_multiple_times_F64",	qb_do_modulo_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_modulo_4x_multiple_times_F32",	qb_do_modulo_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_modulo_4x_multiple_times_F64",	qb_do_modulo_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_modulo_multiple_times_F32",	qb_do_modulo_multiple_times_F32,	0,	0	},
	{	"qb_do_modulo_multiple_times_F64",	qb_do_modulo_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_2x_multiple_times_F32",	qb_do_multiply_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_2x_multiple_times_F64",	qb_do_multiply_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_3x_multiple_times_F32",	qb_do_multiply_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_3x_multiple_times_F64",	qb_do_multiply_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_4x_multiple_times_F32",	qb_do_multiply_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_4x_multiple_times_F64",	qb_do_multiply_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_accumulate_2x_multiple_times_F32",	qb_do_multiply_accumulate_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_accumulate_2x_multiple_times_F64",	qb_do_multiply_accumulate_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_accumulate_3x_multiple_times_F32",	qb_do_multiply_accumulate_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_accumulate_3x_multiple_times_F64",	qb_do_multiply_accumulate_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_accumulate_4x_multiple_times_F32",	qb_do_multiply_accumulate_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_accumulate_4x_multiple_times_F64",	qb_do_multiply_accumulate_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_F32",	qb_do_multiply_accumulate_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_F64",	qb_do_multiply_accumulate_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_S32",	qb_do_multiply_accumulate_multiple_times_S32,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_S64",	qb_do_multiply_accumulate_multiple_times_S64,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_U32",	qb_do_multiply_accumulate_multiple_times_U32,	0,	0	},
	{	"qb_do_multiply_accumulate_multiple_times_U64",	qb_do_multiply_accumulate_multiple_times_U64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_matrix_2x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_3x_column_major_F32",	qb_do_multiply_matrix_by_matrix_3x_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_3x_column_major_F64",	qb_do_multiply_matrix_by_matrix_3x_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_matrix_3x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_4x_column_major_F32",	qb_do_multiply_matrix_by_matrix_4x_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_4x_column_major_F64",	qb_do_multiply_matrix_by_matrix_4x_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_matrix_4x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_column_major_F32",	qb_do_multiply_matrix_by_matrix_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_column_major_F64",	qb_do_multiply_matrix_by_matrix_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_matrix_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_matrix_padded_3x_F32",	qb_do_multiply_matrix_by_matrix_padded_3x_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_vector_2x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_vector_3x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_vector_4x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_column_major_F32",	qb_do_multiply_matrix_by_vector_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_column_major_F64",	qb_do_multiply_matrix_by_vector_column_major_F64,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_multiple_times_column_major_F32",	qb_do_multiply_matrix_by_vector_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_matrix_by_vector_multiple_times_column_major_F64",	qb_do_multiply_matrix_by_vector_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_multiple_times_F32",	qb_do_multiply_multiple_times_F32,	0,	0	},
	{	"qb_do_multiply_multiple_times_F64",	qb_do_multiply_multiple_times_F64,	0,	0	},
	{	"qb_do_multiply_multiple_times_S08",	qb_do_multiply_multiple_times_S08,	0,	0	},
	{	"qb_do_multiply_multiple_times_S16",	qb_do_multiply_multiple_times_S16,	0,	0	},
	{	"qb_do_multiply_multiple_times_S32",	qb_do_multiply_multiple_times_S32,	0,	0	},
	{	"qb_do_multiply_multiple_times_S64",	qb_do_multiply_multiple_times_S64,	0,	0	},
	{	"qb_do_multiply_multiple_times_U08",	qb_do_multiply_multiple_times_U08,	0,	0	},
	{	"qb_do_multiply_multiple_times_U16",	qb_do_multiply_multiple_times_U16,	0,	0	},
	{	"qb_do_multiply_multiple_times_U32",	qb_do_multiply_multiple_times_U32,	0,	0	},
	{	"qb_do_multiply_multiple_times_U64",	qb_do_multiply_multiple_times_U64,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F32",	qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F64",	qb_do_multiply_vector_by_matrix_2x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F32",	qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F64",	qb_do_multiply_vector_by_matrix_3x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F32",	qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F64",	qb_do_multiply_vector_by_matrix_4x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_column_major_F32",	qb_do_multiply_vector_by_matrix_column_major_F32,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_column_major_F64",	qb_do_multiply_vector_by_matrix_column_major_F64,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_multiple_times_column_major_F32",	qb_do_multiply_vector_by_matrix_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_multiply_vector_by_matrix_multiple_times_column_major_F64",	qb_do_multiply_vector_by_matrix_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_negate_2x_multiple_times_F32",	qb_do_negate_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_negate_2x_multiple_times_F64",	qb_do_negate_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_negate_3x_multiple_times_F32",	qb_do_negate_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_negate_3x_multiple_times_F64",	qb_do_negate_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_negate_4x_multiple_times_F32",	qb_do_negate_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_negate_4x_multiple_times_F64",	qb_do_negate_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_negate_multiple_times_F32",	qb_do_negate_multiple_times_F32,	0,	0	},
	{	"qb_do_negate_multiple_times_F64",	qb_do_negate_multiple_times_F64,	0,	0	},
	{	"qb_do_negate_multiple_times_I08",	qb_do_negate_multiple_times_I08,	0,	0	},
	{	"qb_do_negate_multiple_times_I16",	qb_do_negate_multiple_times_I16,	0,	0	},
	{	"qb_do_negate_multiple_times_I32",	qb_do_negate_multiple_times_I32,	0,	0	},
	{	"qb_do_negate_multiple_times_I64",	qb_do_negate_multiple_times_I64,	0,	0	},
	{	"qb_do_normalize_2x_multiple_times_F32",	qb_do_normalize_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_normalize_2x_multiple_times_F64",	qb_do_normalize_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_normalize_3x_multiple_times_F32",	qb_do_normalize_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_normalize_3x_multiple_times_F64",	qb_do_normalize_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_normalize_4x_multiple_times_F32",	qb_do_normalize_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_normalize_4x_multiple_times_F64",	qb_do_normalize_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_normalize_F32",	qb_do_normalize_F32,	0,	0	},
	{	"qb_do_normalize_F64",	qb_do_normalize_F64,	0,	0	},
	{	"qb_do_normalize_multiple_times_F32",	qb_do_normalize_multiple_times_F32,	0,	0	},
	{	"qb_do_normalize_multiple_times_F64",	qb_do_normalize_multiple_times_F64,	0,	0	},
	{	"qb_do_not_equal_multiple_times_F32",	qb_do_not_equal_multiple_times_F32,	0,	0	},
	{	"qb_do_not_equal_multiple_times_F64",	qb_do_not_equal_multiple_times_F64,	0,	0	},
	{	"qb_do_not_equal_multiple_times_I08",	qb_do_not_equal_multiple_times_I08,	0,	0	},
	{	"qb_do_not_equal_multiple_times_I16",	qb_do_not_equal_multiple_times_I16,	0,	0	},
	{	"qb_do_not_equal_multiple_times_I32",	qb_do_not_equal_multiple_times_I32,	0,	0	},
	{	"qb_do_not_equal_multiple_times_I64",	qb_do_not_equal_multiple_times_I64,	0,	0	},
	{	"qb_do_pow_multiple_times_F32",	qb_do_pow_multiple_times_F32,	0,	0	},
	{	"qb_do_pow_multiple_times_F64",	qb_do_pow_multiple_times_F64,	0,	0	},
	{	"qb_do_predicate_clear_array_F32",	qb_do_predicate_clear_array_F32,	0,	0	},
	{	"qb_do_predicate_clear_array_F64",	qb_do_predicate_clear_array_F64,	0,	0	},
	{	"qb_do_predicate_clear_array_I08",	qb_do_predicate_clear_array_I08,	0,	0	},
	{	"qb_do_predicate_clear_array_I16",	qb_do_predicate_clear_array_I16,	0,	0	},
	{	"qb_do_predicate_clear_array_I32",	qb_do_predicate_clear_array_I32,	0,	0	},
	{	"qb_do_predicate_clear_array_I64",	qb_do_predicate_clear_array_I64,	0,	0	},
	{	"qb_do_predicate_clear_element_F32",	qb_do_predicate_clear_element_F32,	0,	0	},
	{	"qb_do_predicate_clear_element_F64",	qb_do_predicate_clear_element_F64,	0,	0	},
	{	"qb_do_predicate_clear_element_I08",	qb_do_predicate_clear_element_I08,	0,	0	},
	{	"qb_do_predicate_clear_element_I16",	qb_do_predicate_clear_element_I16,	0,	0	},
	{	"qb_do_predicate_clear_element_I32",	qb_do_predicate_clear_element_I32,	0,	0	},
	{	"qb_do_predicate_clear_element_I64",	qb_do_predicate_clear_element_I64,	0,	0	},
	{	"qb_do_print_multidimensional_variable_F32",	qb_do_print_multidimensional_variable_F32,	0,	0	},
	{	"qb_do_print_multidimensional_variable_F64",	qb_do_print_multidimensional_variable_F64,	0,	0	},
	{	"qb_do_print_multidimensional_variable_S08",	qb_do_print_multidimensional_variable_S08,	0,	0	},
	{	"qb_do_print_multidimensional_variable_S16",	qb_do_print_multidimensional_variable_S16,	0,	0	},
	{	"qb_do_print_multidimensional_variable_S32",	qb_do_print_multidimensional_variable_S32,	0,	0	},
	{	"qb_do_print_multidimensional_variable_S64",	qb_do_print_multidimensional_variable_S64,	0,	0	},
	{	"qb_do_print_multidimensional_variable_U08",	qb_do_print_multidimensional_variable_U08,	0,	0	},
	{	"qb_do_print_multidimensional_variable_U16",	qb_do_print_multidimensional_variable_U16,	0,	0	},
	{	"qb_do_print_multidimensional_variable_U32",	qb_do_print_multidimensional_variable_U32,	0,	0	},
	{	"qb_do_print_multidimensional_variable_U64",	qb_do_print_multidimensional_variable_U64,	0,	0	},
	{	"qb_do_print_string_U08",	qb_do_print_string_U08,	0,	0	},
	{	"qb_do_print_variable_F32",	qb_do_print_variable_F32,	0,	0	},
	{	"qb_do_print_variable_F64",	qb_do_print_variable_F64,	0,	0	},
	{	"qb_do_print_variable_S08",	qb_do_print_variable_S08,	0,	0	},
	{	"qb_do_print_variable_S16",	qb_do_print_variable_S16,	0,	0	},
	{	"qb_do_print_variable_S32",	qb_do_print_variable_S32,	0,	0	},
	{	"qb_do_print_variable_S64",	qb_do_print_variable_S64,	0,	0	},
	{	"qb_do_print_variable_U08",	qb_do_print_variable_U08,	0,	0	},
	{	"qb_do_print_variable_U16",	qb_do_print_variable_U16,	0,	0	},
	{	"qb_do_print_variable_U32",	qb_do_print_variable_U32,	0,	0	},
	{	"qb_do_print_variable_U64",	qb_do_print_variable_U64,	0,	0	},
	{	"qb_do_print_variable_multiple_times_F32",	qb_do_print_variable_multiple_times_F32,	0,	0	},
	{	"qb_do_print_variable_multiple_times_F64",	qb_do_print_variable_multiple_times_F64,	0,	0	},
	{	"qb_do_print_variable_multiple_times_S08",	qb_do_print_variable_multiple_times_S08,	0,	0	},
	{	"qb_do_print_variable_multiple_times_S16",	qb_do_print_variable_multiple_times_S16,	0,	0	},
	{	"qb_do_print_variable_multiple_times_S32",	qb_do_print_variable_multiple_times_S32,	0,	0	},
	{	"qb_do_print_variable_multiple_times_S64",	qb_do_print_variable_multiple_times_S64,	0,	0	},
	{	"qb_do_print_variable_multiple_times_U08",	qb_do_print_variable_multiple_times_U08,	0,	0	},
	{	"qb_do_print_variable_multiple_times_U16",	qb_do_print_variable_multiple_times_U16,	0,	0	},
	{	"qb_do_print_variable_multiple_times_U32",	qb_do_print_variable_multiple_times_U32,	0,	0	},
	{	"qb_do_print_variable_multiple_times_U64",	qb_do_print_variable_multiple_times_U64,	0,	0	},
	{	"qb_do_radian_to_degree_multiple_times_F32",	qb_do_radian_to_degree_multiple_times_F32,	0,	0	},
	{	"qb_do_radian_to_degree_multiple_times_F64",	qb_do_radian_to_degree_multiple_times_F64,	0,	0	},
	{	"qb_do_random_S08",	qb_do_random_S08,	0,	0	},
	{	"qb_do_random_S16",	qb_do_random_S16,	0,	0	},
	{	"qb_do_random_S32",	qb_do_random_S32,	0,	0	},
	{	"qb_do_random_S64",	qb_do_random_S64,	0,	0	},
	{	"qb_do_random_U08",	qb_do_random_U08,	0,	0	},
	{	"qb_do_random_U16",	qb_do_random_U16,	0,	0	},
	{	"qb_do_random_U32",	qb_do_random_U32,	0,	0	},
	{	"qb_do_random_U64",	qb_do_random_U64,	0,	0	},
	{	"qb_do_random_mt_S08",	qb_do_random_mt_S08,	0,	0	},
	{	"qb_do_random_mt_S16",	qb_do_random_mt_S16,	0,	0	},
	{	"qb_do_random_mt_S32",	qb_do_random_mt_S32,	0,	0	},
	{	"qb_do_random_mt_S64",	qb_do_random_mt_S64,	0,	0	},
	{	"qb_do_random_mt_U08",	qb_do_random_mt_U08,	0,	0	},
	{	"qb_do_random_mt_U16",	qb_do_random_mt_U16,	0,	0	},
	{	"qb_do_random_mt_U32",	qb_do_random_mt_U32,	0,	0	},
	{	"qb_do_random_mt_U64",	qb_do_random_mt_U64,	0,	0	},
	{	"qb_do_random_mt_multiple_times_S08",	qb_do_random_mt_multiple_times_S08,	0,	0	},
	{	"qb_do_random_mt_multiple_times_S16",	qb_do_random_mt_multiple_times_S16,	0,	0	},
	{	"qb_do_random_mt_multiple_times_S32",	qb_do_random_mt_multiple_times_S32,	0,	0	},
	{	"qb_do_random_mt_multiple_times_S64",	qb_do_random_mt_multiple_times_S64,	0,	0	},
	{	"qb_do_random_mt_multiple_times_U08",	qb_do_random_mt_multiple_times_U08,	0,	0	},
	{	"qb_do_random_mt_multiple_times_U16",	qb_do_random_mt_multiple_times_U16,	0,	0	},
	{	"qb_do_random_mt_multiple_times_U32",	qb_do_random_mt_multiple_times_U32,	0,	0	},
	{	"qb_do_random_mt_multiple_times_U64",	qb_do_random_mt_multiple_times_U64,	0,	0	},
	{	"qb_do_random_multiple_times_S08",	qb_do_random_multiple_times_S08,	0,	0	},
	{	"qb_do_random_multiple_times_S16",	qb_do_random_multiple_times_S16,	0,	0	},
	{	"qb_do_random_multiple_times_S32",	qb_do_random_multiple_times_S32,	0,	0	},
	{	"qb_do_random_multiple_times_S64",	qb_do_random_multiple_times_S64,	0,	0	},
	{	"qb_do_random_multiple_times_U08",	qb_do_random_multiple_times_U08,	0,	0	},
	{	"qb_do_random_multiple_times_U16",	qb_do_random_multiple_times_U16,	0,	0	},
	{	"qb_do_random_multiple_times_U32",	qb_do_random_multiple_times_U32,	0,	0	},
	{	"qb_do_random_multiple_times_U64",	qb_do_random_multiple_times_U64,	0,	0	},
	{	"qb_do_range_F32",	qb_do_range_F32,	0,	0	},
	{	"qb_do_range_F64",	qb_do_range_F64,	0,	0	},
	{	"qb_do_range_S08",	qb_do_range_S08,	0,	0	},
	{	"qb_do_range_S16",	qb_do_range_S16,	0,	0	},
	{	"qb_do_range_S32",	qb_do_range_S32,	0,	0	},
	{	"qb_do_range_S64",	qb_do_range_S64,	0,	0	},
	{	"qb_do_range_U08",	qb_do_range_U08,	0,	0	},
	{	"qb_do_range_U16",	qb_do_range_U16,	0,	0	},
	{	"qb_do_range_U32",	qb_do_range_U32,	0,	0	},
	{	"qb_do_range_U64",	qb_do_range_U64,	0,	0	},
	{	"qb_do_reflect_2x_multiple_times_F32",	qb_do_reflect_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_reflect_2x_multiple_times_F64",	qb_do_reflect_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_reflect_3x_multiple_times_F32",	qb_do_reflect_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_reflect_3x_multiple_times_F64",	qb_do_reflect_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_reflect_4x_multiple_times_F32",	qb_do_reflect_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_reflect_4x_multiple_times_F64",	qb_do_reflect_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_reflect_F32",	qb_do_reflect_F32,	0,	0	},
	{	"qb_do_reflect_F64",	qb_do_reflect_F64,	0,	0	},
	{	"qb_do_reflect_multiple_times_F32",	qb_do_reflect_multiple_times_F32,	0,	0	},
	{	"qb_do_reflect_multiple_times_F64",	qb_do_reflect_multiple_times_F64,	0,	0	},
	{	"qb_do_refract_2x_multiple_times_F32",	qb_do_refract_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_refract_2x_multiple_times_F64",	qb_do_refract_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_refract_3x_multiple_times_F32",	qb_do_refract_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_refract_3x_multiple_times_F64",	qb_do_refract_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_refract_4x_multiple_times_F32",	qb_do_refract_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_refract_4x_multiple_times_F64",	qb_do_refract_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_refract_F32",	qb_do_refract_F32,	0,	0	},
	{	"qb_do_refract_F64",	qb_do_refract_F64,	0,	0	},
	{	"qb_do_refract_multiple_times_F32",	qb_do_refract_multiple_times_F32,	0,	0	},
	{	"qb_do_refract_multiple_times_F64",	qb_do_refract_multiple_times_F64,	0,	0	},
	{	"qb_do_remove_premultiplication_4x_multiple_times_F32",	qb_do_remove_premultiplication_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_remove_premultiplication_4x_multiple_times_F64",	qb_do_remove_premultiplication_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_reverse_sort_F32",	qb_do_reverse_sort_F32,	0,	0	},
	{	"qb_do_reverse_sort_F64",	qb_do_reverse_sort_F64,	0,	0	},
	{	"qb_do_reverse_sort_S08",	qb_do_reverse_sort_S08,	0,	0	},
	{	"qb_do_reverse_sort_S16",	qb_do_reverse_sort_S16,	0,	0	},
	{	"qb_do_reverse_sort_S32",	qb_do_reverse_sort_S32,	0,	0	},
	{	"qb_do_reverse_sort_S64",	qb_do_reverse_sort_S64,	0,	0	},
	{	"qb_do_reverse_sort_U08",	qb_do_reverse_sort_U08,	0,	0	},
	{	"qb_do_reverse_sort_U16",	qb_do_reverse_sort_U16,	0,	0	},
	{	"qb_do_reverse_sort_U32",	qb_do_reverse_sort_U32,	0,	0	},
	{	"qb_do_reverse_sort_U64",	qb_do_reverse_sort_U64,	0,	0	},
	{	"qb_do_rgb2hsl_3x_multiple_times_F32",	qb_do_rgb2hsl_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_rgb2hsl_3x_multiple_times_F64",	qb_do_rgb2hsl_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_rgb2hsl_4x_multiple_times_F32",	qb_do_rgb2hsl_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_rgb2hsl_4x_multiple_times_F64",	qb_do_rgb2hsl_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_rgb2hsv_3x_multiple_times_F32",	qb_do_rgb2hsv_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_rgb2hsv_3x_multiple_times_F64",	qb_do_rgb2hsv_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_rgb2hsv_4x_multiple_times_F32",	qb_do_rgb2hsv_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_rgb2hsv_4x_multiple_times_F64",	qb_do_rgb2hsv_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_round_multiple_times_F32",	qb_do_round_multiple_times_F32,	0,	0	},
	{	"qb_do_round_multiple_times_F64",	qb_do_round_multiple_times_F64,	0,	0	},
	{	"qb_do_rsqrt_multiple_times_F32",	qb_do_rsqrt_multiple_times_F32,	0,	0	},
	{	"qb_do_rsqrt_multiple_times_F64",	qb_do_rsqrt_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_bilinear_2x_F32",	qb_do_sample_bilinear_2x_F32,	0,	0	},
	{	"qb_do_sample_bilinear_2x_F64",	qb_do_sample_bilinear_2x_F64,	0,	0	},
	{	"qb_do_sample_bilinear_2x_multiple_times_F32",	qb_do_sample_bilinear_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_bilinear_2x_multiple_times_F64",	qb_do_sample_bilinear_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_bilinear_3x_F32",	qb_do_sample_bilinear_3x_F32,	0,	0	},
	{	"qb_do_sample_bilinear_3x_F64",	qb_do_sample_bilinear_3x_F64,	0,	0	},
	{	"qb_do_sample_bilinear_3x_multiple_times_F32",	qb_do_sample_bilinear_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_bilinear_3x_multiple_times_F64",	qb_do_sample_bilinear_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_bilinear_4x_F32",	qb_do_sample_bilinear_4x_F32,	0,	0	},
	{	"qb_do_sample_bilinear_4x_F64",	qb_do_sample_bilinear_4x_F64,	0,	0	},
	{	"qb_do_sample_bilinear_4x_multiple_times_F32",	qb_do_sample_bilinear_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_bilinear_4x_multiple_times_F64",	qb_do_sample_bilinear_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_bilinear_F32",	qb_do_sample_bilinear_F32,	0,	0	},
	{	"qb_do_sample_bilinear_F64",	qb_do_sample_bilinear_F64,	0,	0	},
	{	"qb_do_sample_bilinear_multiple_times_F32",	qb_do_sample_bilinear_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_bilinear_multiple_times_F64",	qb_do_sample_bilinear_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_nearest_2x_multiple_times_F32",	qb_do_sample_nearest_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_nearest_2x_multiple_times_F64",	qb_do_sample_nearest_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_nearest_3x_multiple_times_F32",	qb_do_sample_nearest_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_nearest_3x_multiple_times_F64",	qb_do_sample_nearest_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_nearest_4x_multiple_times_F32",	qb_do_sample_nearest_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_nearest_4x_multiple_times_F64",	qb_do_sample_nearest_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_sample_nearest_multiple_times_F32",	qb_do_sample_nearest_multiple_times_F32,	0,	0	},
	{	"qb_do_sample_nearest_multiple_times_F64",	qb_do_sample_nearest_multiple_times_F64,	0,	0	},
	{	"qb_do_scatter_8x_F32",	qb_do_scatter_8x_F32,	0,	0	},
	{	"qb_do_scatter_8x_F64",	qb_do_scatter_8x_F64,	0,	0	},
	{	"qb_do_scatter_8x_I08",	qb_do_scatter_8x_I08,	0,	0	},
	{	"qb_do_scatter_8x_I16",	qb_do_scatter_8x_I16,	0,	0	},
	{	"qb_do_scatter_8x_I32",	qb_do_scatter_8x_I32,	0,	0	},
	{	"qb_do_scatter_8x_I64",	qb_do_scatter_8x_I64,	0,	0	},
	{	"qb_do_set_all_I32",	qb_do_set_all_I32,	0,	0	},
	{	"qb_do_set_any_I32",	qb_do_set_any_I32,	0,	0	},
	{	"qb_do_set_equal_F32",	qb_do_set_equal_F32,	0,	0	},
	{	"qb_do_set_equal_F64",	qb_do_set_equal_F64,	0,	0	},
	{	"qb_do_set_equal_I08",	qb_do_set_equal_I08,	0,	0	},
	{	"qb_do_set_equal_I16",	qb_do_set_equal_I16,	0,	0	},
	{	"qb_do_set_equal_I32",	qb_do_set_equal_I32,	0,	0	},
	{	"qb_do_set_equal_I64",	qb_do_set_equal_I64,	0,	0	},
	{	"qb_do_set_less_than_F32",	qb_do_set_less_than_F32,	0,	0	},
	{	"qb_do_set_less_than_F64",	qb_do_set_less_than_F64,	0,	0	},
	{	"qb_do_set_less_than_S08",	qb_do_set_less_than_S08,	0,	0	},
	{	"qb_do_set_less_than_S16",	qb_do_set_less_than_S16,	0,	0	},
	{	"qb_do_set_less_than_S32",	qb_do_set_less_than_S32,	0,	0	},
	{	"qb_do_set_less_than_S64",	qb_do_set_less_than_S64,	0,	0	},
	{	"qb_do_set_less_than_U08",	qb_do_set_less_than_U08,	0,	0	},
	{	"qb_do_set_less_than_U16",	qb_do_set_less_than_U16,	0,	0	},
	{	"qb_do_set_less_than_U32",	qb_do_set_less_than_U32,	0,	0	},
	{	"qb_do_set_less_than_U64",	qb_do_set_less_than_U64,	0,	0	},
	{	"qb_do_set_less_than_equal_F32",	qb_do_set_less_than_equal_F32,	0,	0	},
	{	"qb_do_set_less_than_equal_F64",	qb_do_set_less_than_equal_F64,	0,	0	},
	{	"qb_do_set_less_than_equal_S08",	qb_do_set_less_than_equal_S08,	0,	0	},
	{	"qb_do_set_less_than_equal_S16",	qb_do_set_less_than_equal_S16,	0,	0	},
	{	"qb_do_set_less_than_equal_S32",	qb_do_set_less_than_equal_S32,	0,	0	},
	{	"qb_do_set_less_than_equal_S64",	qb_do_set_less_than_equal_S64,	0,	0	},
	{	"qb_do_set_less_than_equal_U08",	qb_do_set_less_than_equal_U08,	0,	0	},
	{	"qb_do_set_less_than_equal_U16",	qb_do_set_less_than_equal_U16,	0,	0	},
	{	"qb_do_set_less_than_equal_U32",	qb_do_set_less_than_equal_U32,	0,	0	},
	{	"qb_do_set_less_than_equal_U64",	qb_do_set_less_than_equal_U64,	0,	0	},
	{	"qb_do_set_not_I32",	qb_do_set_not_I32,	0,	0	},
	{	"qb_do_set_not_equal_F32",	qb_do_set_not_equal_F32,	0,	0	},
	{	"qb_do_set_not_equal_F64",	qb_do_set_not_equal_F64,	0,	0	},
	{	"qb_do_set_not_equal_I08",	qb_do_set_not_equal_I08,	0,	0	},
	{	"qb_do_set_not_equal_I16",	qb_do_set_not_equal_I16,	0,	0	},
	{	"qb_do_set_not_equal_I32",	qb_do_set_not_equal_I32,	0,	0	},
	{	"qb_do_set_not_equal_I64",	qb_do_set_not_equal_I64,	0,	0	},
	{	"qb_do_shift_left_multiple_times_S08",	qb_do_shift_left_multiple_times_S08,	0,	0	},
	{	"qb_do_shift_left_multiple_times_S16",	qb_do_shift_left_multiple_times_S16,	0,	0	},
	{	"qb_do_shift_left_multiple_times_S32",	qb_do_shift_left_multiple_times_S32,	0,	0	},
	{	"qb_do_shift_left_multiple_times_S64",	qb_do_shift_left_multiple_times_S64,	0,	0	},
	{	"qb_do_shift_left_multiple_times_U08",	qb_do_shift_left_multiple_times_U08,	0,	0	},
	{	"qb_do_shift_left_multiple_times_U16",	qb_do_shift_left_multiple_times_U16,	0,	0	},
	{	"qb_do_shift_left_multiple_times_U32",	qb_do_shift_left_multiple_times_U32,	0,	0	},
	{	"qb_do_shift_left_multiple_times_U64",	qb_do_shift_left_multiple_times_U64,	0,	0	},
	{	"qb_do_shift_right_multiple_times_S08",	qb_do_shift_right_multiple_times_S08,	0,	0	},
	{	"qb_do_shift_right_multiple_times_S16",	qb_do_shift_right_multiple_times_S16,	0,	0	},
	{	"qb_do_shift_right_multiple_times_S32",	qb_do_shift_right_multiple_times_S32,	0,	0	},
	{	"qb_do_shift_right_multiple_times_S64",	qb_do_shift_right_multiple_times_S64,	0,	0	},
	{	"qb_do_shift_right_multiple_times_U08",	qb_do_shift_right_multiple_times_U08,	0,	0	},
	{	"qb_do_shift_right_multiple_times_U16",	qb_do_shift_right_multiple_times_U16,	0,	0	},
	{	"qb_do_shift_right_multiple_times_U32",	qb_do_shift_right_multiple_times_U32,	0,	0	},
	{	"qb_do_shift_right_multiple_times_U64",	qb_do_shift_right_multiple_times_U64,	0,	0	},
	{	"qb_do_shuffle_F32",	qb_do_shuffle_F32,	0,	0	},
	{	"qb_do_shuffle_F64",	qb_do_shuffle_F64,	0,	0	},
	{	"qb_do_shuffle_I08",	qb_do_shuffle_I08,	0,	0	},
	{	"qb_do_shuffle_I16",	qb_do_shuffle_I16,	0,	0	},
	{	"qb_do_shuffle_I32",	qb_do_shuffle_I32,	0,	0	},
	{	"qb_do_shuffle_I64",	qb_do_shuffle_I64,	0,	0	},
	{	"qb_do_sign_multiple_times_F32",	qb_do_sign_multiple_times_F32,	0,	0	},
	{	"qb_do_sign_multiple_times_F64",	qb_do_sign_multiple_times_F64,	0,	0	},
	{	"qb_do_sin_multiple_times_F32",	qb_do_sin_multiple_times_F32,	0,	0	},
	{	"qb_do_sin_multiple_times_F64",	qb_do_sin_multiple_times_F64,	0,	0	},
	{	"qb_do_sinh_multiple_times_F32",	qb_do_sinh_multiple_times_F32,	0,	0	},
	{	"qb_do_sinh_multiple_times_F64",	qb_do_sinh_multiple_times_F64,	0,	0	},
	{	"qb_do_smooth_step_multiple_times_F32",	qb_do_smooth_step_multiple_times_F32,	0,	0	},
	{	"qb_do_smooth_step_multiple_times_F64",	qb_do_smooth_step_multiple_times_F64,	0,	0	},
	{	"qb_do_sort_F32",	qb_do_sort_F32,	0,	0	},
	{	"qb_do_sort_F64",	qb_do_sort_F64,	0,	0	},
	{	"qb_do_sort_S08",	qb_do_sort_S08,	0,	0	},
	{	"qb_do_sort_S16",	qb_do_sort_S16,	0,	0	},
	{	"qb_do_sort_S32",	qb_do_sort_S32,	0,	0	},
	{	"qb_do_sort_S64",	qb_do_sort_S64,	0,	0	},
	{	"qb_do_sort_U08",	qb_do_sort_U08,	0,	0	},
	{	"qb_do_sort_U16",	qb_do_sort_U16,	0,	0	},
	{	"qb_do_sort_U32",	qb_do_sort_U32,	0,	0	},
	{	"qb_do_sort_U64",	qb_do_sort_U64,	0,	0	},
	{	"qb_do_sqrt_multiple_times_F32",	qb_do_sqrt_multiple_times_F32,	0,	0	},
	{	"qb_do_sqrt_multiple_times_F64",	qb_do_sqrt_multiple_times_F64,	0,	0	},
	{	"qb_do_step_multiple_times_F32",	qb_do_step_multiple_times_F32,	0,	0	},
	{	"qb_do_step_multiple_times_F64",	qb_do_step_multiple_times_F64,	0,	0	},
	{	"qb_do_subarray_position_F32",	qb_do_subarray_position_F32,	0,	0	},
	{	"qb_do_subarray_position_F64",	qb_do_subarray_position_F64,	0,	0	},
	{	"qb_do_subarray_position_I08",	qb_do_subarray_position_I08,	0,	0	},
	{	"qb_do_subarray_position_I16",	qb_do_subarray_position_I16,	0,	0	},
	{	"qb_do_subarray_position_I32",	qb_do_subarray_position_I32,	0,	0	},
	{	"qb_do_subarray_position_I64",	qb_do_subarray_position_I64,	0,	0	},
	{	"qb_do_subarray_position_from_end_F32",	qb_do_subarray_position_from_end_F32,	0,	0	},
	{	"qb_do_subarray_position_from_end_F64",	qb_do_subarray_position_from_end_F64,	0,	0	},
	{	"qb_do_subarray_position_from_end_I08",	qb_do_subarray_position_from_end_I08,	0,	0	},
	{	"qb_do_subarray_position_from_end_I16",	qb_do_subarray_position_from_end_I16,	0,	0	},
	{	"qb_do_subarray_position_from_end_I32",	qb_do_subarray_position_from_end_I32,	0,	0	},
	{	"qb_do_subarray_position_from_end_I64",	qb_do_subarray_position_from_end_I64,	0,	0	},
	{	"qb_do_subtract_2x_multiple_times_F32",	qb_do_subtract_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_subtract_2x_multiple_times_F64",	qb_do_subtract_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_subtract_3x_multiple_times_F32",	qb_do_subtract_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_subtract_3x_multiple_times_F64",	qb_do_subtract_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_subtract_4x_multiple_times_F32",	qb_do_subtract_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_subtract_4x_multiple_times_F64",	qb_do_subtract_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_subtract_multiple_times_F32",	qb_do_subtract_multiple_times_F32,	0,	0	},
	{	"qb_do_subtract_multiple_times_F64",	qb_do_subtract_multiple_times_F64,	0,	0	},
	{	"qb_do_subtract_multiple_times_I08",	qb_do_subtract_multiple_times_I08,	0,	0	},
	{	"qb_do_subtract_multiple_times_I16",	qb_do_subtract_multiple_times_I16,	0,	0	},
	{	"qb_do_subtract_multiple_times_I32",	qb_do_subtract_multiple_times_I32,	0,	0	},
	{	"qb_do_subtract_multiple_times_I64",	qb_do_subtract_multiple_times_I64,	0,	0	},
	{	"qb_do_tan_multiple_times_F32",	qb_do_tan_multiple_times_F32,	0,	0	},
	{	"qb_do_tan_multiple_times_F64",	qb_do_tan_multiple_times_F64,	0,	0	},
	{	"qb_do_tanh_multiple_times_F32",	qb_do_tanh_multiple_times_F32,	0,	0	},
	{	"qb_do_tanh_multiple_times_F64",	qb_do_tanh_multiple_times_F64,	0,	0	},
	{	"qb_do_transform_vector_2x_multiple_times_column_major_F32",	qb_do_transform_vector_2x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_transform_vector_2x_multiple_times_column_major_F64",	qb_do_transform_vector_2x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_transform_vector_2x_multiple_times_row_major_F32",	qb_do_transform_vector_2x_multiple_times_row_major_F32,	0,	0	},
	{	"qb_do_transform_vector_2x_multiple_times_row_major_F64",	qb_do_transform_vector_2x_multiple_times_row_major_F64,	0,	0	},
	{	"qb_do_transform_vector_3x_multiple_times_column_major_F32",	qb_do_transform_vector_3x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_transform_vector_3x_multiple_times_column_major_F64",	qb_do_transform_vector_3x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_transform_vector_3x_multiple_times_row_major_F32",	qb_do_transform_vector_3x_multiple_times_row_major_F32,	0,	0	},
	{	"qb_do_transform_vector_3x_multiple_times_row_major_F64",	qb_do_transform_vector_3x_multiple_times_row_major_F64,	0,	0	},
	{	"qb_do_transform_vector_4x_multiple_times_column_major_F32",	qb_do_transform_vector_4x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_do_transform_vector_4x_multiple_times_column_major_F64",	qb_do_transform_vector_4x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_do_transform_vector_4x_multiple_times_row_major_F32",	qb_do_transform_vector_4x_multiple_times_row_major_F32,	0,	0	},
	{	"qb_do_transform_vector_4x_multiple_times_row_major_F64",	qb_do_transform_vector_4x_multiple_times_row_major_F64,	0,	0	},
	{	"qb_do_transpose_matrix_2x_multiple_times_F32",	qb_do_transpose_matrix_2x_multiple_times_F32,	0,	0	},
	{	"qb_do_transpose_matrix_2x_multiple_times_F64",	qb_do_transpose_matrix_2x_multiple_times_F64,	0,	0	},
	{	"qb_do_transpose_matrix_3x_F32",	qb_do_transpose_matrix_3x_F32,	0,	0	},
	{	"qb_do_transpose_matrix_3x_F64",	qb_do_transpose_matrix_3x_F64,	0,	0	},
	{	"qb_do_transpose_matrix_3x_multiple_times_F32",	qb_do_transpose_matrix_3x_multiple_times_F32,	0,	0	},
	{	"qb_do_transpose_matrix_3x_multiple_times_F64",	qb_do_transpose_matrix_3x_multiple_times_F64,	0,	0	},
	{	"qb_do_transpose_matrix_4x_F32",	qb_do_transpose_matrix_4x_F32,	0,	0	},
	{	"qb_do_transpose_matrix_4x_F64",	qb_do_transpose_matrix_4x_F64,	0,	0	},
	{	"qb_do_transpose_matrix_4x_multiple_times_F32",	qb_do_transpose_matrix_4x_multiple_times_F32,	0,	0	},
	{	"qb_do_transpose_matrix_4x_multiple_times_F64",	qb_do_transpose_matrix_4x_multiple_times_F64,	0,	0	},
	{	"qb_do_transpose_matrix_F32",	qb_do_transpose_matrix_F32,	0,	0	},
	{	"qb_do_transpose_matrix_F64",	qb_do_transpose_matrix_F64,	0,	0	},
	{	"qb_do_transpose_matrix_multiple_times_F32",	qb_do_transpose_matrix_multiple_times_F32,	0,	0	},
	{	"qb_do_transpose_matrix_multiple_times_F64",	qb_do_transpose_matrix_multiple_times_F64,	0,	0	},
	{	"qb_do_utf8decode_U16",	qb_do_utf8decode_U16,	0,	0	},
	{	"qb_do_utf8decode_U32",	qb_do_utf8decode_U32,	0,	0	},
	{	"qb_do_utf8decode_count_U16",	qb_do_utf8decode_count_U16,	0,	0	},
	{	"qb_do_utf8encode_U16",	qb_do_utf8encode_U16,	0,	0	},
	{	"qb_do_utf8encode_U32",	qb_do_utf8encode_U32,	0,	0	},
	{	"qb_do_utf8encode_count_U16",	qb_do_utf8encode_count_U16,	0,	0	},
	{	"qb_do_utf8encode_count_U32",	qb_do_utf8encode_count_U32,	0,	0	},
	{	"qb_redirect_alpha_blend_2x_multiple_times_F32",	qb_redirect_alpha_blend_2x_multiple_times_F32,	0,	0	},
	{	"qb_redirect_alpha_blend_4x_multiple_times_F32",	qb_redirect_alpha_blend_4x_multiple_times_F32,	0,	0	},
	{	"qb_redirect_apply_premultiplication_4x_multiple_times_F32",	qb_redirect_apply_premultiplication_4x_multiple_times_F32,	0,	0	},
	{	"qb_redirect_remove_premultiplication_4x_multiple_times_F32",	qb_redirect_remove_premultiplication_4x_multiple_times_F32,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F32",	qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F32",	qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F32",	qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F32,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F32",	qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F32,	0,	0	},
	{	"qb_redirect_alpha_blend_2x_multiple_times_F64",	qb_redirect_alpha_blend_2x_multiple_times_F64,	0,	0	},
	{	"qb_redirect_alpha_blend_4x_multiple_times_F64",	qb_redirect_alpha_blend_4x_multiple_times_F64,	0,	0	},
	{	"qb_redirect_apply_premultiplication_4x_multiple_times_F64",	qb_redirect_apply_premultiplication_4x_multiple_times_F64,	0,	0	},
	{	"qb_redirect_remove_premultiplication_4x_multiple_times_F64",	qb_redirect_remove_premultiplication_4x_multiple_times_F64,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F64",	qb_redirect_multiply_matrix_by_vector_4x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F64",	qb_redirect_multiply_matrix_by_vector_3x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F64",	qb_redirect_multiply_matrix_by_vector_2x_multiple_times_column_major_F64,	0,	0	},
	{	"qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F64",	qb_redirect_multiply_matrix_by_vector_multiple_times_column_major_F64,	0,	0	},
	{	"qb_redirect_print_variable_U32",	qb_redirect_print_variable_U32,	0,	0	},
	{	"qb_redirect_print_variable_array_element_U32",	qb_redirect_print_variable_array_element_U32,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_U32",	qb_redirect_print_variable_multiple_times_U32,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_U32",	qb_redirect_print_multidimensional_variable_U32,	0,	0	},
	{	"qb_redirect_print_variable_S32",	qb_redirect_print_variable_S32,	0,	0	},
	{	"qb_redirect_print_variable_array_element_S32",	qb_redirect_print_variable_array_element_S32,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_S32",	qb_redirect_print_variable_multiple_times_S32,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_S32",	qb_redirect_print_multidimensional_variable_S32,	0,	0	},
	{	"qb_redirect_print_variable_F32",	qb_redirect_print_variable_F32,	0,	0	},
	{	"qb_redirect_print_variable_array_element_F32",	qb_redirect_print_variable_array_element_F32,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_F32",	qb_redirect_print_variable_multiple_times_F32,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_F32",	qb_redirect_print_multidimensional_variable_F32,	0,	0	},
	{	"qb_redirect_print_variable_F64",	qb_redirect_print_variable_F64,	0,	0	},
	{	"qb_redirect_print_variable_array_element_F64",	qb_redirect_print_variable_array_element_F64,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_F64",	qb_redirect_print_variable_multiple_times_F64,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_F64",	qb_redirect_print_multidimensional_variable_F64,	0,	0	},
	{	"qb_redirect_print_variable_S08",	qb_redirect_print_variable_S08,	0,	0	},
	{	"qb_redirect_print_variable_array_element_S08",	qb_redirect_print_variable_array_element_S08,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_S08",	qb_redirect_print_variable_multiple_times_S08,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_S08",	qb_redirect_print_multidimensional_variable_S08,	0,	0	},
	{	"qb_redirect_print_string_U08",	qb_redirect_print_string_U08,	0,	0	},
	{	"qb_redirect_print_variable_U08",	qb_redirect_print_variable_U08,	0,	0	},
	{	"qb_redirect_print_variable_array_element_U08",	qb_redirect_print_variable_array_element_U08,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_U08",	qb_redirect_print_variable_multiple_times_U08,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_U08",	qb_redirect_print_multidimensional_variable_U08,	0,	0	},
	{	"qb_redirect_print_variable_S16",	qb_redirect_print_variable_S16,	0,	0	},
	{	"qb_redirect_print_variable_array_element_S16",	qb_redirect_print_variable_array_element_S16,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_S16",	qb_redirect_print_variable_multiple_times_S16,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_S16",	qb_redirect_print_multidimensional_variable_S16,	0,	0	},
	{	"qb_redirect_print_variable_U16",	qb_redirect_print_variable_U16,	0,	0	},
	{	"qb_redirect_print_variable_array_element_U16",	qb_redirect_print_variable_array_element_U16,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_U16",	qb_redirect_print_variable_multiple_times_U16,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_U16",	qb_redirect_print_multidimensional_variable_U16,	0,	0	},
	{	"qb_redirect_print_variable_S64",	qb_redirect_print_variable_S64,	0,	0	},
	{	"qb_redirect_print_variable_array_element_S64",	qb_redirect_print_variable_array_element_S64,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_S64",	qb_redirect_print_variable_multiple_times_S64,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_S64",	qb_redirect_print_multidimensional_variable_S64,	0,	0	},
	{	"qb_redirect_print_variable_U64",	qb_redirect_print_variable_U64,	0,	0	},
	{	"qb_redirect_print_variable_array_element_U64",	qb_redirect_print_variable_array_element_U64,	0,	0	},
	{	"qb_redirect_print_variable_multiple_times_U64",	qb_redirect_print_variable_multiple_times_U64,	0,	0	},
	{	"qb_redirect_print_multidimensional_variable_U64",	qb_redirect_print_multidimensional_variable_U64,	0,	0	},
	{	"qb_dispatch_instruction_ARR_ARR",	qb_dispatch_instruction_ARR_ARR,	0,	0	},
	{	"qb_dispatch_instruction_ARR_ARR_ARR",	qb_dispatch_instruction_ARR_ARR_ARR,	0,	0	},
	{	"qb_dispatch_instruction_ARR_ARR_SCA_SCA_ARR",	qb_dispatch_instruction_ARR_ARR_SCA_SCA_ARR,	0,	0	},
	{	"qb_do_check_index_add_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_check_index_multiply_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_check_index_multiply_add_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_S08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_S16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_S32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_S64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_U08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_U16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_divide_U64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_extent_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_extent_multiply_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_extent_subtract_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_extent_subtract_multiply_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_index_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_index_add_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_index_multiply_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_index_multiply_add_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_guard_size_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_S08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_S16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_S32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_S64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_U08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_U16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_modulo_U64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate2dcross_product_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate3dcross_product_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate4dcross_product_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_matrix_by_matrix_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_matrix_by_vector_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_square_matrix_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_transform_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_vector_by_matrix_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_validate_vector_widths_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_index_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_index_multiply_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_push_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_2_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_3_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_4_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_5_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_6_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_copy_dimension_7_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_accommodate_size_update_dimension_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_apply_premultiplication_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_apply_premultiplication_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_array_pad_count_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_choose_size_larger_of_two_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_choose_size_larger_of_two_top_level_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_choose_size_largest_of_three_top_level_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_clamp_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_clamp_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_cross_product_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_determinant_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_determinant_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_determinant_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_determinant_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_distance_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_face_forward_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_2x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_3x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_4x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_5x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_6x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_gather_7x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_hsl2rgb_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_hsl2rgb_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_hsv2rgb_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_hsv2rgb_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_length_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_matrix_2x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_matrix_2x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_2x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_2x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_3x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_3x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_4x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_4x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_matrix_by_vector_padded_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_2x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_2x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_3x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_3x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_4x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_4x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_multiply_vector_by_matrix_padded_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_normalize_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_pack_big_endian_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_pack_big_endian_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_pack_little_endian_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_pack_little_endian_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_S08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_S16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_S32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_S64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_U08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_U16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_U32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_range_count_U64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_reflect_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_refract_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_remove_premultiplication_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_remove_premultiplication_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_rgb2hsl_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_rgb2hsl_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_rgb2hsv_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_rgb2hsv_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sample_nearest_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_2x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_3x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_4x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_5x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_6x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_I08",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_I16",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_I32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_scatter_7x_I64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sign_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_sign_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_smooth_step_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_smooth_step_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_2x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_2x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_2x_row_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_2x_row_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_3x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_3x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_3x_row_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_3x_row_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_4x_column_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_4x_column_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_4x_row_major_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transform_vector_4x_row_major_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transpose_matrix_2x_F32",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"qb_do_transpose_matrix_2x_F64",	NULL,	0,	QB_NATIVE_SYMBOL_INLINE_FUNCTION	},
	{	"_ftol2",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_ftol2_sse",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_allshr",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_allshl",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIacos",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIasin",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIatan",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIatan2",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIcos",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIcosh",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIexp",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIfmod",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIlog",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIlog10",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIpow",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIsin",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIsinh",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CIsqrt",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CItan",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_CItanh",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_acos",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_acosf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_asin",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_asinf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_atan",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_atan2",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_atanf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_cos",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_cosf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_exp",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_expf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_log",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_log10",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_log10f",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_logf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_pow",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_powf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_sin",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_sinf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_tan",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"__libm_sse2_tanf",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_acos_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_asin_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_atan_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_cos_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_exp_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_log10_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_log_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_pow_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_sin_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_sqrt_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
	{	"_libm_sse2_tan_precise",	NULL,	0,	QB_NATIVE_SYMBOL_INTRINSIC_FUNCTION	},
};

uint32_t global_native_symbol_count = 1563;

