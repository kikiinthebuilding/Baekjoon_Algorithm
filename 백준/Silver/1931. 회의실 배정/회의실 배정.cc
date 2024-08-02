#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> conf;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t1, t2; cin >> t1 >> t2;
		conf.push_back({ t2, t1 });
	}
	sort(conf.begin(), conf.end());

	int chTime = conf[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (chTime <= conf[i].second) {
			cnt++;
			chTime = conf[i].first;
		}
	}
	cout << cnt;
}