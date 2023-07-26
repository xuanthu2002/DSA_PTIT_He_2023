#include <iostream>

using namespace std;

string sum(string a, string b, int k) {
	if(a.length() > b.length()) swap(a, b);
	while(a.length() < b.length()) {
		a = "0" + a;
	}
	int c = 0;
	string kq = "";
	for(int i = a.length() - 1; i >= 0; i--) {
		int s = a[i] - '0' + b[i] - '0' + c;
		c = s / k;
		s = s % k;
		kq = to_string(s) + kq;
	}
	if(c > 0) kq = to_string(c) + kq;
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		int k;
		cin >> k >> a >> b;
		cout << sum(a, b, k) << endl;
	}
	return 0;
}

