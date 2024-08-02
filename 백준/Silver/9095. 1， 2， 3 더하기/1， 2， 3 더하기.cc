#include <iostream>
#include <vector>
using namespace std;

vector<int> v(12);
void tribonacci() {
	v[0] = v[1] = 1; v[2] = 2;
	for (int i = 3; i <= 11; i++) {
		v[i] = v[i - 1] + v[i - 2] + v[i - 3];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	tribonacci();
	while (T--) {
		int n; cin >> n;
		cout << v[n] << "\n";
	}
}