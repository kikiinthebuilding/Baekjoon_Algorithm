#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 21
int R, C;
char brd[MAX][MAX];
bool alpFlag[26];
int maxPath = 0;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void dfs(int y, int x, int findPath) {
	maxPath = max(findPath, maxPath);

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		int alpha = brd[ny][nx] - 65;
		if (nx < 0 || ny < 0 || nx >= C || ny >= R)
			continue;
		else if (!alpFlag[alpha]) {
			alpFlag[alpha] = true;
			dfs(ny, nx, findPath + 1);
			alpFlag[alpha] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> brd[i][j];

	int firstAlp = brd[0][0] - 65;
	alpFlag[firstAlp] = true;
	dfs(0, 0, 1);
	cout << maxPath;
}