#include <iostream>
#include <algorithm>

using namespace std;

string a[100];
int n, k;
int hv[100];
bool used[100] = {false};
int kq = 1e9;

void update() {
	int minValue = 1e9, maxValue = -1e9;
	for(int i = 0; i < n; i++) {
		int num = 0;
		for(int j = 0; j < k; j++) {
			num = num * 10 + (a[i][hv[j]] - '0');
		}
		minValue = min(minValue, num);
		maxValue = max(maxValue, num);
	}
	kq = min(kq, maxValue - minValue);
}

void quayLui(int i) {
	for(int j = 0; j < k; j++) {
		if(!used[j]) {
			hv[i] = j;
			used[j] = true;
			if(i == k - 1) {
				update();
			}
			else quayLui(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	quayLui(0);
	cout << kq << endl;
	return 0;
}

