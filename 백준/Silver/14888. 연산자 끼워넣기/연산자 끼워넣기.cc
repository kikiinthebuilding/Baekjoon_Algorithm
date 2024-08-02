#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums(11);
vector<int> ops(4);
int maxSum = -1000000001, minSum = 1000000001;

void calMaxMin(int sum, int depth) {
	if (depth == N) {
		maxSum = max(maxSum, sum);
		minSum = min(minSum, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (ops[i] > 0)
		{
			ops[i]--;
			if (i == 0)
				calMaxMin(sum + nums[depth], depth + 1);
			else if (i == 1)
				calMaxMin(sum - nums[depth], depth + 1);
			else if (i == 2)
				calMaxMin(sum * nums[depth], depth + 1);
			else
				calMaxMin(sum / nums[depth], depth + 1);
			ops[i]++; 
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cin >> ops[i];
	calMaxMin(nums[0], 1);
	cout << maxSum << '\n' << minSum;
	return 0;
}