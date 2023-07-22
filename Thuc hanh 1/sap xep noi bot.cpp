#include <iostream>

using namespace std;

void bubbleSort(int a[], int n) {
	for(int i = n - 1; i >= 1; i--) {
		bool flag = true;
		for(int j = 0; j <= i; j++) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = false;
			}
		}
		if(flag) break;
		cout << "Buoc " << n - i << ": ";
		for(int idx = 0; idx < n; idx++) {
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
	bubbleSort(a, n);
	return 0;
}

