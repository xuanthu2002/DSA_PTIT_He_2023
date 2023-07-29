#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Job {
	int jobId, deadline, profit;
};

bool cmp(Job a, Job b) {
	return a.profit > b.profit;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Job j[n];
		bool slot[1001];
		memset(slot, true, sizeof(slot));
		for(int i = 0; i < n; i++) {
			cin >> j[i].jobId >> j[i].deadline >> j[i].profit;
		}
		sort(j, j + n, cmp);
		int kq = 0, cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int idx = j[i].deadline - 1; idx >= 0; idx--) {
				if(slot[idx]) {
					kq += j[i].profit;
					cnt += 1;
					slot[idx] = false;
					break;
				}
			}
		}
		cout << cnt << " " << kq << endl;
	}
	return 0;
}

