#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int octo_num(char c) {
	switch (c) {
	case '-' :
		return 0;
	case '\\' :
		return 1;
	case '(' :
		return 2;
	case '@' :
		return 3;
	case '?' :
		return 4;
	case '>' :
		return 5;
	case '&' :
		return 6;
	case '%' :
		return 7;
	case '/' :
		return -1;
	}
	return 0;
}

int main() {
	string str; int len, sum = 0;
	while ((cin >> str) && str[0] != '#') {
		sum = 0;
		len = str.size();
		for (int i = 0; i < len; i++) {
			sum += octo_num(str[len - 1 - i]) * pow(8, i);
		}
		cout << sum << endl;
	}
	return 0;
}