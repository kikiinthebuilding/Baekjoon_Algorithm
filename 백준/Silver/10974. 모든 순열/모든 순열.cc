#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	do {
		for (int i = 0; i < N; i++)
			cout << arr[i] << ' ';
		cout << "\n";
	} while (next_permutation(arr.begin(), arr.end()));
	return 0;
}