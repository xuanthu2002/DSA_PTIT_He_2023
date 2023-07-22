#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> nt;
int n, s;
vector<vector<int>> kq;

bool isPrime(int x) {
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) return false;
	}
	return true;
}

void init()	{
	nt.push_back(2);
	for(int i = 3; i < 200; i += 2) {
		if(isPrime(i)) {
			nt.push_back(i);
		}
	}
}

void quayLui(int i, vector<int> res, int sum) {
	if(res.size() == n && sum == s) {
		kq.push_back(res);
		return;
	}
	if(i < nt.size() && res.size() < n) {
		if(sum + nt[i] <= s) {
			res.push_back(nt[i]);
			quayLui(i + 1, res, sum + nt[i]);
			res.pop_back();
		}
		quayLui(i + 1, res, sum);
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int p;
		cin >> n >> p >> s;
		int l = 0, r = nt.size() - 1;;
		while(l < nt.size() && nt[l] <= p) {
			l += 1;
		}
		kq.clear();
		vector<int> res;
		quayLui(l, res, 0);
		cout << kq.size() << endl;
		for(auto i : kq) {
			for(auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

