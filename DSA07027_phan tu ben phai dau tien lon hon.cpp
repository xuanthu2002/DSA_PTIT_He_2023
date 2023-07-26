#include <iostream>
#include <stack>

using namespace std;

void solve(int a[], int n) {
	stack<int> st;
	int kq[n];
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) {
			kq[i] = -1;
		}
		else {
			while(!st.empty() && a[st.top()] <= a[i]) {
				st.pop();
			}
			if(!st.empty()) {
				kq[i] = st.top();
			}
			else kq[i] = -1;
		}
		st.push(i);
	}
	for(int i = 0; i < n; i++) {
		if(kq[i] != -1) {
			cout << a[kq[i]] << " ";
		}
		else cout << kq[i] << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		solve(a, n);
	}
	return 0;
}

