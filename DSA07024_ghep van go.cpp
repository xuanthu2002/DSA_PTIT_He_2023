#include <iostream>
#include <stack>

using namespace std;

int solve(int a[], int n) {
	stack<int> st;
	int left[n], right[n];
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[i] <= a[st.top()]) {
			st.pop();
		}
		if(st.empty()) left[i] = 0;
		else left[i] = st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[i] <= a[st.top()]) {
			st.pop();
		}
		if(st.empty()) right[i] = n;
		else right[i] = st.top();
		st.push(i);
	}
	int kq = 0;
	for(int i = 0; i < n; i++) {
		if(right[i] - left[i] >= a[i]) {
			kq = max(kq, a[i]);
		}
	}
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << solve(a, n) << endl;
	}
	return 0;
}

