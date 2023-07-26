#include <iostream>

using namespace std;

int main () {
	int n;
	cin >> n;
	int *a = new int [n];
	int ** b = new int * [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = new int [n];
	}
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
		for (int k = 0; k < n; k++) {
			b[i][k] = a[k];
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		cout << "Buoc " << i + 1 << ": ";
		for (int j = 0; j < n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	delete [] a;
	delete [] b;
	return 0;
}

