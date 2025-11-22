#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree_calc_private.h"

#define MAX_SIZE_VARIABLE_ARRAY 100

void TreeInit(struct Tree_t* tree) {

    assert(tree != NULL);
    tree -> root = NULL;
    tree -> node_size = 0;

}

struct Node_t* CreateNode(TreeElement element, enum TypeNode type_node, struct Tree_t* tree) {

    struct Node_t* node = (struct Node_t*)calloc(1, sizeof(struct Node_t));
    assert(node != NULL);

    switch(type_node) {

    case OPERATION:   node -> node_element.operations = element.operations;
                      break;
    case VARIABLE:    node -> node_element.index_var = element.index_var;
                      break;
    case CONST_VALUE: node -> node_element.const_value = element.const_value;
                      break;
    default:          assert(0);
                      break;

    }

    node -> type_node    = type_node;
    node -> left_branch  = NULL;
    node -> right_branch = NULL;
    node -> parent       = NULL;
    node -> num_node     = tree -> node_size;
    (tree -> node_size)++;
    return node;

}

struct Tree_calc* CreateTreeCalculations() {

    struct Tree_calc* tree_calculations = (struct Tree_calc*)calloc(1, sizeof(struct Tree_calc));
    assert(tree_calculations != NULL);
    union Node_el value_node;
    (tree_calculations -> tree) = (struct Tree_t*)calloc(1, sizeof(struct Tree_t));
    (tree_calculations -> variable_array) = (struct ArrayVar*)calloc(MAX_SIZE_VARIABLE_ARRAY, sizeof(struct ArrayVar));
    (tree_calculations -> variable_array[0]) = {'x', 10};
    (tree_calculations -> variable_array[1]) = {'y', 100};
    value_node.operations = MULL;
    ((tree_calculations -> tree) -> root) = CreateNode(value_node, OPERATION, tree_calculations -> tree);
    value_node.index_var  = 0;
    (((tree_calculations -> tree) -> root) -> left_branch) = CreateNode(value_node, VARIABLE, tree_calculations -> tree);
    value_node.operations = ADD;
    (((tree_calculations -> tree) -> root) -> right_branch) = CreateNode(value_node, OPERATION, tree_calculations -> tree);
    ((((tree_calculations -> tree) -> root) -> left_branch) -> parent)  = ((tree_calculations -> tree) -> root);
    ((((tree_calculations -> tree) -> root) -> right_branch) -> parent) = ((tree_calculations -> tree) -> root);
    value_node.index_var = 1;
    ((((tree_calculations -> tree) -> root) -> right_branch) -> left_branch)  = CreateNode(value_node, VARIABLE, tree_calculations -> tree);
    value_node.const_value = 6;
    ((((tree_calculations -> tree) -> root) -> right_branch) -> right_branch) = CreateNode(value_node, CONST_VALUE, tree_calculations -> tree);
    (((((tree_calculations -> tree) -> root) -> right_branch) -> left_branch) -> parent)  = (((tree_calculations -> tree) -> root) -> right_branch);
    (((((tree_calculations -> tree) -> root) -> right_branch) -> right_branch) -> parent) = (((tree_calculations -> tree) -> root) -> right_branch);

    return tree_calculations;


}
