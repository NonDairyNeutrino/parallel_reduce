// file to provide unified testing interface for the whole system
#include "parse_test.c"
#include "add_test.c"
#include <stdio.h>

int main(){
    printf("Testing parse\n");
    parse_test_true();
    parse_test_false();

    printf("Testing add\n");


    return 0;
}
