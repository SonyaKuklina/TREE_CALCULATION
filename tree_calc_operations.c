#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "tree_calc_private.h"
#include "tree_calc_operations.h"


double PostOrderTreeCalc(struct Node_t* curr_node, struct Tree_calc* tree_calculations) {

    assert(curr_node != NULL);
    assert(tree_calculations != NULL);

    if ((curr_node -> type_node) == VARIABLE) return tree_calculations -> variable_array[curr_node -> node_element.index_var].variable_value;
    if ((curr_node -> type_node) == CONST_VALUE) return curr_node -> node_element.const_value;

    double left_subtree_value = 0;
    if (curr_node -> left_branch  != NULL) left_subtree_value  = PostOrderTreeCalc(curr_node -> left_branch, tree_calculations);
    double right_subtree_value = 0;
    if (curr_node -> right_branch != NULL) right_subtree_value = PostOrderTreeCalc(curr_node -> right_branch, tree_calculations);

    if ((curr_node -> type_node) == OPERATION) return SubTreeCalculation(curr_node, left_subtree_value, right_subtree_value);

    return NAN;//если тип узла не соответствует ни одному из заданныхх в enum

}

double SubTreeCalculation(struct Node_t* curr_node, double left_subtree_value, double right_subtree_value) {

    assert(curr_node != NULL);

    enum OperationType operation_type = curr_node -> node_element.operations;

    switch(operation_type) {

    case ADD:    return (left_subtree_value + right_subtree_value);

    case MULL:   return (left_subtree_value * right_subtree_value);

    case SUB:    return (left_subtree_value - right_subtree_value);

    case DIV:    if (right_subtree_value != 0) return (left_subtree_value / right_subtree_value);
                 else return NAN;

    case POW:    return pow(left_subtree_value, right_subtree_value);

    case SIN:    return sin(right_subtree_value);

    case COS:    return cos(left_subtree_value);

    case TAN:    return tan(right_subtree_value);

    case ATAN:   return atan(right_subtree_value);

    case ASIN:   return asin(right_subtree_value);

    case ACOS:   return acos(left_subtree_value);

    case SINH:   return sinh(right_subtree_value);

    case COSH:   return cosh(left_subtree_value);

    case TANH:   return tanh(right_subtree_value);

    case LN:     return log(left_subtree_value);

    case LOG:    return log(right_subtree_value) / log(left_subtree_value);

    case EXP:    return exp(right_subtree_value);

    default:     assert(0);
                 return NAN;

    }

}
