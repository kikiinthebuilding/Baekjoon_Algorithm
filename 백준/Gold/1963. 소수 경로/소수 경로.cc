#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

#define MAX 10000
int T, N, M;
bool nonPrime[MAX];
bool flag[MAX];

void findPrime() {
	for (int i = 2; i * i <= MAX; i++) {
		if (nonPrime[i])
			continue;
		for (int j = i * i; j <= MAX; j += i)
			nonPrime[j] = true;
	}
}

void reset() {
	memset(flag, false, sizeof(flag));
}

void calCnt() {
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	flag[N] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == M) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextNum;
			for (int j = 0; j <= 9; j++) {
				string s = to_string(num);
				s[i] = j + '0';
				nextNum = stoi(s);
				if (nonPrime[nextNum] || flag[nextNum]) continue;
				if (nextNum >= 10000 || nextNum < 1000) continue;
				flag[nextNum] = true;
				q.push({ nextNum , cnt + 1 });
			}
		}
	}
	cout << "Impossible" << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	findPrime();
	while (T--) {
		reset();
		cin >> N >> M;
		calCnt();
	}
}
