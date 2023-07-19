#include <iostream>
#include <vector>

using namespace std;

bool ok;
int a[11];
int n, cnt;

void sinh() {
	int i = cnt - 1;
	while(i >= 0 && a[i] == 1) {
		i -= 1;
	}
	if(i < 0) {
		ok = false;
		return;
	}
	a[i] -= 1;
	int d = cnt - i;
	int q = d / a[i];
	int r = d % a[i];
	cnt = i + 1;
	while(q--) {
		a[cnt] = a[i];
		cnt += 1;
	}
	if(r) {
		a[cnt] = r;
		cnt += 1;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		a[0] = n;
		cnt = 1;
		ok = true;
		vector<string> kq;
		while(ok) {
			string s = "(";
			for(int i = 0; i < cnt; i++) {
				s += to_string(a[i]) + " ";
			}
			s.pop_back();
			s += ")";
			kq.push_back(s);
			sinh();
		}
		cout << kq.size() << endl;
		for(string s : kq) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}

