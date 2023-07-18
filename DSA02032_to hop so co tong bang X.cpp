#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
int a[21];
int b[21];
vector<string> kq;

void quayLui(int i, int sum) {
	for(int j = (x - sum) / a[i]; j >= 0; j--) {
		b[i] = j;
		sum += a[i] * j;
		if(i == n - 1) {
			if(sum == x) {
				string s = "{";
				for(int idx = 0; idx < n; idx++) {
					for(int k = 0; k < b[idx]; k++) {
						s += to_string(a[idx]) + " ";
					}
				}
				s.erase(s.length() - 1);
				s += "}";
				kq.push_back(s);
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
		cin >> n >> x;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		quayLui(0, 0);
		if(kq.size() < 1) cout << -1;
		else cout << kq.size() << " ";
		for(string s : kq) {
			cout << s << " ";
		}
		kq.clear();
		cout << endl;
	}
	return 0;
}

