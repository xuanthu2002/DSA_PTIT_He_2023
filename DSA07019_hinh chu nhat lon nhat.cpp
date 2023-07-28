#include <iostream>
#include <stack>

using namespace std;

long long solve(int a[], int n) {
	stack<int> st;
	int left[n], right[n];
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) {
			right[i] = n;
		}
		else {
			while(!st.empty() && a[i] <= a[st.top()]) {
				st.pop();
			}
			if(st.empty()) {
				right[i] = n;
			}
			else {
				right[i] = st.top();
			}
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = 0; i < n; i++) {
		if(st.empty()) {
			left[i] = -1;
		}
		else {
			while(!st.empty() && a[i] <= a[st.top()]) {
				st.pop();
			}
			if(st.empty()) {
				left[i] = -1;
			}
			else {
				left[i] = st.top();
			}
		}
		st.push(i);
	}
	long long kq = 0;
	for(int i = 0; i < n; i++) {
		kq = max(kq, (long long) a[i] * (right[i] - 1 - left[i]));
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

