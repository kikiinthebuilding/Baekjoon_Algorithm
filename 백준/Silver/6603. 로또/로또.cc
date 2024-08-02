#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
vector<int> S(13);
vector<int> asw(6);

void dfs(int v, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)
			cout << asw[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = v; i < k; i++) {
		asw[cnt] = S[i];
		dfs(i + 1, cnt + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> k && k) {
		for (int i = 0; i < k; i++)
			cin >> S[i];
		dfs(0, 0);
		cout << "\n";
	}

	return 0;
}