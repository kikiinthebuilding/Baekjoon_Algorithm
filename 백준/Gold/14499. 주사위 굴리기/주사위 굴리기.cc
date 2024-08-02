#include <iostream>
#include <vector>
using namespace std;

int N, M, X, Y, K;
int map[20][20];
vector<int> dice(7);
void rollDice(int k) {
	switch (k) {
	case 1:
		dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] }; //상 북 동 서 남 하
		break;
	case 2:
		dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
		break;

	case 3:
		dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
		break;

	case 4:
		dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
		break;
	}
}

int dy[5] = { 0, 0, 0, -1, 1 }; //1 동쪽 2 서쪽 3 북쪽 4 남쪽
int dx[5] = { 0, 1, -1, 0, 0 };
void move(int m) {
	int ny = Y + dy[m];
	int nx = X + dx[m];
	if (ny >= N || ny < 0 || nx >= M || nx < 0)
		return;
	X = nx; Y = ny;
	rollDice(m);
	cout << dice[1] << '\n';
	if (!map[Y][X])
		map[Y][X] = dice[6];
	else {
		dice[6] = map[Y][X];
		map[Y][X] = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> Y >> X >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int movin;
	for (int i = 0; i < K; i++) {
		cin >> movin;
		move(movin);
	}
}
