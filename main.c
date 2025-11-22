#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "structs_calc.h"
#include "tree_calc_operations.h"
#include "tree_calc_private.h"
#include "tree_calc_graph.h"
//#include "work_with_file.h"

#define DUMP_TREE(x) DumpTree((x), __FILE__, __LINE__)


int main(void) {

    struct Tree_calc* tree_calculations = CreateTreeCalculations();
    double result = PostOrderTreeCalc((tree_calculations -> tree) -> root, tree_calculations);
    DUMP_TREE(tree_calculations);
    printf("%lg", result);

    return CORRECT;


}
