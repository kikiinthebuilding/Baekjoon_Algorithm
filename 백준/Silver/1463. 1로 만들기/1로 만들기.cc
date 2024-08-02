#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int X, cnt = 0;
queue<pair<int, int>> xs; // {x, depth}
bool flag[1000000];
void makeOne() {
	xs.push({ X, 0 });
	while (!xs.empty()) {
		int x = xs.front().first;
		int depth = xs.front().second;
		xs.pop();
		if (x == 1) {
			cout << depth;
			return;
		}

		if (x % 3 == 0) {
			if (!flag[x / 3]) {
				flag[x / 3] = true;
				xs.push({ x / 3, depth + 1 });
			}
		}
		if (x % 2 == 0) {
			if (!flag[x / 2]) {
				flag[x / 2] = true;
				xs.push({ x / 2, depth + 1 });
			}
		}
		
		if (!flag[x - 1]) {
			flag[x - 1] = true;
			xs.push({ x - 1, depth + 1 });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X;
	makeOne();
}