#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100];
int b[100];

void quayLui(int i, int sum) {
	for(int j = 0; j < 2; j++) {
		b[i] = j;
		sum += a[i] * j;
		if(i == n - 1) {
			if(sum & 1) {
				for(int idx = 0; idx <= i; idx++) {
					if(b[idx] > 0) {
						cout << a[idx] << " ";
					}
				}
				cout << endl;
			}
		}
		else quayLui(i + 1, sum);
		sum -= a[i] * j;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		quayLui(0, 0);
	}
	return 0;
}

