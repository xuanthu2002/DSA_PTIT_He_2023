#include<iostream>

using namespace std;

int a[100];
int n;

void quayLui(int i) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		if(i == n - 1) {
			for(int idx = 0; idx < n; idx++) {
				cout << (char) (a[idx] + 'A');
			}
			cout << " ";
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		quayLui(0);
		cout << endl;
	}
	return 0;
}

