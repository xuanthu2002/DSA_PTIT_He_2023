#include <iostream>
#include <queue>

using namespace std;

vector<string> v;

void init() {
	queue<string> q;
	q.push("6");
	q.push("8");
	v.push_back("6");
	v.push_back("8");
	while(1) {
		string top = q.front();
		q.pop();
		if(top.length() >= 15) return;
		v.push_back(top + "6");
		v.push_back(top + "8");
		q.push(top + "6");
		q.push(top + "8");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	init();
	while(t--) {
		int n;
		cin >> n;
		int i = v.size() - 1;
		while(v[i].length() > n) {
			i --;
		}
		cout << i + 1 << endl;
		for(int j = 0; j <= i; j++) {
			cout << v[j] << " ";
		}
		cout << endl;
	}
	return 0;
}
