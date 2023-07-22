#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int cnt[11][26];
bool used[11];
int a[12];
int kq;

int lap(int i, int j) {
	int res = 0;
	for(int idx = 0; idx < 26; idx++) {
		if(cnt[i][idx] == 1 && cnt[j][idx] == 1) res += 1;
	}
	return res;
}

void quayLui(int i, int res) {
	if(res >= kq) return;
	for(int j = 1; j <= n; j++) {
		if(!used[j]) {
			a[i] = j;
			int tmp = lap(a[i - 1], a[i]);
			res += tmp;
			used[j] = true;
			if(i == n) {
				kq = min(kq, res);
			}
			else quayLui(i + 1, res);
			res -= tmp;
			used[j] = false;
		}
	}
}

int main() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for(char c : s) {
			cnt[i + 1][c - 'A'] += 1;
		}
	}
	memset(used, false, sizeof(used));
	kq = 1e9;
	a[0] = 0;
	quayLui(1, 0);
	cout << kq;
	return 0;
}

