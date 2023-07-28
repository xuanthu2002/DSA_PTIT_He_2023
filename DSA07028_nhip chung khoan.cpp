#include <iostream>
#include <stack>

using namespace std;

void solve(int a[], int n) {
	int kq[n];
	stack<int> st;
	for(int i = 0; i < n; i++) {
		if(st.empty()) {
			kq[i] = 1;
		}
		else {
			while(!st.empty() && a[i] >= a[st.top()]) {
				st.pop();
			}
			if(!st.empty()) kq[i] = i - st.top();
			else kq[i] = 1;
		}
		st.push(i);
	}
	for(int i = 0; i < n; i++) cout << kq[i] << " ";
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

