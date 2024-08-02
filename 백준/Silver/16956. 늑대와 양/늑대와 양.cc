#include <iostream>
#include <queue>
using namespace std;

#define MAX 500
char map[MAX][MAX];
queue<pair<int, int>> wolfLoc;
int R, C;

bool makeFence() {
	int xArnd[4] = { -1, 1, 0, 0 };
	int yArnd[4] = { 0, 0, -1, 1 };
				
	while (!wolfLoc.empty()) {
		for (int i = 0; i < 4; i++) {
			int tY = wolfLoc.front().first + yArnd[i];
			int tX = wolfLoc.front().second + xArnd[i];

			if (tY >= 0 && tY < R && tX >= 0 && tX < C) {
				if (map[tY][tX] == 'S')
					return false;
				else if (map[tY][tX] == '.')
					map[tY][tX] = 'D';
			}
		}
		wolfLoc.pop();
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'W')
				wolfLoc.push({ i,j });
		}
			
	bool poss = makeFence();
	cout << poss << endl;
	if (poss) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cout << map[i][j];
			cout << endl;
		}
	}
	
	return 0;
}
