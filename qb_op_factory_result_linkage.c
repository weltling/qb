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

// link all operands to the result generated by the op
static int32_t qb_link_results_all_operands(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	uint32_t i;
	for(i = 0; i < operand_count; i++) {
		qb_operand *value = &operands[i];
		if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
			value->result_prototype->parent = result_prototype;
		}
	}
	return TRUE;
}

// link the value to the variable
static int32_t qb_link_results_variable(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *variable = &operands[0];
	qb_operand *value = &operands[1];

	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		// indicate that the destination is the r-value
		qb_result_destination *destination = qb_allocate_result_destination(cxt->pool);
		destination->type = QB_RESULT_DESTINATION_VARIABLE;
		destination->variable = *variable;
		destination->prototype = result_prototype;
		value->result_prototype->destination = destination;
	}
	if(variable->type == QB_OPERAND_EMPTY) {
		// the variable doesn't really need to be there--try to bypass the assignment 
		result_prototype->address_flags |= QB_ADDRESS_TEMPORARY;
	} else if(variable->type == QB_OPERAND_RESULT_PROTOTYPE) {
		if(variable->result_prototype->address_flags & QB_ADDRESS_TEMPORARY) {
			result_prototype->address_flags |= QB_ADDRESS_TEMPORARY;
		}
	}
	return TRUE;
}

// link the value to the array element 
static int32_t qb_link_results_array_element(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *container = &operands[0];
	qb_operand *index = &operands[1];
	qb_operand *value = &operands[2];

	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		qb_result_destination *destination = qb_allocate_result_destination(cxt->pool);
		destination->type = QB_RESULT_DESTINATION_ELEMENT;
		destination->element.container = *container;
		destination->element.index = *index;
		destination->prototype = result_prototype;
		value->result_prototype->destination = destination;
	}
	return TRUE;
}

// link the value to the object property
static int32_t qb_link_results_assign_return_value(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *value = &operands[0];
	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		qb_result_destination *destination = qb_allocate_result_destination(cxt->pool);
		destination->type = QB_RESULT_DESTINATION_RETURN;
		destination->prototype = result_prototype;
		value->result_prototype->destination = destination;
	}
	return TRUE;
}

// link the value to the print operator
static int32_t qb_link_results_print(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *value = &operands[0];

	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		qb_result_destination *destination = qb_allocate_result_destination(cxt->pool);
		destination->type = QB_RESULT_DESTINATION_PRINT;
		destination->prototype = result_prototype;
		value->result_prototype->destination = destination;
	}
	return TRUE;
}

// link the value to the object property
static int32_t qb_link_results_free(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *value = &operands[0];
	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		qb_result_destination *destination = qb_allocate_result_destination(cxt->pool);
		destination->type = QB_RESULT_DESTINATION_FREE;
		destination->prototype = result_prototype;
		value->result_prototype->destination = destination;
	}
	return TRUE;
}

static int32_t qb_link_results_array_init(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *value = &operands[0];
	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		value->result_prototype->parent = result_prototype;
	}
	return TRUE;
}

static int32_t qb_link_results_array_append(qb_compiler_context *cxt, qb_op_factory *f, qb_operand *operands, uint32_t operand_count, qb_result_prototype *result_prototype) {
	qb_operand *value = &operands[0];
	if(value->type == QB_OPERAND_RESULT_PROTOTYPE) {
		value->result_prototype->parent = result_prototype;
	}
	return TRUE;
}
