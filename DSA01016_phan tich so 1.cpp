#include <iostream>

using namespace std;

int n;
int a[100];
bool ok;
int cnt;

void sinh() {
	int i = cnt - 1;
	while(i >= 0 && a[i] == 1) {
		i -= 1;
	}
	if(i < 0) ok = false;
	else {
		a[i] -= 1;
		int d = cnt - i;
		cnt = i + 1;
		int q = d / a[i];
		int r = d % a[i];
		while(q--) {
			a[cnt] = a[i];
			cnt += 1;
		}
		if(r) {
			a[cnt] = r;
			cnt += 1;
		}
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
		while(ok) {
			cout << "(";
			for(int i = 0; i < cnt - 1; i++) {
				cout << a[i] << " ";
			}
			cout << a[cnt - 1] << ") ";
			sinh();
		}
		cout << endl;
	}
	return 0;
}

