#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cnt = 0;
	int sugar; cin >> sugar;
	while (sugar >= 0) {
		if (sugar % 5 == 0) {
			cnt += sugar / 5;
			cout << cnt;
			return 0;
		}
		sugar -= 3;
		cnt++;
	}
	cout << -1;
}