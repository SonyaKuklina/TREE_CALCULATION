#ifndef ENUM_DIFF
#define ENUM_DIFF

enum OperationType {

    ADD, MULL, DIV, SUB,
    POW, SIN,  COS, TAN,
    ATAN, ASIN, ACOS,
    SINH, COSH, TANH,
    LN, LOG, EXP,


};

enum TypeNode {

    OPERATION = 0,
    VARIABLE,
    CONST_VALUE,

};

enum ProgrammReturn {

    CORRECT = 0,
    INCORRECT,

};

#endif
