#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function definition for calculating size of an array - shorthand code to save space

int length_array(int array) {
	int length = sizeof(array) / sizeof(array[0]);
		
}

// Binary search algorithm function definition  

int binary_sort(int array, int target_num) {
	int IndexLow, IndexHigh;

	IndexHigh = length_array(array) - 1;
	IndexLow = 0;
	
	while (IndexLow <= IndexHigh): {
		int IndexMid = Floor((IndexHigh + IndexLow) / 2))
	
		if array[IndexMid] == target_num:
			return IndexMid;
		if array[IndexMid] < target_num: 
			IndexLow = IndexMid + 1;
		else:
			IndexHigh = IndexMid - 1;
	}
return -1;
}


// DEFINE THE LINEAR SEARCH FUNCTION ALGORITHM 

int linear_scan (int array, int target_num) {
	int i = 0;
	while i < length_array(array):
		if array[i] == target_num: 
			return i; 
		i += 1; 
return -1;
}

// Initialize global variable scope for array attributes/properties
// ***** the array (pointer?)

int *arr;
//int min, max, arraySize;


// User input section: Ask the user for input 
// Sets min, max range for random number generator

// *** Eventually have this ask them for a number to search for in algorithmic sorting  

void user_prompt(int min, int max, int *arraySize) {
	printf("Enter in your minimum value for randomizing values: \n ");
	scanf("%d", &min);
	
	printf("Enter in your max value for randomizing values: \n ");
	scanf("%d", &max);
	
	printf("Enter in your array size: \n ");
	scanf("%d", &arraySize);
	
}


// Function definition for comparator function : needed for quicksort function 

int comparator(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Quicksort function to resort random array values from DESC to ASC

void sort_arr(int *array, int arraySize) {

	// qsort takes array, its size, size of array elements
	// Uses comparator as final param to sort between elements -> sends to STD_OUT
	// returns sorted list from lowest to highest ints
	
	qsort(array, arraySize, sizeof(int), comparator);
}	






int main() {
	
	// Seed random with current time 
	srand(time(NULL));

	// Create an array and then feed in randomized values by iterating through each index slot   
	
	// Prompt user for initializing variables to define array elements (min, max, length)
	
	user_prompt();
	
	// Array creation and printing 
	
	// Allocate dynamic memory to the array using ______ 
	arr = (int *)malloc(arraySize * sizeof(int));
	
    	if (arr == NULL) {
        	printf("Memory allocation failed!\n");
        	return 1; // Exit the program if memory allocation fails
  	}
	
	//int arraySize = sizeof(arr)/sizeof(arr[0]);
	
	// ASSIGN RANDOM VALUES IN ARRAY 
	
	for (int i = 0; i < arraySize; i++) {
		
		int rand_arr = rand() % (max - min + 1) + min;
		arr[i] = rand_arr;
		
		
	}
	
	// SORT ARRAY, DESC TO ASC 
	sort_arr(arr, arraySize);
	
	
	// WRITE FUNCTION TO PRINT ARRAY 
	// DEFINE THIS INTO ITS OWN FUNCTION LATER 
	for (int j = 0; j < arraySize; j++) {
		printf("%d\n", arr[j]);
	}
	

	// Free the allocated memory up again 
	free(arr);
	
	return 0;

}
