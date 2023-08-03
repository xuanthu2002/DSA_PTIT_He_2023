#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<int> ke[n + 1];
		while(m--) {
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		string kq = "YES";
		for(auto i : ke) {
			for(int j : i) {
				if(i.size() != ke[j].size()) {
					kq = "NO";
					break;
				}
			}
		}
		cout << kq << endl;
	}
	return 0;
}

