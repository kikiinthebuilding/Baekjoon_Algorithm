#include <iostream>
using namespace std;

#define MAX 101
bool coms[MAX][MAX];
bool flag[MAX];
int comN, netN;
int cnt = 0;

void init() {
	for (int i = 1; i <= comN; i++)
		flag[i] = false;
}

void DFS(int n) {
	flag[n] = true;
	for (int i = 1; i <= comN; i++) {
		if (coms[n][i] && !flag[i]) {
			DFS(i);
			cnt++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> comN >> netN;
	for (int i = 0; i < netN; i++) {
		int t1, t2; cin >> t1 >> t2;
		coms[t1][t2] = coms[t2][t1] = true;
	}

	init();
	DFS(1);
	printf("%d", cnt);

	return 0;
}