#include <iostream>
#include <vector>
using namespace std;

int N, score, rankable;
vector<int> rnk;

int calRnk() {
	int cnt = 0, my = 1;
	if (N == 0)
		return 1;
	for (int i = 0; i < N; i++) {
		if (score < rnk[i]) my++;
		else if (score>rnk[i]) break;
		cnt++;
	}
	if (cnt == rankable) return -1;
	return my;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> score >> rankable;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		rnk.push_back(temp);
	}

	cout << calRnk();
}