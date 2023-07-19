#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> kq;
string s;

void quayLui(int i, int cnt, string res) {
	for(int j = 0; j < 2; j++) {
		if(j == 1) {
			res += s[i];
		}
		cnt += j;
		if(i == n - 1) {
			if(cnt > 0) {
				kq.push_back(res);
			}
		}
		else quayLui(i + 1, cnt, res);
		cnt -= j;
		if(j == 1) res.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		cin >> s;
		n = s.length();
		quayLui(0, 0, "");
		sort(kq.begin(), kq.end());
		for(string i : kq) {
			cout << i << " ";
		}
		kq.clear();
		cout << endl;
	}
	return 0;
}

