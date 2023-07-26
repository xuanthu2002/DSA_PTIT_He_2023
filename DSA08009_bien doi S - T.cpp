#include <iostream>

using namespace std;

void process() {
	int s, t;
	cin >> s >> t;
	int kq = 0;
	while(s < t) {
		if(t % 2 == 0) {
			t /= 2;
		}
		else t += 1;
		kq += 1;
	}
	kq += s - t;
	cout << kq << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		process();
	}
	return 0;
}

