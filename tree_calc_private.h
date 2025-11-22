#ifndef TREE_DIFF_PRIVATE
#define TREE_DIFF_PRIVATE

#include "structs_calc.h"
#include "enum_calc.h"

struct Tree_calc* CreateTreeCalculations();
struct Node_t* CreateNode(TreeElement element, enum TypeNode type_node, struct Tree_t* tree);
void TreeInit(struct Tree_t* tree);


#endif
