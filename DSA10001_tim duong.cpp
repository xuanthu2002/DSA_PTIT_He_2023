#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int DOWN = 0;
const int UP = 1;
const int RIGHT = 2;
const int LEFT = 3;

int a[502][502];
int n, m;
pair<int, int> st, en;

struct Position {
	int x, y;
	int huong;
	
	Position(int _x, int _y, int _huong) {
		x = _x;
		y = _y;
		huong = _huong;
	}
};

string solve() {
	queue<pair<int, Position>> q;
	q.push({0, Position(st.first, st.second, DOWN)});
	q.push({0, Position(st.first, st.second, UP)});
	q.push({0, Position(st.first, st.second, LEFT)});
	q.push({0, Position(st.first, st.second, RIGHT)});
	while(!q.empty()) {
		int d = q.front().first;
		int x = q.front().second.x;
		int y = q.front().second.y;
		int huong = q.front().second.huong;
		a[x][y] = 0;
		q.pop();
		if(x == en.first && y == en.second) {
			return "YES";
		}
		switch(huong) {
			case DOWN: {
				if(x + 1 <= n && a[x + 1][y])
					q.push({d, Position(x + 1, y, DOWN)});
				if(d < 2) {
					if(x - 1 >= 1 && a[x - 1][y])
						q.push({d + 1, Position(x - 1, y, UP)});
					if(y - 1 >= 1 && a[x][y - 1])
						q.push({d + 1, Position(x, y - 1, LEFT)});
					if(y + 1 <= m && a[x][y + 1])
						q.push({d + 1, Position(x, y + 1, RIGHT)});
				}
				break;
			}
			case UP: {
				if(x - 1 >= 1 && a[x - 1][y])
					q.push({d, Position(x - 1, y, UP)});
				if(d < 2) {
					if(x + 1 <= n && a[x + 1][y])
						q.push({d + 1, Position(x + 1, y, DOWN)});
					if(y - 1 >= 1 && a[x][y - 1])
						q.push({d + 1, Position(x, y - 1, LEFT)});
					if(y + 1 <= m && a[x][y + 1])
						q.push({d + 1, Position(x, y + 1, RIGHT)});
				}
				break;
			}
			case LEFT: {
				if(y - 1 >= 1 && a[x][y - 1])
					q.push({d, Position(x, y - 1, LEFT)});
				if(d < 2) {
					if(x + 1 <= n && a[x + 1][y])
						q.push({d + 1, Position(x + 1, y, DOWN)});
					if(x - 1 >= 1 && a[x - 1][y])
						q.push({d + 1, Position(x - 1, y, UP)});
					if(y + 1 <= m && a[x][y + 1])
						q.push({d + 1, Position(x, y + 1, RIGHT)});
				}
				break;
			}
			case RIGHT: {
				if(y + 1 <= m && a[x][y + 1])
					q.push({d, Position(x, y + 1, RIGHT)});
				if(d < 2) {
					if(x + 1 <= n && a[x + 1][y])
						q.push({d + 1, Position(x + 1, y, DOWN)});
					if(x - 1 >= 1 && a[x - 1][y])
						q.push({d + 1, Position(x - 1, y, UP)});
					if(y - 1 >= 1 && a[x][y - 1])
						q.push({d + 1, Position(x, y - 1, LEFT)});
				}
				break;
			}
		}
	}
	return "NO";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		char c;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> c;
				if(c == '.') {
					a[i][j] = 1;
				}
				else if(c == '*') {
					a[i][j] = 0;
				}
				else if(c == 'S') {
					a[i][j] = 1;
					st.first = i;
					st.second = j;
				}
				else if(c == 'T') {
					a[i][j] = 1;
					en.first = i;
					en.second = j;
				}
			}
		}
		cout << solve() << endl;
	}
	return 0;
}

