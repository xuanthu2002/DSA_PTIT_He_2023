#include <iostream>
#include <cstring>

using namespace std;

int n;
int a[200];
bool used[100];

void quayLui(int i) {
	for(int j = 1; j <= n; j++) {
		if(!used[j]) {
			a[i] = j;
			used[j] = true;
			if(i == n - 1) {
				for(int idx = 0; idx < n; idx++) cout << a[idx];
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
		memset(used, false, sizeof(used));
		cin >> n;
		quayLui(0);
		cout << endl;
	}
	return 0;
}

