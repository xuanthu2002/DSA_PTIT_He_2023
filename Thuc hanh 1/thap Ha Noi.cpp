#include <iostream>

using namespace std;

void quayLui(int n, char a, char b, char c) {
	if(n == 1) {
		cout << a << " -> " << c << endl;
		return;
	}
	quayLui(n - 1, a, c, b);
	quayLui(1, a, b, c);
	quayLui(n - 1, b, a, c);
}

int main() {
	int n;
	cin >> n;
	quayLui(n, 'A', 'B', 'C');
	return 0;
}

