#include <iostream>
#include <algorithm>

using namespace std;

int a[100];
int n;
bool used[100];
int hv[100];

void quayLui(int i) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			hv[i] = j;
			used[j] = true;
			if(i == n - 1) {
				for(int idx = 0; idx < n; idx++) {
					cout << a[hv[idx]] << " ";
				}
				cout << endl;
			}
			else quayLui(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		used[i] = false;
	}
	sort(a, a + n);
	quayLui(0);
	return 0;
}

