#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

#define MAX 10000
int T, A, B;
bool flag[MAX];

void reset() {
	memset(flag, false, sizeof(flag));
}

void calculator() {
	queue<pair<int, string>> q;
	q.push({ A, "" });
	flag[A] = true;
	while (!q.empty()) {
		int num = q.front().first;
		string path = q.front().second;
		q.pop();

		if (num == B) {
			cout << path << '\n';
			return;
		}
		int nextNum;
		nextNum = (num * 2) % 10000;
		if (!flag[nextNum]) {
			flag[nextNum] = true;
			q.push({ nextNum, path + 'D' });
		}
		nextNum = num - 1 < 0 ? 9999 : num - 1;
		if (!flag[nextNum]) {
			flag[nextNum] = true;
			q.push({ nextNum, path + 'S' });
		}
		nextNum = (num % 1000) * 10 + num / 1000;
		if (!flag[nextNum]) {
			flag[nextNum] = true;
			q.push({ nextNum, path + 'L' });
		}
		nextNum = (num % 10) * 1000 + num / 10;
		if (!flag[nextNum]) {
			flag[nextNum] = true;
			q.push({ nextNum, path + 'R' });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> A >> B;
		reset();
		calculator();
	}
}
