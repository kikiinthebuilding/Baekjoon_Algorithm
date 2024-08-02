#include <iostream>
#include <string.h>
using namespace std;

#define MAX 50
int W, H;
bool map[MAX][MAX];
bool flag[MAX][MAX];
int cnt = 0;	

void reset() {
	memset(map, false, sizeof(map));
	memset(flag, false, sizeof(flag));
	cnt = 0;
}

int yArd[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int xArd[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
void findIsland(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int ny = y + yArd[i];
		int nx = x + xArd[i];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W)
			continue;
		else if (map[ny][nx] && !flag[ny][nx]) {
			flag[ny][nx] = true;
			findIsland(ny, nx);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> W >> H && W && H) {
		reset();
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (map[i][j] && !flag[i][j]) {
					cnt++;
					flag[i][j] = true;
					findIsland(i, j);
				}
			}
		
		cout << cnt << "\n";
	}
}