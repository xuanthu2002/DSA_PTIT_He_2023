#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<string> st;
	for(int i = 0; i < n; i++) {
		int tmp = a[i], j = i - 1;
		while(j >= 0 && a[j] > tmp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
		string s = "Buoc ";
		s += to_string(i);
		s += ": ";
		for(int idx = 0; idx <= i; idx++) {
			s += to_string(a[idx]) + " ";
		}
		st.push(s);
	}
	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}

