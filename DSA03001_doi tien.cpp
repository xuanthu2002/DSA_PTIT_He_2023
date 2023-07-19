#include <iostream>

using namespace std;

int main() {
	int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int kq = 0;
		int i = 9;
		while(i >= 0 && n >= 0) {
			kq += n / a[i];
			n %= a[i];
			i -= 1;
		}
		cout << kq << endl;
	}
	return 0;
}

