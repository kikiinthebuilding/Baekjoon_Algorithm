#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<string> field(12);
bool flag[12][6];
int cnt = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool chain(int y, int x, char c) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	memset(flag, false, sizeof(flag));
	q.push({ y, x });
	v.push_back({ y, x });
	flag[y][x] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12)
				continue;
			if (field[ny][nx] == c && !flag[ny][nx]) {
				q.push({ ny, nx });
				v.push_back({ ny, nx });
				flag[ny][nx] = true;
			}
		}
	}

	if (v.size() >= 4) {
		for (int i = 0; i < v.size(); i++)
			field[v[i].first][v[i].second] = '.';
		return true;
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 12; i++)
		cin >> field[i];
		
	while (1) {
		bool sw = false;
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (field[i][j] != '.') 
					if (chain(i, j, field[i][j]))
						sw = true;

		if (!sw) break;
		else {
			cnt++;
			for (int i = 0; i < 6; i++) {
				int top = 11;
				for (int j = 11; j >= 0; j--) {
					if (field[j][i] == '.') continue;
					if (j != top) {
						field[top][i] = field[j][i];
						field[j][i] = '.';
					}
					top--;
				}
			}
		}
	}
	if (cnt) cout << cnt;
	else cout << 0;
}