#include<iostream>

using namespace std;

int merge(int a[], int b[], int l, int r, int mid) {
    int i = l, j = i, k = mid;
    int res = 0;
    while(i < mid && k <= r) {
        if(a[i] <= a[k]) {
        	b[j] = a[i];
        	j += 1;
        	i += 1;
		}
        else {
            b[j] = a[k];
            j += 1;
            k += 1;
            res += mid - i;
        }
    }
    while(i < mid) {
    	b[j] = a[i];
    	j += 1;
    	i += 1;
	}
    while(k <= r) {
    	b[j] = a[k];
    	j += 1;
    	k += 1;
	}
    for(i = l; i <= r; i++) a[i] = b[i];
    return res;
}

int Sort(int a[], int b[], int l, int r) {
    int res = 0;
    if(l < r) {
        int mid = (l + r) / 2;
        res += Sort(a, b, l, mid);
        res += Sort(a, b, mid + 1, r);
        res += merge(a, b, l, r, mid + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], c[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    int idx = 0;
    for (int i = 0; i < n; i++) {
    	if(a[i] % 2 == 0) {
    		c[idx] = a[i];
    		idx += 1;
		}
	}
    int res = Sort(c, b, 0, idx - 1);
    int cnt = 0;
    a[n] = 1;
    for (int i = 1; i <= n; i++) {
        if(a[i] % 2 == 0 and a[i - 1] % 2 == 0) cnt = cnt + 1;
        else if(a[i] % 2 != 0 and a[i - 1] % 2 == 0) {
            res -= Sort(a, b, i - cnt - 1, i - 1);
            cnt = 0;
        }
    }
    cout << res;
    return 0;
}
