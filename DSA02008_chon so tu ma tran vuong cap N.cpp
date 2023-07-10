#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int a[100][100];
int hv[100];
bool used[100];
int n, k;
vector<string> kq;

void quayLui(int i, int sum) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			hv[i] = j;
			used[j] = true;
			sum += a[i][j];
			if(i == n - 1) {
				if(sum == k) {
					string s = "";
					for(int idx = 0; idx < n; idx++) {
						s += to_string(hv[idx] + 1) + " ";
					}
					kq.push_back(s);
				}
			}
			else quayLui(i + 1, sum);
			sum -= a[i][j];
			used[j] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	memset(used, false, sizeof(used));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	quayLui(0, 0);
	cout << kq.size() << endl;
	for(string s : kq) {
		cout << s << endl;
	}
	return 0;
}

