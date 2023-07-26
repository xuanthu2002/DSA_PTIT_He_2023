#include <iostream>
#include <cstring>

using namespace std;

int F[40001], A[201], n , s;

int qhd() {
	memset(F, 0, sizeof(F));
	F[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = s; j >= A[i]; j--) {
			if(F[j] == 0 && F[j - A[i]] == 1) {
				F[j] = 1;
			}
		}
	}
	return F[s];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> s;
		for(int i = 1; i <= n; i++) cin >> A[i];
		if(qhd() == 1) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

