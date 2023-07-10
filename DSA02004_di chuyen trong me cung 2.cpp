#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[100][100];
int n;
bool kq;

void quayLui(string path, int x, int y) {
	if(x == n && y == n) {
		cout << path << " ";
		kq = true;
		return;
	}
	if(x > n || y > n) return;
	a[x][y] = 0;
	if(a[x + 1][y] == 1) {
		quayLui(path + "D", x + 1, y);
		a[x + 1][y] = 1;
	}
	if(a[x][y - 1] == 1) {
		quayLui(path + "L", x, y - 1);
		a[x][y - 1] = 1;
	}
	if(a[x][y + 1] == 1) {
		quayLui(path + "R", x, y + 1);
		a[x][y + 1] = 1;
	}
	if(a[x - 1][y] == 1) {
		quayLui(path + "U", x - 1, y);
		a[x - 1][y] = 1;
	}	
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		kq = false;
		if(a[1][1] == 0) {
			cout << "-1" << endl;
			continue;
		}
		quayLui("", 1, 1);
		if(!kq) {
			cout << "-1";
		}
		cout << endl;
	}
	return 0;
}

