#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<string> binary;

void init() {
	queue<string> q;
	q.push("1");
	for(int i = 0; i < 10000; i++) {
		string s = q.front();
		q.pop();
		binary.push_back(s);
		q.push(s + "0");
		q.push(s + "1");
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cout << binary[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

