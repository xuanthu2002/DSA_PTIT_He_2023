#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct Bang {
	int a[2][3];
	
	Bang() {}
	
	friend bool operator == (Bang A, Bang B) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				if(A.a[i][j] != B.a[i][j]) return false;
			}
		}
		return true;
	}
};

Bang st, en;

const int LEFT = 0;
const int RIGHT = 1;

Bang xoay(Bang A, int i) {
	Bang B = A;
	A.a[0][0 + i] = B.a[1][0 + i];
	A.a[0][1 + i] = B.a[0][0 + i];
	A.a[1][0 + i] = B.a[1][1 + i];
	A.a[1][1 + i] = B.a[0][1 + i];
	return A;
}

vector<Bang> visited;

bool chuaxet(Bang bang) {
	for(Bang i : visited) {
		if(i == bang) return false;
	}
	return true;
}

int solve() {
	queue<pair<Bang, int>> q;
	q.push({st, 0});
	visited.clear();
	while(!q.empty()) {
		Bang top = q.front().first;
		int d = q.front().second;
		if(top == en) return d;
		q.pop();
		visited.push_back(top);
		Bang bang = xoay(top, LEFT);
		if(chuaxet(bang)) {
			q.push({bang, d + 1});
		}
		bang = xoay(top, RIGHT);
		if(chuaxet(bang)) {
			q.push({bang, d + 1});
		}
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> st.a[i][j];
			}
		}
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> en.a[i][j];
			}
		}
		cout << solve() << endl;
	}
	return 0;
}

