#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		deque<int> q;
		while(n--) {
			int x;
			cin >> x;
			switch(x) {
				case 1: {
					cout << q.size() << endl;
					break;
				}
				case 2: {
					cout << (q.empty() ? "YES" : "NO") << endl;
					break;
				}
				case 3: {
					int a;
					cin >> a;
					q.push_back(a);
					break;
				}
				case 4: {
					if(!q.empty()) {
						q.pop_front();
					}
					break;
				}
				case 5: {
					if(q.empty()) {
						cout << -1 << endl;
					}
					else cout << q.front() << endl;
					break;
				}
				case 6: {
					if(q.empty()) {
						cout << -1 << endl;
					}
					else cout << q.back() << endl;
					break;
				}
			}
		}
	}
	return 0;
}

