#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void selectionSort(int a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
	}
}

void insertionSort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		int key = a[i];
		int j = i;
		while(j > 0 && a[j - 1] > key) {
			a[j] = a[j - 1];
			j -= 1;
		}
		a[j] = key;
	}
}

void bubbleSort(int a[], int n) {
	for(int i = n - 1; i > 0; i--) {
		bool flag = true;
		for(int j = 0; j < i; j++) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = false;
			}
		}
		if(flag) {
			break;
		}
	}
}

int partition(int a[], int l, int h) {
	int x = a[h];
	int i = l - 1;
	for(int j = l; j < h; j++) {
		if(a[j] < x) {
			i += 1;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void merge(int a[], int l, int m, int r) {
	vector<int> merge;
	int i = l, j = m;
	while(i < m && j < r) {
		if(a[i] <= a[j]) {
			merge.push_back(a[i]);
			i += 1;
		}
		else {
			merge.push_back(a[j]);
			j += 1;
		}
	}
	while(i < m) {
		merge.push_back(a[i]);
		i += 1;
	}
	while(j < r) {
		merge.push_back(a[j]);
		j += 1;
	}
	for(i = l; i < r; i++) {
		a[i] = merge[i - l];
	}
}

void mergeSort(int a[], int l, int r) {
	if(l < r - 1) {
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m, r);
		merge(a, l, m , r);
	}
}

int main() {
	fstream in("input.txt");
	int n;
	in >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	clock_t start, end;
	start = clock();
	bubbleSort(a, n);
	end = clock();
	cout << "bubble sort: " << (double) ((double) end - (double) start) / CLOCKS_PER_SEC << endl;
	return 0;
}

