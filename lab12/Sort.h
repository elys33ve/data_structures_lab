#pragma once



class Sort {
	private:
		void swap(int *x, int *y);		// swap two items in array
		int max(int arr[], int n);		// return max value in array

		// recursive helper functions
		void merge_sort_recursive(int arr[], int left, int right);		// merge sort
		void quick_sort_recursive(int arr[], int left, int right);		// quick sort
		void heap_sort_recursive(int arr[], int n, int i);				// heap sort
		
	public:
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
};