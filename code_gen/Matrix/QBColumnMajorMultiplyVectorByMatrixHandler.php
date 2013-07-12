<?php

class QBColumnMajorMultiplyVectorByMatrixHandler extends QBColumnMajorMultiplyMatrixByMatrixHandler {

	public function getHelperFunctions() {
		$type = $this->getOperandType(1);
		$cType = $this->getOperandCType(1);
		$functions = array(
			array(
				"static void ZEND_FASTCALL qb_multiply_vector_by_cm_matrix_2x2_$type($cType *op1_start, $cType *op1_end, $cType *op2_start, $cType *op2_end, $cType *res_start, $cType *res_end) {",
					"$cType *__restrict res_ptr = res_start;",
					"$cType *__restrict op1_ptr = op1_start;",
					"$cType *__restrict op2_ptr = op2_start;",
					"for(;;) {",
						"$cType dot_product0 = (op1_ptr[0] * op2_ptr[0 * 2 + 0]) + (op1_ptr[1] * op2_ptr[0 * 2 + 1]);",
						"$cType dot_product1 = (op1_ptr[0] * op2_ptr[1 * 2 + 0]) + (op1_ptr[1] * op2_ptr[1 * 2 + 1]);",
						"res_ptr[0] = dot_product0;",
						"res_ptr[1] = dot_product1;",
						"res_ptr += 2;",
						"if(res_ptr >= res_end) {",
							"break;",
						"}",
						"op1_ptr += 2;",
						"if(op1_ptr >= op1_end) {",
							"op1_ptr = op1_start;",
						"}",
						"op2_ptr += 4;",
						"if(op2_ptr >= op2_end) {",
							"op2_ptr = op2_start;",
						"}",
					"}",
				"}",
			),
			array(
				"static void ZEND_FASTCALL qb_multiply_vector_by_cm_matrix_3x3_$type($cType *op1_start, $cType *op1_end, $cType *op2_start, $cType *op2_end, $cType *res_start, $cType *res_end) {",
					"$cType *__restrict res_ptr = res_start;",
					"$cType *__restrict op1_ptr = op1_start;",
					"$cType *__restrict op2_ptr = op2_start;",
					"for(;;) {",
						"$cType dot_product0 = (op1_ptr[0] * op2_ptr[0 * 3 + 0]) + (op1_ptr[1] * op2_ptr[0 * 3 + 1]) + (op1_ptr[2] * op2_ptr[0 * 3 + 2]);",
						"$cType dot_product1 = (op1_ptr[0] * op2_ptr[1 * 3 + 0]) + (op1_ptr[1] * op2_ptr[1 * 3 + 1]) + (op1_ptr[2] * op2_ptr[1 * 3 + 2]);",
						"$cType dot_product2 = (op1_ptr[0] * op2_ptr[2 * 3 + 0]) + (op1_ptr[1] * op2_ptr[2 * 3 + 1]) + (op1_ptr[2] * op2_ptr[2 * 3 + 2]);",
						"res_ptr[0] = dot_product0;",
						"res_ptr[1] = dot_product1;",
						"res_ptr[2] = dot_product2;",
						"res_ptr += 3;",
						"if(res_ptr >= res_end) {",
							"break;",
						"}",
						"op1_ptr += 3;",
						"if(op1_ptr >= op1_end) {",
							"op1_ptr = op1_start;",
						"}",
						"op2_ptr += 9;",
						"if(op2_ptr >= op2_end) {",
							"op2_ptr = op2_start;",
						"}",
					"}",
				"}",
			),
			array(
				"static void ZEND_FASTCALL qb_multiply_vector_by_cm_matrix_3x3_padded_$type($cType *op1_start, $cType *op1_end, $cType *op2_start, $cType *op2_end, $cType *res_start, $cType *res_end) {",
					"$cType *__restrict res_ptr = res_start;",
					"$cType *__restrict op1_ptr = op1_start;",
					"$cType *__restrict op2_ptr = op2_start;",
					"for(;;) {",
						"$cType dot_product0 = (op1_ptr[0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[1] * op2_ptr[0 * 4 + 1]) + (op1_ptr[2] * op2_ptr[0 * 4 + 2]);",
						"$cType dot_product1 = (op1_ptr[0] * op2_ptr[1 * 4 + 0]) + (op1_ptr[1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[2] * op2_ptr[1 * 4 + 2]);",
						"$cType dot_product2 = (op1_ptr[0] * op2_ptr[2 * 4 + 0]) + (op1_ptr[1] * op2_ptr[2 * 4 + 1]) + (op1_ptr[2] * op2_ptr[2 * 4 + 2]);",
						"res_ptr[0] = dot_product0;",
						"res_ptr[1] = dot_product1;",
						"res_ptr[2] = dot_product2;",
						"res_ptr += 4;",
						"if(res_ptr >= res_end) {",
							"break;",
						"}",
						"op1_ptr += 4;",
						"if(op1_ptr >= op1_end) {",
							"op1_ptr = op1_start;",
						"}",
						"op2_ptr += 12;",
						"if(op2_ptr >= op2_end) {",
							"op2_ptr = op2_start;",
						"}",
					"}",
				"}",
			),
			array(
				"static void ZEND_FASTCALL qb_multiply_vector_by_cm_matrix_4x4_$type($cType *op1_start, $cType *op1_end, $cType *op2_start, $cType *op2_end, $cType *res_start, $cType *res_end) {",
					"$cType *__restrict res_ptr = res_start;",
					"$cType *__restrict op1_ptr = op1_start;",
					"$cType *__restrict op2_ptr = op2_start;",
					"for(;;) {",
						"$cType dot_product0 = (op1_ptr[0] * op2_ptr[0 * 4 + 0]) + (op1_ptr[1] * op2_ptr[0 * 4 + 1]) + (op1_ptr[2] * op2_ptr[0 * 4 + 2]) + (op1_ptr[3] * op2_ptr[0 * 4 + 3]);",
						"$cType dot_product1 = (op1_ptr[0] * op2_ptr[1 * 4 + 0]) + (op1_ptr[1] * op2_ptr[1 * 4 + 1]) + (op1_ptr[2] * op2_ptr[1 * 4 + 2]) + (op1_ptr[3] * op2_ptr[1 * 4 + 3]);",
						"$cType dot_product2 = (op1_ptr[0] * op2_ptr[2 * 4 + 0]) + (op1_ptr[1] * op2_ptr[2 * 4 + 1]) + (op1_ptr[2] * op2_ptr[2 * 4 + 2]) + (op1_ptr[3] * op2_ptr[2 * 4 + 3]);",
						"$cType dot_product3 = (op1_ptr[0] * op2_ptr[3 * 4 + 0]) + (op1_ptr[1] * op2_ptr[3 * 4 + 1]) + (op1_ptr[2] * op2_ptr[3 * 4 + 2]) + (op1_ptr[3] * op2_ptr[3 * 4 + 3]);",
						"res_ptr[0] = dot_product0;",
						"res_ptr[1] = dot_product1;",
						"res_ptr[2] = dot_product2;",
						"res_ptr[3] = dot_product3;",
						"res_ptr += 4;",
						"if(res_ptr >= res_end) {",
							"break;",
						"}",
						"op1_ptr += 4;",
						"if(op1_ptr >= op1_end) {",
							"op1_ptr = op1_start;",
						"}",
						"op2_ptr += 16;",
						"if(op2_ptr >= op2_end) {",
							"op2_ptr = op2_start;",
						"}",
					"}",
				"}",
			),
			array(
				"static void ZEND_FASTCALL qb_multiply_vector_by_cm_matrix_$type($cType *op1_start, $cType *op1_end, uint32_t v_col, $cType *op2_start, $cType *op2_end, uint32_t m_row, uint32_t m_col, $cType *res_start, $cType *res_end) {",
					"ALLOCA_FLAG(use_heap)",
					"$cType *buffer = do_alloca(m_row * sizeof($cType), use_heap);",
					"$cType *__restrict res_ptr = res_start;",
					"$cType *__restrict op1_ptr = op1_start;",
					"$cType *__restrict op2_ptr = op2_start;",
					"for(;;) {",
					"uint32_t i, j, k;",
						"for(i = 0; i < m_col; ++i) {",
							"$cType dot_product = 0;",
							"for(j = 0, k = 0; j < m_row; ++j) {",
								"dot_product += op1_ptr[j] * op2_ptr[k + i];",
								"k += m_col;",
							"}",
							"buffer[i] = dot_product;",
						"}",
						"memcpy(res_ptr, buffer, m_col * sizeof($cType));",
						"res_ptr += m_col;",
						"if(res_ptr >= res_end) {",
							"break;",
						"}",
						"op1_ptr += v_col;",
						"if(op1_ptr >= op1_end) {",
							"op1_ptr = op1_start;",
						"}",
						"op2_ptr += m_row * m_col;",
						"if(op2_ptr >= op2_end) {",
							"op2_ptr = op2_start;",
						"}",
					"}",
					"free_alloca(buffer, use_heap);",
				"}",
			),
		);
		return $functions;
	}

