#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

set<string> v;
int n;
bool used[11];
string last;

void quayLui(int i, vector<string> res) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			res.push_back(*next(v.begin(), j));
			used[j] = true;
			if(i == n - 1) {
				for(string s : res) {
					cout << s << " ";
				}
				cout << last << endl;
			}
			else quayLui(i + 1, res);
			res.pop_back();
			used[j] = false;
		}
	}
}

int main() {
	cin >> n;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		v.insert(s);
	}
	memset(used, false, sizeof(used));
	cin >> last;
	v.erase(last);
	n -= 1;
	vector<string> res;
	quayLui(0, res);
	return 0;
}

