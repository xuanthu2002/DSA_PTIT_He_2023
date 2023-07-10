#include <iostream>

using namespace std;

int a[100];
int n, k, s;
int kq;

void quayLui(int i, int sum) {
	for(int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		sum += a[i];
		if(i == k) {
			if(sum == s) {
				kq += 1;
			}
		}
		else quayLui(i + 1, sum);
		sum -= a[i];
	}
}

int main() {
	a[0] = 0;
	while(cin >> n >> k >> s) {
		if(n == 0 && k == 0 && s == 0) {
			break;
		}
		kq = 0;
		quayLui(1, 0);
		cout << kq << endl;
	}
	return 0;
}

