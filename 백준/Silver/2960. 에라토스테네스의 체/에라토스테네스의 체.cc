#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	bool arr[1001] = { 0, };
	int N, K; cin >> N >> K;
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (arr[i]) continue;
		for (int j = i; j <= N; j += i) {
			if (arr[j]) continue;
			arr[j] = true;
			cnt++;
			if (cnt == K) {
				cout << j;
				return 0;
			}
		}
	}
}