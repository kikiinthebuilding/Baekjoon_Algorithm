#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int A, B, V;
	cin >> A >> B >> V;
	int days = 1;
	days += (V - A) / (A - B);
	if ((V - A) % (A - B) != 0)
		days++;
	if (A >= V) cout << "1";
	else cout << days;
	return 0;
}