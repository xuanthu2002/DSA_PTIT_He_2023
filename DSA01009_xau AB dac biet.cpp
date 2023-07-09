#include <iostream>
#include <vector>

using namespace std;

int a[100];
int n, k;
vector<string> kq;

bool check() {
	int cnt = 0;
	int res = 0;
	for(int i = 0; i <= n; i++) {
		if(a[i] == 0)
			cnt += 1;
		else {
			if(cnt == k)
				res += 1;
			cnt = 0;
		}
	}
	return res == 1;
}

void quayLui(int i) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		if(i == n - 1) {
			if(check()) {
				string s = "";
				for(int idx = 0; idx < n; idx++) {
					if(a[idx] == 0) s += "A";
					else s += "B";
				}
				kq.push_back(s);
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	cin >> n >> k;
	a[n] = 1;
	quayLui(0);
	cout << kq.size() << endl;
	for(string s : kq) cout << s << endl;
	return 0;
}

