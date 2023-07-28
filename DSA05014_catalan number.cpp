#include <iostream>

using namespace std;

string operator * (string x, string y) {
	string res = "";
	int lenx = x.length(), leny = y.length();
 
	while(res.length() < lenx + leny) {
		res += "0";
	}

	int carry = 0;
	for(int i = leny - 1; i >= 0; i--){
		carry = 0;
		int j;
		for(j = lenx - 1; j >= 0; j--) {
			int num = (y[i] - 48) * (x[j] - 48) + carry;
			int tmp = (res[i + j + 1] - 48) + num;
			carry = tmp / 10;
			tmp %= 10;
			res[i + j + 1] = (char) (tmp + 48);
		}
		while(carry > 0) {
			int tmp = (res[i + j + 1] - 48) + carry;
			carry = tmp / 10;
			tmp %= 10;
			res[i + j + 1] = (char) (tmp + 48);
			j--;
		}
	}
	while(res[0] == '0' && res.length() > 1) {
		res.erase(0, 1);
	}
	return res;
}

string tong(string a, string b) {
	string res = "";
	while(a.length() < b.length()) {
		a = "0" + a;
	}
	while(a.length() > b.length()) {
		b = "0" + b;
	}
	int n = a.length();
	int nho = 0;
	for(int i = n - 1; i >= 0; i--) {
		int x = a[i] - '0';
		int y = b[i] - '0';
		int s = x + y + nho;
		nho = s / 10;
		s %= 10;
		res = (char) (s + '0') + res;
	}
	if(nho > 0) {
		res = (char) (nho + '0') + res;
	}
	return res;
}

int main() {
	string C[101] = {"0"};
	C[0] = "1";
	C[1] = "1";
	C[2] = "2";
	for(int i = 3; i <= 100; i++) {
		for(int j = 0; j < i; j++) {
			C[i] = tong(C[i], C[j] * C[i - 1 - j]);
		}
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << C[n] << endl;
	}
	return 0;
}