	public function getOperandSize($i) {
		if($this->operandSize == "variable") {
			switch($i) {
				case 1: return "(1 * MATRIX1_COLS)";
				case 2: return "(MATRIX2_ROWS * MATRIX2_COLS)";
				case 3: return "(1 * MATRIX2_COLS)";
			}
		} else {
			switch($i) {
				case 1: return $this->operandSize;
				case 2: return ($this->operandSize + $this->operandPadding) * $this->operandSize;
				case 3: return $this->operandSize;
			}
		}
	}
		
	public function getAction() {
		$type = $this->getOperandType(1);
		if($this->operandSize == "variable") {
			if($this->addressMode == "ARR") {
				return "qb_multiply_vector_by_cm_matrix_$type(op1_start, op1_end, MATRIX1_COLS, op2_start, op2_end, MATRIX2_ROWS, MATRIX2_COLS, res_start, res_end);";
			} else {
				return "qb_multiply_vector_by_cm_matrix_$type(op1_ptr, NULL, MATRIX1_COLS, op2_ptr, NULL, MATRIX2_ROWS, MATRIX2_COLS, res_ptr, NULL);";
			}
		} else {
			if($this->operandPadding) {
				if($this->addressMode == "ARR") {
					return "qb_multiply_vector_by_cm_matrix_{$this->operandSize}x{$this->operandSize}_padded_$type(op1_start, op1_end, op2_start, op2_end, res_start, res_end);";
				} else {
					return "qb_multiply_vector_by_cm_matrix_{$this->operandSize}x{$this->operandSize}_padded_$type(op1_ptr, NULL, op2_ptr, NULL, res_ptr, NULL);";
				}
			} else {
				if($this->addressMode == "ARR") {
					return "qb_multiply_vector_by_cm_matrix_{$this->operandSize}x{$this->operandSize}_$type(op1_start, op1_end, op2_start, op2_end, res_start, res_end);";
				} else {
					return "qb_multiply_vector_by_cm_matrix_{$this->operandSize}x{$this->operandSize}_$type(op1_ptr, NULL, op2_ptr, NULL, res_ptr, NULL);";
				}
			}
		}
	}
}

?>