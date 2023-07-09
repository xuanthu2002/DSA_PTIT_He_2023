#include <iostream>
#include <cstring>

using namespace std;

int a[100];
int n;
bool used[100];
int hv[100];
bool kq;
int res;

bool check() {
	for(int i = 0; i < n; i++) {
		if(a[i] != hv[i]) return false;
	}
	return true;
}

void quayLui(int i) {
	if(kq) return;
	for(int j = 1; j <= n; j++) {
		if(!used[j]) {
			hv[i] = j;
			used[j] = true;
			if(i == n - 1) {
				res += 1;
				if(check()) {
					kq = true;
					return;
				}
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
		cin >> n;
		memset(used, false, sizeof(used));
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		res = 0;
		kq = false;
		quayLui(0);
		cout << res << endl;
	}
	return 0;
}

