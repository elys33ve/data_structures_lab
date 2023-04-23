#pragma once



class Sort {
	private:
		void swap(int *x, int *y);
		int max(int arr[], int n);

		// merge-sort
		void merge_sort_recursive(int arr[], int left, int right);
		void merge(int arr[], int left, int mid, int right);

		// quick sort
		void quick_sort_recursive(int arr[], int left, int right);

		// heap-sort
		void heap_sort_recursive(int arr[], int n, int i);
		
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