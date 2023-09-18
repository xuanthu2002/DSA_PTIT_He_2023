#include <iostream>

using namespace std;

int selectionSort(int a[], int n) {
	int kq = 0;
	for(int i = 0; i < n; i++) {
		int pos = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[pos]) {
				pos = j;
			}
		}
		if(pos != i) {
			swap(a[i], a[pos]);
			kq += 1;
		}
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << selectionSort(a, n) << endl;
	}
	return 0;
}

