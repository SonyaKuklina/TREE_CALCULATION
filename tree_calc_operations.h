#ifndef TREE_CALC_OPERATIONS
#define TREE_CALC_OPERATIONS

#include "structs_calc.h"
#include "enum_calc.h"

double PostOrderTreeCalc(struct Node_t* curr_node, struct Tree_calc* tree_calculations);
double SubTreeCalculation(struct Node_t* curr_node, double left_subtree_value, double right_subtree_value);

#endif
