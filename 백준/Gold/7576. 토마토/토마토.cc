#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1001
int farm[MAX][MAX];
int N, M; // N : 세로, M : 가로
queue<pair<int, int>> q;

int xArd[4] = { -1, 1, 0, 0 };
int yArd[4] = { 0, 0, -1, 1 };

void BFS() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nY = y + yArd[i];
			int nX = x + xArd[i];
			if (nY < 0 || nY >= N || nX < 0 || nX >= M)
				continue;
			else if (farm[nY][nX] == 0) {
				farm[nY][nX] = farm[y][x] + 1;
				q.push({ nY, nX });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			int temp; cin >> temp;
			farm[i][j] = temp;
			if (temp == 1)
				q.push({ i, j });
		}
	
	BFS();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (farm[i][j] == 0) {
				cout << "-1";
				return 0;
			}
			cnt = max(cnt, farm[i][j]);
		}
	cout << cnt - 1;
	return 0;
}