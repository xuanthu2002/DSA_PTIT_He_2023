#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for(i = 0; i < n - 1; i++) {
		min_idx = i;
		for(j = i + 1; j < n; j++)
		    if (arr[j] < arr[min_idx])
				min_idx = j;
	
	    swap(arr[min_idx], arr[i]);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt[10] = {0};
		int b[1000];
		int len = 0;
		for(int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			while(x) {
				if(cnt[x % 10] == 0) {
					cnt[x % 10] += 1;
					b[len++] = x % 10;
				}
				x /= 10;
			}
		}
		selectionSort(b, len);
		for(int i = 0; i < len; i++) {
			cout << b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

