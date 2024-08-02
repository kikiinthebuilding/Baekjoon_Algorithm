#include <iostream>
#include <queue>
using namespace std;

#define MAX 201
int buck[3]; // A, B, C
bool flag[MAX][MAX];
bool result[MAX];

void water() {
	queue<pair<int, int>> q;
	int from[6] = { 0, 0, 1, 1, 2, 2 };
	int to[6] = { 1, 2, 0, 2, 0, 1 };
	// A->B   A->C   B->A   B->C   C->A   C->B
	result[buck[2]] = true;
	q.push({ 0, 0 }); 
	flag[0][0] = true;
	
	while (!q.empty()) {
		int n1 = q.front().first; // A
		int n2 = q.front().second; // B
		int n3 = buck[2] - n1 - n2;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int cur[3] = { n1, n2, n3 };
			cur[to[i]] += cur[from[i]];
			cur[from[i]] = 0;
			if (cur[to[i]] > buck[to[i]]) {
				cur[from[i]] = cur[to[i]] - buck[to[i]];
				cur[to[i]] = buck[to[i]];
			}
			if (!flag[cur[0]][cur[1]]) {
				flag[cur[0]][cur[1]] = true;
				q.push({ cur[0], cur[1] });
				if (!cur[0]) result[cur[2]] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 3; i++) cin >> buck[i];

	water();
	for (int i = 0; i <= buck[2]; i++)
		if (result[i]) 
			cout << i << ' ';
}
