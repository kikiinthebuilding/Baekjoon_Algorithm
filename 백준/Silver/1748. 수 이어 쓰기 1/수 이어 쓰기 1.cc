#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	int cnt = 0, sum = 0, temp = N;
	while (temp) {
		cnt++;
		temp = temp / 10;
	}

	if (cnt == 1)
		sum = N % 10;
	else {
		int juil = 1;
		for (int i = 1; i <= cnt - 1; i++) {
			sum += i * 9 * juil;
			juil *= 10;
		}
		sum += (N - juil + 1) * cnt;
	}

	cout << sum;
	return 0;
}