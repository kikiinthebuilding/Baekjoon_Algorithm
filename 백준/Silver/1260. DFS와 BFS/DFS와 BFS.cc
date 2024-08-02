#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1001
int n, m, v;
bool graph[MAX][MAX];
bool flag[MAX];
queue<int> q;

void reset() {
	for (int i = 1; i <= n; i++)
		flag[i] = false;
}

void DFS(int p) {
	flag[p] = true;
	cout << p << " ";

	for (int i = 1; i <= n; i++)
		if (graph[p][i] && !flag[i])
			DFS(i);
}

void BFS(int p) {
	q.push(p);
	flag[p] = true;
	cout << p << " ";

	while (!q.empty()) {
		p = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[p][i] && !flag[i]) {
				q.push(i);
				flag[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int from, to; cin >> from >> to;
		graph[from][to] = graph[to][from] = 1;
	}

	reset(); DFS(v);

	cout << endl;

	reset(); BFS(v);

	return 0;
}