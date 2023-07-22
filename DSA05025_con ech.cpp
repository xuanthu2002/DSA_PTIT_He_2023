#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	long long d[51] = {0};
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for(int i = 4; i <= 50; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	while(t--) {
		int n;
		cin >> n;
		cout << d[n] << endl;
	}
	return 0;
}

