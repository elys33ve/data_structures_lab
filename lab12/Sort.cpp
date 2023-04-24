#include <iostream>
#include <cstdio>
#include <chrono>
#include <ctime>
#include <string>
#include "Sort.h"
#include "Arrays.h"
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
typedef chrono::high_resolution_clock Clock;

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

// check order
int Sort::check_order(int arr[], int n) {
	int fail = 0;
	for (int i=0; i<n-1; i++) {
		if (arr[i] > arr[i+1]) {
			fail = 1;
			cout << "fail: idx=" << i << ", " << arr[i] << " -> " << arr[i+1] << endl;
		}
	}
	return fail;
}



// bubble sort
void Sort::bubble_sort(int arr[], int n) {
	double t; auto t1 = Clock::now();			// start time

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-(i + 1); j++) {
			if (arr[j] > arr[j + 1]) {		// swap
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[0] >= 10) { time_idx[0] = 0; }
	bubble_sort_time[time_idx[0]] = t; time_idx[0]++;	// record time
}




// insertion sort
void Sort::insertion_sort(int arr[], int n) {
	double t; auto t1 = Clock::now();			// start time

	// swap each 'new' item until it has correct placement
	int j, temp;
	for (int i=1; i<n; i++) {
		temp = arr[i];
		j = i - 1;

		// move elements greater than t
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		} arr[j + 1] = temp;
	}

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[1] >= 10) { time_idx[1] = 0; }
	insertion_sort_time[time_idx[1]] = t; time_idx[1]++;	// record time
}




// merge-sort
void Sort::merge_sort(int arr[], int n) { 	// (in main for simplicity)
	double t; auto t1 = Clock::now();			// start time

	merge_sort_recursive(arr, 0, n-1); 

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[2] >= 10) { time_idx[2] = 0; }
	merge_sort_time[time_idx[2]] = t; time_idx[2]++;	// record time
}	
void Sort::merge_sort_recursive(int arr[], int left, int right) {	// right and left idx of sub array
	if (left >= right) { return; }

	// sort within sub arrays
	int mid = left + ((right - left) / 2);
	merge_sort_recursive(arr, left, mid);
	merge_sort_recursive(arr, mid+1, right);

	// merge arr[right...mid] and arr[mid+1...left]
	int n1, n2;				// size of sub arrays
	n1 = mid - left + 1;
	n2 = right - mid;

	int arr1[n1], arr2[n2];		// sub arrays

	int idx1, idx2, idx_merged = left;
	idx1 = idx2 = 0;

	// copy to temp arrays
	for (int i=0; i<n1; i++) {		// left array
		arr1[i] = arr[left + i];
	}
	for (int i=0; i<n2; i++) {		// right array
		arr2[i] = arr[mid + i + 1];
	}

	// merge based on element values
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
void Sort::quick_sort(int arr[], int n) { 	// (in main for simplicity)
	double t; auto t1 = Clock::now();			// start time

	quick_sort_recursive(arr, 0, n-1); 

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[3] >= 10) { time_idx[3] = 0; }
	quick_sort_time[time_idx[3]] = t; time_idx[3]++;	// record time
}
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
	double t; auto t1 = Clock::now();			// start time

	int output[n], m = max(arr, n);

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

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[4] >= 10) { time_idx[4] = 0; }
	counting_sort_time[time_idx[4]] = t; time_idx[4]++;	// record time
}
// (reference: https://www.programiz.com/dsa/counting-sort)




// radix sort
void Sort::radix_sort(int arr[], int n) {
	double t; auto t1 = Clock::now();			// start time

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

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[5] >= 10) { time_idx[5] = 0; }
	radix_sort_time[time_idx[5]] = t; time_idx[5]++;	// record time
}
 



