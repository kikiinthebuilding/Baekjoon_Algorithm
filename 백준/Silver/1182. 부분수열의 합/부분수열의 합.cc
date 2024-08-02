#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> nums(20);
int asw = 0;

void findS(int cnt, int sum) {
	if (cnt == N) {
		if(sum == S)
			asw++;
		return;
	}
	
	for (int i = 0; i <= 1; i++) {
		if (i)
			findS(cnt + 1, sum + nums[cnt]);
		else
			findS(cnt + 1, sum);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	findS(0, 0);
	if (S == 0) asw--;
	cout << asw;

	return 0;
}