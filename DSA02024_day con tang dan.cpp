#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[21];
int b[21];
int n;
vector<string> res;

bool check() {
	int tmp = -1e9;
	for(int i = 0; i < n; i++) {
		if(b[i] == 1) {
			if(a[i] < tmp) {
				return false;
			}
			tmp = a[i];
		}
	}
	return true;
}

void quayLui(int i, int cnt) {
	for(int j = 0; j < 2; j++) {
		b[i] = j;
		cnt += j;
		if(i == n - 1) {
			if(check() && cnt > 1) {
				string s = "";
				for(int idx = 0; idx < n; idx++) {
					if(b[idx] > 0) {
						s += to_string(a[idx]) + " ";
					}
				}
				res.push_back(s);
			}
		}
		else quayLui(i + 1, cnt);
		cnt -= j;
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quayLui(0, 0);
	sort(res.begin(), res.end());
	for(string s : res) {
		cout << s << endl;
	}
	return 0;
}

