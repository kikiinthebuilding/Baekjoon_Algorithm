#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
bool bar[MAX][MAX];
bool flag[MAX][MAX];
vector<int> cnts;
int cnt = 1;
int M, N; // M : 세로, N : 가로

void dfs(int y, int x) {
	int ySurr[4] = { -1, 1, 0, 0 };
	int xSurr[4] = { 0, 0, -1, 1 };
	for (int i = 0; i < 4; i++) {
		int tx = x + xSurr[i];
		int ty = y + ySurr[i];
		if (ty < 0 || ty >= M || tx < 0 || tx >= N)
			continue;
		else if (!bar[ty][tx] && !flag[ty][tx]) {
			cnt++;
			flag[ty][tx] = true;
			dfs(ty, tx);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int t1x, t1y, t2x, t2y; cin >> t1x >> t1y >> t2x >> t2y;
		for (int j = t1y; j < t2y; j++) {
			for (int k = t1x; k < t2x; k++) {
				bar[j][k] = true;
			}
		}
	}

	int cntArea = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cnt = 1;
			if (!bar[i][j] && !flag[i][j]) {
				cntArea++;
				flag[i][j] = true;
				dfs(i, j);
				cnts.push_back(cnt);
			}
		}
	}

	cout << cntArea << endl;
	sort(cnts.begin(), cnts.end());
	for (int i = 0; i < cnts.size(); i++) {
		printf("%d ", cnts[i]);
	}
}