#include "logic.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int check_inputNum(int number)
{
    if ((number < 1) || (number > 10)) {
        return 0;
    }
    return 1;
}
int check_inputNum2(int number, int* c)
{
    if (*c < number) {
        return 0;
    } else
        *c -= number;
    return 1;
}
int check_compNum(int quantity, int* c)
{
 while (quantity > *c) {
        return 0;
    }
    *c -= quantity;
    return 1;
}
