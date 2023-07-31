#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

//bool isOperator(string s) {
//	return s == "+" || s == "-" || s == "*" || s == "/" || s == "^";
//}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<long long> st;
		for(int i = n - 1; i >= 0; i--) {
			if(a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/" || a[i] == "^") {
				long long x = st.top();
				st.pop();
				long long y = st.top();
				st.pop();
				if(a[i] == "+") {
					st.push(x + y);
				}
				else if(a[i] == "-") {
					st.push(x - y);
				}
				else if(a[i] == "*") {
					st.push(x * y);
				}
				else if(a[i] == "/") {
					st.push(x / y);
				}
				else {
					st.push(pow(x, y));
				}
			}
			else {
				st.push(stoi(a[i]));
			}
		}
		cout << st.top() << endl;;
	}
	return 0;
}

