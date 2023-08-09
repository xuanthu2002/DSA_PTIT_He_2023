#include <iostream>

using namespace std;

const char _operator[] = {'+', '-', '*'};

int IN[5];
int A[5];

int calculator(int a, int b, char c) {
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	return a * b;
} 

bool solve() {
	for(char a : _operator) {
		for(char b : _operator) {
			for(char c : _operator) {
				for(char d : _operator) {
					int res = calculator(A[0], A[1], a);
					res = calculator(res, A[2], b);
					res = calculator(res, A[3], c);
					res = calculator(res, A[4], d);
					if(res == 23) return true;
				}
			}
		}
	}
	return false;
}

int hv[5];
bool used[5];

bool quayLui(int i) {
	for(int j = 0; j < 5; j++) {
		if(!used[j]) {
			hv[i] = j;
			used[j] = true;
			if(i == 4) {
				for(int idx = 0; idx < 5; idx++) A[idx] = IN[hv[idx]];
				if(solve()) return true;
			}
			else if(quayLui(i + 1)) return true;
			used[j] = false;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 0; i < 5; i++) {
			cin >> IN[i];
			used[i] = false;
		}
		if(quayLui(0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

