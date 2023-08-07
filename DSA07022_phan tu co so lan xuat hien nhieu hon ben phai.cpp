#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		map<int, int> m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] += 1;
		}
		int kq[n];
		stack<int> st;
		for(int i = n - 1; i >= 0; i--) {
			while(!st.empty() && m[a[i]] >= m[st.top()]) {
				st.pop();
			}
			if(st.empty()) kq[i] = -1;
			else kq[i] = st.top();
			st.push(a[i]);
		}
		for(int i = 0; i < n; i++) cout << kq[i] << " ";
		cout << endl;
	}
	return 0;
}

