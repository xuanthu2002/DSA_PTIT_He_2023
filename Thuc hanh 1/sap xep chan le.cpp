#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> chan, le;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(i & 1) {
			chan.push_back(x);
		}
		else le.push_back(x);
	}
	sort(le.begin(), le.end());
	sort(chan.begin(), chan.end(), greater<int>());
	int i = 0;
	while(i < chan.size() && i < le.size()) {
		cout << le[i] << " " << chan[i] << " ";
		i += 1;
	}
	while(i < le.size()) {
		cout << le[i] << " ";
		i += 1;
	}
	while(i < chan.size()) {
		cout << chan[i] << " ";
		i += 1;
	}
	return 0;
}

