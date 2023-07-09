#include <iostream>

using namespace std;

int a[100];
int n;
int S;
bool kq = false;

void quayLui(int i, int sum) {
	if(kq) return;
	if(sum * 2 == S) {
		kq = true;
		return;
	}
	if(i < n) {
		if((a[i] + sum) * 2 <= S) {
			quayLui(i + 1, sum + a[i]);
		}
		quayLui(i + 1, sum); 
	}
}

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		S = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			S += a[i];
		}
		kq = false;
		if(S % 2 == 0) quayLui(0, 0);
		if(kq) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}


