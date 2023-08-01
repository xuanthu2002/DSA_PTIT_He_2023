#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if(s == "PUSH") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if(s == "PRINTFRONT") {
			if(q.empty()) {
				cout << "NONE" << endl;
			}
			else cout << q.front() << endl;
		}
		else {
			if(!q.empty()) q.pop();
		}
	}
	return 0;
}

