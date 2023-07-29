#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

string s;
long long kq;
int len;
unordered_map<long long, bool> m;

void quayLui(int i, long long n) {
	if(i == len) {
		if(m[n]) {
			kq = max(kq, n);
		}
		return;
	}
	if(i < len) {
		quayLui(i + 1, n * 10 + s[i] - '0');
		quayLui(i + 1, n);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(long long i = 1; i <= 1000000; i++) {
		m[i * i * i] = true;
	}
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		len = s.length();
		kq = -1;
		quayLui(0, 0);
		cout << kq << endl;
	}
	return 0;
}

