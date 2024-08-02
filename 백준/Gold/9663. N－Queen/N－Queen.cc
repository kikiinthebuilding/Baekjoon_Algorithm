#include <iostream>
using namespace std;

int N, cnt = 0;
int field[15];

bool chk(int lv) {
	for (int i = 0; i < lv; i++)
		if (field[i] == field[lv] || abs(field[lv] - field[i]) == lv - i)
			return false;
	return true;
}

void noc(int x) {
	if (x == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		field[x] = i;
		if (chk(x))
			noc(x + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	noc(0);
	cout << cnt;
}