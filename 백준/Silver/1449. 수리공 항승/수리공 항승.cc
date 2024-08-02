#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000
vector<int> loc;
bool flag[MAX];
int N, L;

int fix() {
	int cnt = 1;
	int start = loc[0];
	for (int i = 1; i < N; i++) {
		if (L <= loc[i] - start) {
			cnt++;
			start = loc[i];
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		loc.push_back(temp);
	}
	sort(loc.begin(), loc.end());
	cout << fix();
}