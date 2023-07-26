#include <iostream>
#include <algorithm>

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
		bool slot[n];
		for(int i = 0; i < n; i++) {
			cin >> j[i].jobId >> j[i].deadline >> j[i].profit;
			slot[i] = true;
		}
		sort(j, j + n, cmp);
		int kq = 0, cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int idx = min(n, j[i].deadline) - 1; idx >= 0; idx--) {
				if(slot[idx]) {
					kq += j[i].profit;
					slot[idx] = false;
					cnt += 1;
					break;
				}
			}
		}
		cout << cnt << " " << kq << endl;
	}
	return 0;
}

