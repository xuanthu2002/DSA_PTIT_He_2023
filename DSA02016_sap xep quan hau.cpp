#include <iostream>
#include <cstring>

using namespace std;

int a[15];
bool cot[15];
bool xuoi[100];
bool nguoc[100];
int cnt = 0;
int n;

bool check() {
	
}

void quayLui(int i) {
	for(int j = 1; j <= n; j++) {
		if(!cot[j] && !xuoi[i - j + n - 1] && !nguoc[i + j - 2]) {
			a[i] = j;
			cot[j] = xuoi[i - j + n - 1] = nguoc[i + j - 2] = true;
			if(i == n - 1) {
				cnt ++;
			}
			else quayLui(i + 1);
			cot[j] = xuoi[i - j + n - 1] = nguoc[i + j - 2] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(cot, false, sizeof(cot));
		memset(xuoi, false, sizeof(xuoi));
		memset(nguoc, false, sizeof(nguoc));
		cnt = 0;
		quayLui(0);
		cout << cnt << endl;	
	}
	return 0;
}


