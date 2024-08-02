#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	int sum, part;
	for (int i = 1; i < N; i++) {
		sum = part = i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
}