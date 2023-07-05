#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[100];
int n, k;
int x[100];
vector<string> v;

void quayLui(int i, int sum) {
	for(int j = 1; j >= 0; j--) {
		x[i] = j;
		sum += a[i] * j;
		if(i == n - 1) {
			if(sum == k) {
				string s = "[";
				for(int idx = 0; idx < n; idx++) {
					if(x[idx] > 0) {
						s += to_string(a[idx]) + " ";
					}
				}
				s.erase(s.length() - 1);
				s += "]";
				v.push_back(s);
			}
		}
		else quayLui(i + 1, sum);
		sum -= a[i] * j;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		quayLui(0, 0);
		for(string s : v) {
			cout << s << " ";
		}
		if(v.size() == 0) {
			cout << "-1";
		}
		cout << endl;
		v.clear();
	}
	return 0;
}

