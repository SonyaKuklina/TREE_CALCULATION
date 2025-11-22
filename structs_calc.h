#ifndef STRUCTS_DIFF
#define STRUCTS_DIFF

#include "enum_calc.h"

union Node_el { //для элемента узла

    enum OperationType operations;
    double const_value;
    int index_var;

};

typedef union Node_el TreeElement;

struct Node_t {

    enum TypeNode type_node;
    TreeElement node_element;
    struct Node_t* left_branch;//YES
    struct Node_t* right_branch;//NO
    struct Node_t* parent;
    int num_node;

};

struct Tree_t {

    struct Node_t* root;
    size_t node_size;

};

struct ArrayVar {

    char variable_name;
    double variable_value;

};

struct Tree_calc {

    struct Tree_t* tree;
    struct ArrayVar* variable_array;

};


#endif
