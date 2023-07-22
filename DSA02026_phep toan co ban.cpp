#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string s;
vector<int> pos;
bool kq;

bool check() {
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(5, 2));
	int c = stoi(s.substr(10, 2));
	if(s[3] == '?') {
		if(a * b == c) {
			s[3] = '*';
			return true;
		}
		if(a + b == c) {
			s[3] = '+';
			return true;
		}
		if(a - b == c) {
			s[3] = '-';
			return true;
		}
		if(b * c == a) {
			s[3] = '/';
			return true;
		}
	}
	else {
		if(s[3] == '+' && a + b == c) return true;
		if(s[3] == '-' && a - b == c) return true;
		if(s[3] == '*' && a * b == c) return true;
		if(s[3] == '/' && b * c == a) return true;
	}
	return false;
}

void quayLui(int i) {
	int j = ((pos[i] == 0 || pos[i] == 5 || pos[i] == 10) ? 1 : 0);
	for(; j < 10; j++) {
		if(kq) return;
		s[pos[i]] = (char) (j + '0');
		if(i == pos.size() - 1) {
			if(check()) {
				kq = true;
				return;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		getline(cin, s);
		pos.clear();
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '?' && i != 3) {
				pos.push_back(i);
			}
		}
		if(pos.size() < 1) {
			if(check()) {
				cout << s << endl;
			}
			else cout << "WRONG PROBLEM!" << endl;
			continue;
		}
		kq = false;
		quayLui(0);
		if(!kq) {
			cout << "WRONG PROBLEM!" << endl;
		}
		else cout << s << endl;
	}
	return 0;
}

