#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int map[8][8], temp[8][8];
bool flag[64];
vector<pair<int, int>> bnk;
int cnt = 0, result = 0;

void reset() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = map[i][j];
	cnt = 0;
}

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void cntSafe() {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (temp[i][j] == 2)
				q.push({ i, j });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (!temp[ny][nx]) {
				temp[ny][nx] = 2;
				q.push({ ny, nx });
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!temp[i][j])
				cnt++;
	result = max(result, cnt);
}

void makeWall(int lv, int idx) {
	if (lv == 3) {
		reset();
		for (int i = 0; i < bnk.size(); i++) {
			if (cnt == 3) break;
			if (flag[i]) {
				int y = bnk[i].first;
				int x = bnk[i].second;
				temp[y][x] = 1;
				cnt++;
			}
		}
		cntSafe();
		return;
	}
	for (int i = idx; i < bnk.size(); i++) {
		if (flag[i]) continue;
		flag[i] = true;
		makeWall(lv + 1, i);
		flag[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (!map[i][j])
				bnk.push_back({ i, j });
		}
	
	makeWall(0, 0);
	cout << result;
}