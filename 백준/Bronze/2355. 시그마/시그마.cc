#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long  A, B; cin >> A >> B;
	if (A < B)
		cout << (B * (B + 1) / 2) - (A * (A - 1) / 2) << '\n';
	else
		cout << (A * (A + 1) / 2) - (B * (B - 1) / 2) << '\n';
	return 0;
}