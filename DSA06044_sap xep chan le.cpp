#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	vector<int> chan, le;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(i & 1) {
			chan.push_back(x);
		}
		else {
			le.push_back(x);
		}
	}
	sort(le.begin(), le.end());
	sort(chan.begin(), chan.end(), greater<int>());
	int i = 0, j = 0;
	while(i < le.size() && j < chan.size()) {
		cout << le[i] << " " << chan[j] << " ";
		i += 1;
		j += 1;
	}
	while(i < le.size()) {
		cout << le[i];
		i += 1;
	}
	while(j < chan.size()) {
		cout << chan[j];
		j += 1;
	}
	return 0;
}

