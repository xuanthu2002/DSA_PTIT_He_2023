#include <iostream>
#include <stack>

using namespace std;

void solve(int a[], int n) {
	int nextGreater[n], rightSmaller[n];
	stack<int> st;
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) {
			nextGreater[i] = -1;
		}
		else {
			while(!st.empty() && a[i] >= a[st.top()]) {
				st.pop();
			}
			if(st.empty()) nextGreater[i] = -1;
			else nextGreater[i] = st.top();
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) {
			rightSmaller[i] = -1;
		}
		else {
			while(!st.empty() && a[i] <= a[st.top()]) {
				st.pop();
			}
			if(st.empty()) rightSmaller[i] = -1;
			else rightSmaller[i] = st.top();
		}
		st.push(i);
	}
	
	for(int i = 0; i < n; i++) {
		if(nextGreater[i] != -1 && rightSmaller[nextGreater[i]] != -1) {
			cout << a[rightSmaller[nextGreater[i]]] << " ";
		}
		else cout << -1 << " ";
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

