#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	int n;
	cin >> n;
	fstream out("input.txt");
	out << n << endl;
	srand(time(NULL));
	for(int i = 0; i < n; i++) {
		out << rand() % 100000 << " ";
		if((i + 1) % 10 == 0) {
			out << endl;
		}
	}
	out.close();
	return 0;
}

