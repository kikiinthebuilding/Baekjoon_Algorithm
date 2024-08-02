#include <iostream>
#include <string.h>
using namespace std;

#define MAX 51
bool bchFarm[MAX][MAX];
bool flag[MAX][MAX];
int garo, sero, bchNum;

void findFarm_dfs(int y, int x) {
	int yArd[4] = { -1, 1, 0, 0 };
	int xArd[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++) {
		int tX = x + xArd[i];
		int tY = y + yArd[i];
		if (tY < 0 || tY >= sero || tX < 0 || tX >= garo) 
            continue;
		else if (bchFarm[tY][tX] && !flag[tY][tX]) {
			flag[tY][tX] = true;
			findFarm_dfs(tY, tX);
		}
	}
}

int main(void) {
	int testNum; cin >> testNum;
	while (testNum--) {
		memset(bchFarm, false, sizeof(bchFarm));
		memset(flag, false, sizeof(flag));
		int cnt = 0;

		cin >> garo >> sero >> bchNum;
		for (int i = 0; i < bchNum; i++) {
			int x, y; cin >> x >> y;
			bchFarm[y][x] = true;
		}

		for (int i = 0; i < sero; i++)
			for (int j = 0; j < garo; j++)
				if (bchFarm[i][j] && !flag[i][j]) {
					cnt++;
					flag[i][j] = true;
					findFarm_dfs(i, j);
				}
		printf("%d\n", cnt);
	}
	return 0;
}