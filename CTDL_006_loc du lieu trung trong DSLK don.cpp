#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> s;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int tmp = s.size();
		s.insert(x);
		if(tmp != s.size()) {
			cout << x << " ";
		}
	}
	return 0;
}

