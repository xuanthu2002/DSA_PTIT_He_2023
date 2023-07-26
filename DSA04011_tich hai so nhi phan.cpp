#include <iostream>

using namespace std;

int binaryToInt(string s) {
	int kq = 0;
	for(char c : s) {
		kq = kq * 2 + c - '0';
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		cout << (long long) binaryToInt(a) * binaryToInt(b) << endl;
	}
	return 0;
}

