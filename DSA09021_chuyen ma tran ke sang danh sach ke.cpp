#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if(x & 1) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

