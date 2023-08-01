#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	deque<int> q;
	while(t--) {
		string s;
		cin >> s;
		if(s == "PUSHFRONT") {
			int x;
			cin >> x;
			q.push_front(x);
		}
		else if(s == "PRINTFRONT") {
			if(q.empty()) cout << "NONE" << endl;
			else cout << q.front() << endl;
		}
		else if(s == "POPFRONT") {
			if(!q.empty()) {
				q.pop_front();
			}
		}
		else if(s == "PUSHBACK") {
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if(s == "PRINTBACK") {
			if(q.empty()) cout << "NONE" << endl;
			else cout << q.back() << endl;
		}
		else {
			if(!q.empty()) {
				q.pop_back();
			}
		}
	}
	return 0;
}

