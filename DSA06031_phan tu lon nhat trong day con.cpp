#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		multiset<int> ms;
		for(int i = 0; i < k; i++) {
			cin >> a[i];
			ms.insert(a[i]);
		}
		cout << *ms.rbegin() << " ";
		for(int i = k; i < n; i++) {
			cin >> a[i];
			ms.erase(ms.find(a[i - k]));
			ms.insert(a[i]);
			cout << *ms.rbegin() << " ";
		}
		cout << endl;
	}
	return 0;
}

