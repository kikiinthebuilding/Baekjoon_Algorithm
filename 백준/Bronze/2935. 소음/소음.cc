#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string n1, n2; char op;
	cin >> n1 >> op >> n2;
	if (op == '+') {
		if (n1 > n2) {
			n1[n1.size() - n2.size()] = '1';
			cout << n1;
		}
		else if (n2 > n1) {
			n2[n2.size() - n1.size()] = '1';
			cout << n2;
		}
		else {
			n1[0] = '2';
			cout << n1;
		}
	}
	else if (op == '*') {
		int os = n2.size() - 1;
		while(os--) n1.push_back('0');
		cout << n1;
	}
}