// heap-sort
void Sort::heap_sort(int arr[], int n) {
	double t; auto t1 = Clock::now();			// start time

	// order heap
	for (int i=n/2-1; i>=0; i--) {
        heap_sort_recursive(arr, n, i);
	}
 
    // sort
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heap_sort_recursive(arr, i, 0);
    }

	// end time
	auto t2 = Clock::now();
	t = chrono::duration<double>(t2 - t1).count() * 1000;
	if (time_idx[6] >= 10) { time_idx[6] = 0; }
	heap_sort_time[time_idx[6]] = t; time_idx[6]++;	// record time
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




///////////////////////////////////////////////////////


// create new array 
void Sort::new_array(int arr[]) {
	int *temp = create_array(size);
	for(int i=0; i<size; i++) {
		arr[i] = temp[i];
	}
}



// test all sort methods
void Sort::test_all() {
	int n = size;
	// create unsorted temp array
	int arr[size], temp[n];		
	new_array(arr);
	for (int i=0; i<n; i++) { temp[i] = arr[i]; }

	// bubble sort
	bubble_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[0] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }	// reset array

	// insertion sort
	insertion_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[1] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }

	// merge-sort
	merge_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[2] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }

	// quicksort
	quick_sort(arr, n);
	//if (check_order(arr, n) == 1) { cout << sort_functions[3] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }

	// counting sort
	counting_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[4] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }

	// radix sort
	radix_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[5] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }

	// heap-sort
	heap_sort(arr, n);
	if (check_order(arr, n) == 1) { cout << sort_functions[6] << " fail\n"; }
	for (int i=0; i<n; i++) { arr[i] = temp[i]; }
}



// test method 10 times
void Sort::test_10(int arr[], int k) {
	int n = size;
	// bubble sort
	if (k == 0) { 
		for (int i=0; i<10; i++) { bubble_sort(arr, n); }
	}
	// insertion sort
	if (k == 1) { 
		for (int i=0; i<10; i++) { insertion_sort(arr, n); }
	}
	// merge sort
	if (k == 2) { 
		for (int i=0; i<10; i++) { merge_sort(arr, n); }
	}
	// quick sort
	if (k == 3) { 
		for (int i=0; i<10; i++) { quick_sort(arr, n); }
	}
	// counting sort
	if (k == 4) { 
		for (int i=0; i<10; i++) { counting_sort(arr, n); }
	}
	// radix sort
	if (k == 5) { 
		for (int i=0; i<10; i++) { radix_sort(arr, n); }
	}
	// heap sort
	if (k == 6) { 
		for (int i=0; i<10; i++) { heap_sort(arr, n); }
	}	
}




// get times arrays
double **Sort::get_times() {
	times[0] = bubble_sort_time; 
	times[1] = insertion_sort_time; 
	times[2] = merge_sort_time;
	times[3] = quick_sort_time;
	times[4] = counting_sort_time;
	times[5] = radix_sort_time;
	times[6] = heap_sort_time;
	return times;
}



// print array
void Sort::print_array(int arr[], int n) {
	// if array size 10, print items
	if (n == 10) {
		for (int i=0; i<n; i++) {
			cout << arr[i] << endl;
		}
	}
	else {
		// print only first and last 5 if its one of the large ones
		for (int i=0; i<5; i++) {		// first 5
			cout << arr[i] << endl;
		} cout << ". . .\n";
		for (int i=n-5; i<n; i++) {		// last 5
			cout << arr[i] << endl;
		}
	}
}



// print times
void Sort::print_times(int i) {		// print one time array
	get_times();

	double avg = 0;
	// print times array
	cout << sort_functions[i] << " times (ns): ";
	for (int j=0; j<9; j++) {
		avg += times[i][j];
		cout << times[i][j] << ", ";
	} cout << times[i][9] << endl;

	// print average
	avg = (avg + times[i][9]) / 10;
	cout << "\t(average = " << avg << ")\n";
}



// print times
void Sort::print_avgs() {		// print one time array
	get_times();

	double avg;
	// print times array
	for (int i=0; i<7; i++) {
		avg = 0; 
		for (int j=0; j<10; j++) {
			avg += times[i][j];
		} avg /= 10;
		cout << sort_functions[i] << " average = " << avg << " ms\n";
	}
}

