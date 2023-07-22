#include <iostream>

using namespace std;

string s, ans;

void quayLui(int k) {
	if(k == 0) return ;
	int n = s.length();
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(s[i] < s[j]) {
				swap(s[i], s[j]);
				if(s > ans) {
					ans = s;
				}
				quayLui(k - 1);
				swap(s[i], s[j]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k >> s;
		ans = s;
		quayLui(k);
		cout << ans << endl;
	}
	return 0;
}


