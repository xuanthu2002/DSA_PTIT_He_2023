#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long kq = (long long) n * (n - 1) / 2;
	int cnt = 1;
	vector<int> v;
	for(int i = 1; i < n; i++) {
		if(s[i] == s[i - 1]) {
			cnt += 1;
		}
		else {
			v.push_back(cnt);
			cnt = 1;
		}
	}
	v.push_back(cnt);
	for(int i = 1; i < v.size(); i++) {
		kq -= v[i] + v[i - 1] - 1;
	}
	cout << kq;
	return 0;
}

