#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 101
vector<string> grid;
bool flag[MAX][MAX];
int N, cnt = 0;

int xArd[4] = { -1, 1, 0, 0 };
int yArd[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nY = y + yArd[i];
		int nX = x + xArd[i];
		if (nY < 0 || nY >= N || nX < 0 || nX >= N)
			continue;
		else if (grid[nY][nX] == grid[y][x] && !flag[nY][nX]) {
			flag[nY][nX] = true;
			dfs(nY, nX);
		}
	}
}

void blindSet() {
	cnt=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			flag[i][j] = false;
			if (grid[i][j] == 'G')
				grid[i][j] = 'R';
		}		
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		grid.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!flag[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	blindSet();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!flag[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
}