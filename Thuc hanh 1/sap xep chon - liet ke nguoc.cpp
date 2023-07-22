#include <iostream>
#include <vector>

using namespace std;

void selectionSort(int a[], int n) {
	vector<string> kq;
	for(int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
		string s = "Buoc ";
		s += to_string(i + 1) + ": ";
		for(int idx = 0; idx < n; idx++) {
			s += to_string(a[idx]) + " ";
		}
		kq.push_back(s);
	}
	for(int i = n - 2; i >= 0; i--) cout << kq[i] << endl;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	selectionSort(a, n);
	return 0;
}

