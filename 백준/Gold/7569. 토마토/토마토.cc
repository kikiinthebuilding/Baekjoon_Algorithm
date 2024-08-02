#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101
int farm[MAX][MAX][MAX];
int N, M, H; // N : 세로, M : 가로
struct tmt {
	int tz;
	int ty;
	int tx;
};
queue<tmt> q;

int dz[6] = { 0, 0, 0 ,0, -1, 1 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { -1, 1, 0, 0, 0, 0 };

void BFS() {
	while (!q.empty()) {
		int z = q.front().tz;
		int y = q.front().ty;
		int x = q.front().tx;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			else if (farm[nz][ny][nx] == 0) {
				farm[nz][ny][nx] = farm[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> farm[i][j][k];
				if (farm[i][j][k] == 1) q.push({ i, j, k });
			}

	BFS();
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				if (farm[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
				cnt = max(cnt, farm[i][j][k]);
			}
	cout << cnt - 1;
	return 0;
}