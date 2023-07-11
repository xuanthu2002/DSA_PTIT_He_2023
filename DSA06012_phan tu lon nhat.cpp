#include <iostream>

using namespace std;

int partition(int a[], int l, int h) {
	int x = a[h];
	int i = l - 1;
	for(int j = l; j < h; j++) {
		if(a[j] > x) {
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

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		quickSort(a, 0, n - 1);
		for(int i = 0; i < k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

