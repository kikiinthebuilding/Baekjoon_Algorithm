#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	do {
		getline(cin, s);
		cout << s << "\n";
	} while (!cin.eof());
}