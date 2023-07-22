#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int a[], int n) {
	vector<string> kq;
	for(int i = 0; i < n; i++) {
		int key = a[i];
		int j = i;
		while(j >= 1 && a[j - 1] > key) {
			a[j] = a[j - 1];
			j -= 1;
		}
		a[j] = key;
		string s = "Buoc ";
		s += to_string(i) + ": ";
		for(int idx = 0; idx <= i; idx++) {
			s += to_string(a[idx]) + " ";
		}
		kq.push_back(s);
	}
	for(int i = n - 1; i >= 0; i--) cout << kq[i] << endl;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	insertionSort(a, n);
	return 0;
}

