#include <stdlib.h>

float* parse_args(int argc, char* argv[]) {
	// allocate argc number of boxes of size sizeof(int)
	// assign the address of the first box to nums
	float* nums = (float*)calloc(argc - 1, sizeof(float));

	// fun fact: `int* ptr = array` is the same as `int* ptr = &array[0]`

	// iterate through each box of the given arguments
	// converting each character to an integer
	// and putting that integer in the `i` box in nums
	for(int i = 1; i < argc; i++) {
		nums[i - 1] = atof(argv[i]);
	}
	// return the address of the first box of nums
	return nums;
}
