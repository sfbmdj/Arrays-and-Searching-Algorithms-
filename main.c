#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>


#include "algo_def.c"

// ***** the array (pointer?)


#define MIN_VALUE 1
#define MAX_VALUE 10000
#define ARRAY_SIZE 1000
#define TARGET_SEARCH_NUMBER 200
#define ERROR_MEMORY_ALLOCATION_FAILED "Memory allocation failed!\n"

double measure_execution_time(int (*search_func)(const int*, int, int), const int* arr, int size, int target);
int* create_random_array(size_t size, int min, int max);
int comparator(const void* a, const void* b);
void sort_array(int* arr, size_t array_size);
void print_array(const int* arr, size_t array_size);

// Function definition for comparator function : needed for quicksort function

int comparator(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Quicksort function to resort random array values from DESC to ASC

void sort_array(int* arr, size_t array_size) {

	// qsort takes array, its size, size of array elements
	// Uses comparator as final param to sort between elements -> sends to STD_OUT
	// returns sorted list from lowest to highest ints

	if(arr == NULL || array_size == 0) {
		return;
	}

	qsort(arr, array_size, sizeof(int), comparator);
}


// Iterate through all values in array and print to stdout
void print_array(const int* arr, size_t array_size) {

	if (arr == NULL || array_size == 0) {
		return;
	}


	for (size_t i = 0; i < array_size; i++) {
		printf("%d\n", arr[i]);
	}

}



double measure_execution_time(int (*search_func)(const int*, int, int), const int* arr, int size, int target) {
    clock_t start = clock();
    int result = search_func(arr, size, target); // Call the search function
    clock_t end = clock();
    (void)result; // Suppress unused variable warning
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}



int* create_random_array(size_t size, int min, int max) {

	// Allocate dynamic memory to the array using ______
	int* arr = (int *)malloc(size * sizeof(int));

	if (arr == NULL) {
        fprintf(stderr, ERROR_MEMORY_ALLOCATION_FAILED);
        exit(EXIT_FAILURE); // Exit the program if memory allocation fails
  	}
		
		
	for (size_t i = 0; i < size; i++) {

		// initialize an integer variable using math random function
		// then use modulo of max, min function to round out values
		// Assign each iteration of index in array to this random value

		arr[i] = rand() % (max - min + 1) + min;
	}
	
	return arr;

}


int main(void) {
	

	// Seed random with current time
	srand((unsigned int)time(NULL));

	// Create an array and then feed in randomized values by iterating through each index slot

	// Array creation and printing
	// Assign random values to every index item in the array to the last block

	// Sort the array from lowest to highest value
	int* arr = create_random_array(ARRAY_SIZE, MIN_VALUE, MAX_VALUE);
	sort_array(arr, ARRAY_SIZE);

	// Call function

    // Measure execution time for binary search
    double search_time = measure_execution_time((int (*)(const int*, int, int))binary_sort, arr, ARRAY_SIZE, TARGET_SEARCH_NUMBER);
    printf("Time taken for binary search: %.9f seconds\n", search_time);


	int searchResult = binary_sort(arr, ARRAY_SIZE, TARGET_SEARCH_NUMBER);

	if (searchResult == -1) {
		printf("\nTarget number %d was NOT found in the array \n", TARGET_SEARCH_NUMBER);
	} else {
		printf("\nTarget number %d was found at index %d in the array.\n", TARGET_SEARCH_NUMBER, searchResult);
	}

	// If (algoChoice == "B")
	// Run binary search 
	// binary_search(arr, arraySize, target_srch_num);
	
	// Return runtime for algorithm time took to run 

	// Free the allocated memory up again
	free(arr);

	return EXIT_SUCCESS;

}