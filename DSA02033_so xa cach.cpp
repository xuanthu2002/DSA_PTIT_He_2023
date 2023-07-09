#include <iostream>
#include <cstring>

using namespace std;

int a[100];
int n;
bool used[100] = {false};

bool check() {
	bool cnt[n + 1] = {false};
	for(int i = 1; i < n; i++) {
		if(cnt[a[i]] || abs(a[i] - a[i - 1]) == 1)
			return false;
		cnt[a[i]] = true;
	}
	return true;
}

void quayLui(int i) {
	for(int j = 1; j <= n; j++) {
		if(!used[j]) {
			a[i] = j;
			used[j] = true;
			if(i == n - 1) {
				if(check()) {
					for(int idx = 0; idx < n; idx++) {
						cout << a[idx];
					}
					cout << endl;
				}
			}
			else quayLui(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(used, false, sizeof(used));
		quayLui(0);
	}
	return 0;
}

