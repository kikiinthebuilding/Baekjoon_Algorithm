#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> Pi, addPi;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		Pi.push_back(temp);
	}
	sort(Pi.begin(), Pi.end());

	addPi.push_back(Pi.front());
	for (int i = 1; i < N; i++) {
		int temp; temp = Pi[i] + addPi.back();
		addPi.push_back(temp);
	}

	int sum = accumulate(addPi.begin(), addPi.end(), 0);
	cout << sum;
}