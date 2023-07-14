#include <iostream>
#include <vector>

using namespace std;

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
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		mergeSort(a, 0, n);
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}

