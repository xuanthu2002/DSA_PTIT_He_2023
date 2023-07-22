#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(int a[], int n) {
	vector<string> kq;
	for(int i = n - 1; i >= 1; i--) {
		bool flag = true;
		for(int j = 0; j < i; j++) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = false;
			}
		}
		if(flag) break;
		string s = "Buoc ";
		s += to_string(n - i) + ": ";
		for(int idx = 0; idx < n; idx++) s += to_string(a[idx]) + " ";
		kq.push_back(s);
	}
	reverse(kq.begin(), kq.end());
	for(string s : kq) cout << s << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		bubbleSort(a, n);
	}
	return 0;
}

