#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i]; 
		stack<int> st;
		int kq[n];
		for(int i = 0; i < n; i++) {
			if(st.empty()) {
				kq[i] = i + 1;
			}
			else {
				while(!st.empty() && a[i] >= a[st.top()]) {
					st.pop();
				}
				if(st.empty()) {
					kq[i] = i + 1;
				}
				else kq[i] = i - st.top();
			}
			st.push(i);
		}
		for(int i = 0; i < n; i++) cout << kq[i] << " ";
		cout << endl;
	}
	return 0;
}

