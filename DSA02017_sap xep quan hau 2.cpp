#include <iostream>
#include <cstring>

using namespace std;

int a[8][8];
int n = 8;
bool cot[8], xuoi[16], nguoc[16];
int kq;

void quayLui(int i, int sum) {
	for(int j = 0; j < n; j++) {
		if(!cot[j] && !xuoi[i - j + n -1] && !nguoc[i + j]) {
			sum += a[i][j];
			cot[j] = true;
			xuoi[i - j + n - 1] = true;
			nguoc[i + j] = true;
			if(i == n - 1) {
				kq = max(kq, sum);
			}
			else quayLui(i + 1, sum);
			cot[j] = false;
			xuoi[i - j + n - 1] = false;
			nguoc[i + j] = false;
			sum -= a[i][j];
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		memset(cot, false, sizeof(cot));
		memset(xuoi, false, sizeof(xuoi));
		memset(nguoc, false, sizeof(nguoc));
		kq = -1e9;
		quayLui(0, 0);
		cout << kq << endl;
	}
	return 0;
}

