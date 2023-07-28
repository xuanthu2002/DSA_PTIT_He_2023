#include <iostream>
#include <vector>

using namespace std;

long long merge(long long a[], int l, int m, int r) {
	vector<long long> left(a + l, a + m + 1);
	vector<long long> right(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	long long cnt = 0;
	while(i < left.size() && j < right.size()) {
		if(left[i] > right[j]) {
			cnt += left.size() - i;
			a[l] = right[j];
			l += 1;
			j += 1;
		}
		else {
			a[l] = left[i];
			i += 1;
			l += 1;
		}
	}
	while(i < left.size()) {
		a[l] = left[i];
		l += 1;
		i += 1;
	}
	while(j < right.size()) {
		a[l] = right[j];
		l += 1;
		j += 1;
	}
	return cnt;
}

long long mergeSort(long long a[], int l, int r) {
	if(l < r) {
		int m = (l + r) / 2;
		return mergeSort(a, l, m) + mergeSort(a, m + 1, r) + merge(a, l, m, r);
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << mergeSort(a, 0, n - 1) << endl;
	}
	return 0;
}

