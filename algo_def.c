#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



// Function definition for calculating size of an array - shorthand code to save space

// Binary search algorithm function definition
// RETURNS -1 IF NUMBER NOT FOUND
// RETURNS the *INDEX NUMBER* of number within array if it IS found 
// so if result != -1, then return output into next function as INDEX of original array 

int binary_sort(const int* arr, int size, int target_num) {
	int low = 0, high = size -1;
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target_num) {
			return mid;
		}
		else if (arr[mid] < target_num) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}


// DEFINE THE LINEAR SEARCH FUNCTION ALGORITHM

//int linear_scan(int *arr, int arraySize, int target_num) {
//	int i = 0;
//	while (i < arraySize) {
//		if (arr[i] == target_num) {
//			return i;
//		
//        }
//		i += 1;
//    }
//	return -1;
//}
