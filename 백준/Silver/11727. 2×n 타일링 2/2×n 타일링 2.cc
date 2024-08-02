#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> sq(N + 1);
	sq[0] = sq[1] = 1;
	for (int i = 2; i <= N; i++) {
		sq[i] = (sq[i - 1] + 2 * sq[i - 2]) % 10007;
	}
	cout << sq[N] << endl;
}