#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	long long max1 = a[0] * a[1] * a[2];
	long long max2 = a[0] * a[1] * a[n - 1];
	long long max3 = a[0] * a[n - 1] * a[n - 2];
	long long max4 = a[n - 1] * a[n - 2] * a[n - 3];
	long long max5 = a[0] * a[1];
	long long max6 = a[n - 1] * a[n - 2];
	cout << max(max1, max(max2, max(max3, max(max4, max(max5, max6))))) << endl;
	return 0;
}

