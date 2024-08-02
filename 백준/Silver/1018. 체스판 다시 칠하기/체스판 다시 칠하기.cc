#include <iostream>
#include <vector>
using namespace std;

#define MAX 50
int N, M;
bool brd[MAX][MAX];
bool temp[MAX][MAX];

int paint(int n, int m) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			temp[i][j] = brd[i + n][j + m];

	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			if (j == 0 && i<7) {
				if (temp[i][j] == temp[i + 1][j]) {
					temp[i + 1][j] = !temp[i + 1][j];
					cnt++;
				}
			}
			if (temp[i][j] == temp[i][j + 1]) {
				temp[i][j + 1] = !temp[i][j + 1];
				cnt++;
			}
		}
	}
	if (cnt <= 32) return cnt;
	else return 64 - cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	char temp; bool bw;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			if (temp == 'B') bw = false;
			else bw = true;
			brd[i][j] = bw;
		}
	}

	int minCnt = 1000;
	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
			minCnt = min(minCnt, paint(i, j));

	cout << minCnt;
}