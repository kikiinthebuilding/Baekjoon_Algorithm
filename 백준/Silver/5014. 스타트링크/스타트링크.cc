#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int F, S, G, U, D;
bool flag[1000001];

void bfs() {
	queue<pair<int, int>> tree; // 시작점, 카운트
	tree.push({ S, 0 });
	while (!tree.empty()) {
		int x = tree.front().first;
		int cnt = tree.front().second;
		tree.pop();
		if (x == G) {
			cout << cnt; 
			return;
		}

		if (x + U <= F) {
			if (!flag[x + U]) {
				flag[x + U] = true;
				tree.push({ x + U, cnt + 1 });
			}
		}
		if (x - D > 0) {
			if (!flag[x - D]) {
				flag[x - D] = true;
				tree.push({ x - D, cnt + 1 });
			}
		}
	}
	cout << "use the stairs";
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	flag[S] = true;
	bfs();

	return 0;
}