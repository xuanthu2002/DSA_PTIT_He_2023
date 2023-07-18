#include <iostream>

using namespace std;

int a[100];
int n;
bool ok;

void sinh() {
	int i = n - 1;
	while(a[i] == 1 && i >= 0) {
		a[i] = 0;
		i -= 1;
	}
	if(i >= 0) a[i] = 1;
	else ok = false;
}

int main() {
	cin >> n;
	int len;
	if(n % 2 != 0) {
		n = n / 2 + 1;
		len = n - 1;
	}
	else {
		n /= 2;
		len = n;
	}
	ok = true;
	for(int i = 0; i < n; i++) a[i] = 0;
	while(ok) {
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		for(int i = len - 1; i >= 0; i--) cout << a[i] << " ";
		cout << endl;
		sinh();
	}
	return 0;
}

