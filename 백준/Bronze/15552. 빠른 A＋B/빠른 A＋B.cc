#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int t1, t2;
	while (N--) {
		cin >> t1 >> t2;
		cout << t1 + t2 << "\n";
	}
	return 0;
}