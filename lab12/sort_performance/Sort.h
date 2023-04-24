#pragma once
#include <iostream>
#include <string>


class Sort {
	private:
		// record times
		int size;
		int time_idx[7] = { 0 };				// record current idx for each time array
		double bubble_sort_time[10] = { 0 };
		double insertion_sort_time[10] = { 0 };
		double merge_sort_time[10] = { 0 };
		double quick_sort_time[10] = { 0 };
		double counting_sort_time[10] = { 0 };
		double radix_sort_time[10] = { 0 };
		double heap_sort_time[10] = { 0 };
		double *times[7] = { 0 };				// array to return time arrays	

		int rand_seeds[10] { };			// srand seeds for random array values
		int r_idx;


		void swap(int *x, int *y);			// swap two items in array
		int max(int arr[], int n);			// return max value in array
		int check_order(int arr[], int n);	// checks to make sure array is actually sorted
		

		// recursive helper functions
		void merge_sort_recursive(int arr[], int left, int right);		// merge sort
		void quick_sort_recursive(int arr[], int left, int right);		// quick sort
		void heap_sort_recursive(int arr[], int n, int i);				// heap sort
		
	public:
		// list of sort method names for print functions
		std::string sort_functions[7] = { "bubble sort", "insertion sort", "merge sort",
		"quick sort", "counting sort", "radix sort", "heap sort" };
		bool debug = false;

		Sort() { size = 0; }
		Sort(int s);

		// bubble sort
		void bubble_sort(int arr[], int n);

		// insertion sort
		void insertion_sort(int arr[], int n);

		// merge-sort
		void merge_sort(int arr[], int n);

		// quicksort
		void quick_sort(int arr[], int n);

		// counting sort
		void counting_sort(int arr[], int n);

		// radix sort
		void radix_sort(int arr[], int n);

		// heap-sort
		void heap_sort(int arr[], int n);


		// test all sort methods
		void test_all();
		// test method 10 times
		void test_10(int k);

		// get times arrays
		double **get_times();

		// create new array w new values
		void new_array(int arr[]);
		int *new_array();

		// print array
		void print_array(int arr[], int n);
		// print times
		void print_times() { for (int i=0; i<7; i++) { print_times(i); } }
		void print_times(int i);
		void print_avgs();
};