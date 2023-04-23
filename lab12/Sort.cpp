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

// max
int Sort::max(int arr[], int n) {
	int m = arr[0];
	for (int i=0; i<n; i++) {
		if (arr[i] > m) {
			m = arr[i];
		}
	}
	return m;
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
void Sort::insertion_sort(int arr[], int n) {
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
void Sort::merge_sort(int arr[], int n) { merge_sort_recursive(arr, 0, n-1); }	// in main for simplicity
void Sort::merge_sort_recursive(int arr[], int left, int right) {	// right and left idx of sub array
	if (left >= right) { return; }

	// sort within sub arrays
	int mid = left + ((right - left) / 2);
	merge_sort_recursive(arr, left, mid);
	merge_sort_recursive(arr, mid+1, right);
	merge(arr, left, mid, right);
}
void Sort::merge(int arr[], int left, int mid, int right) {
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
void Sort::quick_sort(int arr[], int n) { quick_sort_recursive(arr, 0, n-1); }	// in main for simplicity
void Sort::quick_sort_recursive(int arr[], int left, int right) {
	if (left >= right) { return; }
	
	// part
	int current = arr[left];
	int idx, k = 0;
	for (int i=left+1; i<=right; i++) {
		if (arr[i] <= current) { k++; }		// count all greater than current
	}
	idx = left + k;
	swap(&arr[idx], &arr[left]);
	
	// sort by swapping to correct place
	int i = left, j = right;
	while (i < idx && j > idx) {
		while (arr[i] <= current) { i++; }
		while (arr[j] > current) { j--; }

		if (i < idx && j > idx) {
			swap(&arr[i++], &arr[j++]);
		}
	}

	// sort
	quick_sort_recursive(arr, left, idx-1);		// left side
	quick_sort_recursive(arr, idx+1, right);	// right side
}
// (reference: https://www.geeksforgeeks.org/cpp-program-for-quicksort/)



// counting sort
void Sort::counting_sort(int arr[], int n) {
	int output[n];
	int m = max(arr, n);

	// fill count with zeros
	int count[m+1];
	for (int i=0; i<=m; i++) { count[i] = 0; } 
	// get count of each item
	for (int i=0; i<n; i++) { count[arr[i]]++; }
	// get cummulative counts
	for (int i=1; i<=m; i++) {
		count[i] += count[i - 1];
	}

	// store items in order in temp output array
	for (int i=n-1; i>=0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	// copy to original array
	for (int i=0; i<n; i++) {
		arr[i] = output[i];
	}	
}
// (reference: https://www.programiz.com/dsa/counting-sort)



// radix sort
void Sort::radix_sort(int arr[], int n) {
	// get max value
	int m = max(arr, n);
	
	// sort
	for (int i=1; m/i>0; i*=10) {
        int output[n], count[10];

		// set count to zeros
		for (int j=0; j<10; j++) { count[j] = 0; }

		// get count for arr elements
		for (int j=0; j<n; j++) {
			count[(arr[j] / i) % 10]++;
		}
		// get elements positions
		for (int j=1; j<10; j++) {
			count[j] += count[j - 1];
		}

		// order
		for (int j=n-1; j>=0; j--) {
			output[count[(arr[j] / i) % 10] - 1] = arr[j];
			count[(arr[j] / i) % 10]--;
		}

		// copy to original array
		for (int j=0; j<n; j++) {
			arr[j] = output[j];
		}
	}
}
 



// heap-sort
void Sort::heap_sort(int arr[], int n) {
	// order heap
	for (int i=n/2-1; i>=0; i--) {
        heap_sort_recursive(arr, n, i);
	}
 
    // sort
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heap_sort_recursive(arr, i, 0);
    }
}
void Sort::heap_sort_recursive(int arr[], int n, int i) {
	int left, right, idx = i; 
    left = (2 * i) + 1; 
    right = (2 * i) + 2; 
 
    // if left larger, update idx
    if (left < n && arr[left] > arr[idx]) {
        idx = left;
	}
    // if right larger, update idx
    if (right < n && arr[right] > arr[idx]) {
        idx = right;
	}

    // if root not largest, reorder subtree
    if (idx != i) {
        swap(&arr[i], &arr[idx]);
        heap_sort_recursive(arr, n, idx);
	}
}
// (reference: https://www.geeksforgeeks.org/cpp-program-for-heap-sort/)
