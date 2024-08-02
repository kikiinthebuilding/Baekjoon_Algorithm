#include <iostream>
#include <vector>
using namespace std;

vector<int> triSet;
void makeSet() {
	int sum = 0;
	for (int i = 1; sum <= 1000; i++) {
		sum = sum + i;
		triSet.push_back(sum);
	}
}

bool calSum(int n) {
	int len = triSet.size();
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			for (int k = 0; k < len; k++)
				if (n == triSet[i] + triSet[j] + triSet[k])
					return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testCase; cin >> testCase;
	makeSet();
	int k;
	while (testCase--) {
		cin >> k;
		cout << calSum(k) << '\n';
	}
}