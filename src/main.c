// standard library
#include <stdio.h>
// custom
#include "parse.c"
#include "add.c"

int main(int argc, char* argv[]) {
	int	num_count = argc - 1;

	float* nums = parse_args(argc, argv);

	// printf("num count: %d\n", num_count);
	// printf("Numbers: ");
	// for(int i = 0; i < num_count; i++){
	// 	printf("%f ", nums[i]);
	// }
	// printf("\n");

	float sum = add_many_pthread(num_count, nums);

	printf("The sum of your given numbers is: %f\n", sum);
	free(nums);
	return 0;
}

