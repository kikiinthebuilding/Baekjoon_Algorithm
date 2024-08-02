#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int A, B, C; cin >> A >> B >> C;
	string num = to_string(A * B * C);
	int cnt;
	for (int i = 0; i <= 9; i++) {
		cnt = 0;
		for (int j = 0; j < num.size(); j++) {
			if (num[j]-'0' == i)
				cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}