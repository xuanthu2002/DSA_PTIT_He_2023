#include <iostream>
#include <fstream>

using namespace std;

int a[100];
int c[100];
int n, w;
int fopt;
int x[100];
int xopt[100];

void quayLui(int i, int sum, int cost) {
	for(int j = 0; j < 2; j++) {
		x[i] = j;
		cost += a[i] * j;
		sum += c[i] * j;
		if(i == n - 1) {
			if(cost <= w && sum > fopt) {
				for(int idx = 0; idx < n; idx++) xopt[idx] = x[idx];
				fopt = sum;
			}
		}
		else quayLui(i + 1, sum, cost);
		sum -= a[i] * j;
		cost -= c[i] * j;
	}
}

int main() {
//	fstream fIn("data.in");
//	fIn >> n >> w;
//	for(int i = 0; i < n; i++) fIn >> c[i];
//	for(int i = 0; i < n; i++) fIn >> a[i];
	cin >> n >> w;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	fopt = -1;
	quayLui(0, 0, 0);
	cout << fopt << endl;
	for(int i = 0; i < n; i++) cout << xopt[i] << " ";
//	fIn.close();
	return 0;
}

