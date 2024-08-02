#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 51
queue<pair<int, int>> q;
bool map[MAX][MAX];	//지도
bool flag[MAX][MAX];	//방문 표시
int path[MAX][MAX];	//경로
int row, col;
int maxLen = 0;

void reset() {
	memset(flag, 0, sizeof(flag));
	memset(path, 0, sizeof(path));
	maxLen = 0;
}

int findDist(int y, int x) {
	path[y][x] = 1;
	flag[y][x] = true;
	q.push({ y, x });
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		int ysur[4] = { 0, 0, -1, 1 };
		int xsur[4] = { -1, 1, 0, 0 };
		for (int i = 0; i < 4; i++) {
			int ny = y + ysur[i];
			int nx = x + xsur[i];

			if (ny < 0 || ny >= row || nx < 0 || nx >= col)
				continue;
			else if (map[ny][nx] == true && !flag[ny][nx]) {
				flag[ny][nx] = true;
				path[ny][nx] = path[y][x] + 1;
				q.push({ ny, nx });
				maxLen = max(maxLen, path[ny][nx]);
			}
		}
	}
	return maxLen - 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int answ = 0;

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char temp; cin >> temp;
			if (temp == 'L') map[i][j] = true;
			else map[i][j] = false;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 1) {
				int temp = findDist(i, j);
				answ = max(temp, answ);
				reset();
			}
		}
	}
	cout << answ;
}