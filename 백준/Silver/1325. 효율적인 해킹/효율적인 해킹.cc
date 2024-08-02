#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 10001
vector<int> network[MAX];
bool flag[MAX];
int N, cnt;
vector<pair<int, int>> vec;
queue<int> qu;

void reset() {
	memset(flag, false, sizeof(flag));
}

void bfs(int v) {
	qu.push(v);
	while (!qu.empty()) {
		int temp = qu.front();
		flag[temp] = true;
		qu.pop();
		for (int i = 0; i < network[temp].size(); i++) {
			int vi = network[temp][i];
			if (!flag[vi]) {
				qu.push(vi);
				flag[vi] = true;
				cnt++;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int M, maxCnt = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2; cin >> t1 >> t2;
		network[t2].push_back(t1);
	}

	for (int i = 1; i <= N; i++) {
		reset(); cnt = 1;
		bfs(i);
		vec.push_back({ i, cnt });
	}

	for (int i = 0; i < vec.size(); i++)
		if (vec[i].second > maxCnt)
			maxCnt = vec[i].second;

	for (int i = 0; i < vec.size(); i++)
		if (vec[i].second == maxCnt)
			printf("%d ", vec[i].first);

	return 0;
}