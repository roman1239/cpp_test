#include "c_src_file.h"

#include "stdio.h"

int s_variable = 14;

void Print()
{
    printf("c_src_file !\n");
}

void PrintVar()
{
    printf("s_var: %d\n", s_variable);
}
