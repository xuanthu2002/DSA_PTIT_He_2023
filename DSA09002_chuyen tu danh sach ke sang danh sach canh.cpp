#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int u = -1;
		while(ss >> u) {
			if(u > i) {
				cout << i << " " << u << endl;
			}
		}
	}
	return 0;
}

