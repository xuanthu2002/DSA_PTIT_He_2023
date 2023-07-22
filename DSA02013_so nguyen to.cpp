#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> nt;
int n, s;
int m;
int b[201];
vector<string> kq;

void init() {
	nt.push_back(0);
	bool a[201] = {false};
	for(int i = 2; i <= 200; i++) a[i] = true;
	for(int i = 2; i <= sqrt(200); i++) {
		if(a[i]) {
			for(int j = i * i; j <= 200; j += i) {
				a[j] = false;
			}
		}
	}
	for(int i = 2; i <= 200; i++) {
		if(a[i]) {
			nt.push_back(i);
		}
	}
	cout << endl;
}

void quayLui(int i, int sum) {
	for(int j = b[i - 1] + 1; j <= m - n + i - 1; j++) {
		b[i] = j;
		sum += nt[j];
		if(i == n) {
			if(sum == s) {
				string tmp = "";
				for(int idx = 1; idx <= n; idx++) {
					tmp += to_string(nt[b[idx]]) + " ";
				}
				kq.push_back(tmp);
			}
		}
		else quayLui(i + 1, sum);
		sum -= nt[j];
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int p;
		cin >> n >> p >> s;
		int i = 0;
		while(i < nt.size() && nt[i] <= p) i += 1;
		m = nt.size();
		b[0] = i - 1;
		quayLui(1, 0);
		cout << kq.size() << endl;
		sort(kq.begin(), kq.end());
		for(string i : kq) {
			cout << i << endl;
		}
		kq.clear();
	}
	return 0;
}
