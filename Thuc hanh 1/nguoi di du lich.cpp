#include <iostream>

using namespace std;

int a[20][20];
int n;
bool used[20];
int kq;

void quayLui(int i, int cur, int sum) {
	for(int j = 1; j < n; j++) {
		if(!used[j] && sum + a[cur][j] < kq) {
			used[j] = true;
			sum += a[cur][j];
			if(i == n - 2) {
				kq = min(kq, sum + a[j][0]);
			}
			else quayLui(i + 1, j, sum);
			sum -= a[cur][j];
			used[j] = false;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		used[i] = false;
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	kq = 1e9;
	quayLui(0, 0, 0);
	cout << kq;
	return 0;
}

