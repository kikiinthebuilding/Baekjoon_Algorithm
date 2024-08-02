#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 301
int dist[MAX][MAX]; // 거리 저장용
bool flag[MAX][MAX];
queue<pair<int, int>> q;
pair<int, int> startPoint;
pair<int, int> goalPoint;
int sideLen;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void reset() {
	while (!q.empty()) q.pop();
	memset(dist, false, sizeof(dist));
	memset(flag, false, sizeof(flag));
}

void bfs(int x, int y) {
	q.push({ x, y });
	flag[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == goalPoint.first && y == goalPoint.second) {
			printf("%d\n", dist[x][y]);
			break;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= sideLen || ny < 0 || ny >= sideLen)
				continue;
			else if (!flag[nx][ny]) {
				q.push({ nx, ny });
				flag[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int testNum; cin >> testNum;
	while (testNum--) {
		cin >> sideLen;
		cin >> startPoint.first >> startPoint.second;
		cin >> goalPoint.first >> goalPoint.second;
		reset();
		bfs(startPoint.first, startPoint.second);
	}
}