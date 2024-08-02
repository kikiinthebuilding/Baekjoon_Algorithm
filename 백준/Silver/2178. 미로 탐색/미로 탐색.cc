#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAX 101
bool map[MAX][MAX];
bool flag[MAX][MAX];
int dist[MAX][MAX]; // 이동 거리 기록 용
queue<pair<int, int>> q;
int N, M;

void bfs(int x, int y) {
	flag[x][y] = true;
	q.push({ x, y });
	dist[x][y]++;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ySurr[4] = { -1, 1, 0, 0 };
			int xSurr[4] = { 0, 0, -1, 1 };
			int tx = x + xSurr[i];
			int ty = y + ySurr[i];

			if (tx < 0 || tx >= N || ty < 0 || ty >= M)
				continue;
			else if (!flag[tx][ty] && map[tx][ty]) {
				flag[tx][ty] = true;
				q.push({ tx, ty });
				dist[tx][ty] = dist[x][y] + 1;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string row; cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j] - '0';
			dist[i][j] = 0;
		}
	}
	bfs(0, 0);
	cout << dist[N - 1][M - 1];
}