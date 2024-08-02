#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 26
vector<string> map;
bool flag[MAX][MAX];
int n, cnt = 1;
vector<int> cnts;


void dfs(int y, int x) {
	int ySurr[4] = { -1, 1, 0, 0 };
	int xSurr[4] = { 0, 0, -1, 1 };
	for (int i = 0; i < 4; i++) {
		int ty = y + ySurr[i];
		int tx = x + xSurr[i];
		if (ty < 0 || ty >= n || tx < 0 || tx >= n)
			continue;
		else if (map[ty][tx] == '1' && !flag[ty][tx]) {
			cnt++;
			flag[ty][tx] = true;
			dfs(ty, tx);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		map.push_back(temp);
	}

	int cntArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 1;
			if (map[i][j] == '1' && !flag[i][j]) {
				cntArea++;
				flag[i][j] = true;
				dfs(i, j);
				cnts.push_back(cnt);
			}
		}
	}

	cout << cntArea << endl;
	sort(cnts.begin(), cnts.end());
	for (int i = 0; i < cnts.size(); i++)
		printf("%d\n", cnts[i]);
}