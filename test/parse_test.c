#include "../src/parse.c"
#include <stdio.h>

// parse test true
void parse_test_true(){
    // expected
    int  num_count = 4;
    float answer[] = {1,2,3,4};
    // calculated
    int     argc = num_count + 1;
    char* argv[] = {"name", "1", "2", "3", "4", NULL};
    float*  nums = parse_args(argc, argv);

    int sum = 0;
    for(int i = 0; i < num_count; i++){
        sum += nums[i] == answer[i];
    }
    printf("parse passes: %s\n", sum == num_count ? "\033[32mPASSED\033[0m" : "\033[31mFAILED\033[0m");
    free(nums);
}

// parse test false
void parse_test_false(){
    // expected
    int  num_count = 3;
    float answer[] = {1,2,3};
    // calculated
    int     argc = 5;
    char* argv[] = {"name", "1", "2", "3", "4", NULL};
    float*  nums = parse_args(argc, argv);
    // test
    int sum = 0;
    for(int i = 0; i < num_count; i++){
        sum += nums[i] == answer[i];
    }
    // should return false
    printf("parse fails: %s\n", sum == num_count ? "\033[32mPASSED\033[0m" : "\033[31mFAILED\033[0m");
    free(nums);
}
