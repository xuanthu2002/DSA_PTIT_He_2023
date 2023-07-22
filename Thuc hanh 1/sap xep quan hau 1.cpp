#include <iostream>
#include <cstring>

using namespace std;

int n;
bool cot[11], xuoi[20], nguoc[20];
int kq;

void quayLui(int i) {
	for(int j = 0; j < n; j++) {
		if(!cot[j] && !xuoi[i + n - j] && !nguoc[i + j]) {
			cot[j] = true;
			xuoi[i + n - j] = true;
			nguoc[i + j] = true;
			if(i == n - 1) {
				kq += 1;
			}
			else quayLui(i + 1);
			cot[j] = false;
			xuoi[i + n - j] = false;
			nguoc[i + j] = false;
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
		kq = 0;
		quayLui(0);
		cout << kq << endl;
	}
	return 0;
}

