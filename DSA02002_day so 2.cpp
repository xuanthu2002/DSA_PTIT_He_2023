#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		a[n] = 0;
		vector<string> v;
		for(int i = n; i > 0; i--) {
			string s = "[";
			for(int j = 0; j < i - 1; j++) {
				s += to_string(a[j]) + " ";
				a[j] += a[j + 1];
			}
			s += to_string(a[i - 1]) + "]";
			v.push_back(s);
			a[i - i - 1] += a[i - 1];
		}
		reverse(v.begin(), v.end());
		for(string s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}

