#include <iostream>
#include <vector>

using namespace std;

void interchangeSort(int a[], int n) {
	vector<string> kq;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
		string s = "Buoc ";
		s += to_string(i + 1) + ": ";
		for(int idx = 0; idx < n; idx++) {
			s += to_string(a[idx]) + " ";
		}
		kq.push_back(s);
	}
	for(int i = n - 2; i >= 0; i--) {
		cout << kq[i] << endl;
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
		interchangeSort(a, n);
	}
	return 0;
}

