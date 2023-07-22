#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int l, int m, int r) {
	vector<int> left(a + l, a + m);
	vector<int> right(a + m, a + r);
	int i = 0, j = 0;
	while(i < left.size() && j < right.size()) {
		if(left[i] <= right[j]) {
			a[l] = left[i];
			i += 1;
			l += 1;
		}
		else {
			a[l] = right[j];
			j += 1;
			l += 1;
		}
	}
	while(i < left.size()) {
		a[l] = left[i];
		l += 1;
		i += 1;
	}
	while(j < right.size()) {
		a[l] = right[j];
		l += 1;
		j += 1;
	}
}

void mergeSort(int a[], int l, int r) {
	if(l < r - 1) {
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m, r);
		merge(a, l, m, r);
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

