#include <iostream>

using namespace std;

int a[100];
int n;
bool used[100];
string s;

void quayLui(int i) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			a[i] = j;
			used[j] = true;
			if(i == n - 1) {
				for(int idx = 0; idx < n; idx++) {
					cout << s[a[idx]];
				}
				cout << " ";
			}
			else quayLui(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		n = s.length();
		quayLui(0);
		cout << endl;
	}
	return 0;
}

