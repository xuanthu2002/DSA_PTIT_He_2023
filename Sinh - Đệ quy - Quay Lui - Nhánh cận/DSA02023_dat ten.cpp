#include <iostream>
#include <set>

using namespace std;

int a[100];
int n, k;
set<string> s;

void quayLui(int i) {
	for(int j = a[i - 1] + 1; j < n - k + i; j++) {
		a[i] = j;
		if(i == k) {
			for(int idx = 1; idx <= k; idx++) {
				cout << *(next(s.begin(), a[idx])) << " ";
			}
			cout << endl;
		}
		else quayLui(i + 1);
	}
}

int main() {
	cin >> n >> k;
	a[0] = -1;
	for(int i = 0; i < n; i++) {
		string x;
		cin >> x;
		s.insert(x);
	}
	n = s.size();
	quayLui(1);
	return 0;
}


