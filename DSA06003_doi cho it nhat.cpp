#include <iostream>

using namespace std;

int selectionSort(int arr[], int n) {
	int i, j, min_idx, kq = 0;
    for(i = 0; i < n - 1; i++) {
		min_idx = i;
		for(j = i + 1; j < n; j++)
		    if (arr[j] < arr[min_idx])
				min_idx = j;
	
	    if(min_idx != i) {
	    	swap(arr[min_idx], arr[i]);
	    	kq += 1;
		}
    }
	return kq;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << selectionSort(a, n) << endl;
	}
	return 0;
}

