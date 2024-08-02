#include <iostream>
#include <algorithm>
using namespace std;

int N; 
int minCost = 9999999;
int arr[10][10];
bool flag[10] = { false, };
int v; // 시작점

void calCost(int k, int cnt, int cost) {
	if (cnt == N) {
		if (arr[k][v] > 0)
			minCost = min(minCost, cost + arr[k][v]);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (arr[k][i] != 0 && !flag[i]) {
			flag[i] = true;
			calCost(i, cnt + 1, cost + arr[k][i]);
			flag[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++) {
		v = i;
		flag[i] = true;
		calCost(i, 1, 0);
		flag[i] = false;
	}
	cout << minCost;

	return 0;
}