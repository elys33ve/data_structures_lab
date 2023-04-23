#include <iostream>
#include "Sort.h"
/*	create implementation for the following sort operations:
	* bubble sort
	* insertion sort
	* merge-sort
	* quicksort
	* counting sort
	* radix sort
	* heap-sort
*/

using namespace std;


// swap
void Sort::swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}


// bubble sort
void Sort::bubble_sort(int arr[], int n) {
	int t;		// temp
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-(i + 1); j++) {
			if (arr[j] > arr[j + 1]) {		// swap
				swap(&arr[j], &arr[j+1]);
				//t = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = t;
			}
		}
	}
}



// insertion sort
void Sort::insertion_sort(int *arr, int n) {
	// swap each 'new' item until it has correct placement
	int j, t;
	for (int i=1; i<n; i++) {
		t = arr[i];
		j = i - 1;

		// move elements greater than t
		while (j >= 0 && arr[j] > t) {
			arr[j + 1] = arr[j];
			j = j - 1;
		} arr[j + 1] = t;
	}
}




// merge-sort
void Sort::merge_sort(int *arr, int n) { merge_sort_recursive(arr, 0, n-1); }	// in main for simplicity
void Sort::merge_sort_recursive(int *arr, int left, int right) {	// right and left idx of sub array
	if (left >= right) { return; }

	// sort within sub arrays
	int mid = left + ((right - left) / 2);
	merge_sort_recursive(arr, left, mid);
	merge_sort_recursive(arr, mid+1, right);
	merge(arr, left, mid, right);
}
void Sort::merge(int *arr, int left, int mid, int right) {
	// merges arr[right...mid] and arr[mid+1...left]
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int arr1[n1], arr2[n2];

	// copy to temp arrays
	for (int i=0; i<n1; i++) {
		arr1[i] = arr[left + i];
	}
	for (int i=0; i<n2; i++) {
		arr2[i] = arr[mid + i + 1];
	}

	// merge
	int idx1, idx2, idx_merged = left;
	idx1 = idx2 = 0;
	while (idx1 < n1 && idx2 < n2) {
		if (arr1[idx1] <= arr2[idx2]) {
			arr[idx_merged] = arr1[idx1];
			idx1++;
		} 
		else {
			arr[idx_merged] = arr2[idx2];
			idx2++;
		}
		idx_merged++;
	}

	// copy remaining left
	while (idx1 < n1) {
		arr[idx_merged] = arr1[idx1];
		idx1++; idx_merged++;
	}
	// copy remaining right
	while (idx2 < n2) {
		arr[idx_merged] = arr2[idx2];
		idx2++; idx_merged++;
	}
}
// (reference: https://www.geeksforgeeks.org/merge-sort/)



// quicksort
void Sort::quick_sort(int *arr, int n) { quick_sort_recursive(arr, 0, n-1); }	// in main for simplicity
void Sort::quick_sort_recursive(int *arr, int left, int right) {
	if (left >= right) { return; }
	
	
	int x = part(arr, left, right);

	// sort
	quick_sort_recursive(arr, left, x-1);		// left side
	quick_sort_recursive(arr, x+1, right);		// right side
}
int Sort::part(int *arr, int left, int right) {
	// part
	int pivot = arr[left];
	int idx, k = 0;
	for (int i=left+1; i<=right; i++) {
		if (arr[i] <= pivot) {
			k++;
		}
	}
	idx = left + k;
	swap(&arr[idx], &arr[left]);
	
	// sort
	int i = left, j = right;
	while (i < idx && j > idx) {
		while (arr[i] <= pivot) { i++; }
		while (arr[j] > pivot) { j--; }

		if (i < idx && j > idx) {
			swap(&arr[i++], &arr[j++]);
		}
	}
	return idx;
}


// counting sort
void Sort::counting_sort(int *arr) {

	
}


// radix sort
void Sort::radix_sort(int *arr) {

	
}


// heap-sort
void Sort::heap_sort(int *arr) {

	
}

