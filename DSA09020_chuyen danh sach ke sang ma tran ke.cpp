#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	int a[n + 1][n + 1];
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int j;
		while(ss >> j) {
			a[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

