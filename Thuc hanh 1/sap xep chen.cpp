#include <iostream>

using namespace std;

void insertionSort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		int key = a[i];
		int j = i;
		while(j >= 1 && a[j - 1] > key) {
			a[j] = a[j - 1];
			j -= 1;
		}
		a[j] = key;
		cout << "Buoc " << i << ": ";
		for(int idx = 0; idx <= i; idx++) {
			cout << a[idx] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	insertionSort(a, n);
	return 0;
}

