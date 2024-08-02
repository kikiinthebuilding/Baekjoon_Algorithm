#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<string> phones;

void consist() {
	for (int i = 0; i < N - 1; i++) {
		int curLen = phones[i].size();
		int nextLen = phones[i + 1].size();
		if (curLen < nextLen && !phones[i + 1].rfind(phones[i], 0)) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int testcase; cin >> testcase;
	while (testcase--) {
		phones.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			string temp; cin >> temp;
			phones.push_back(temp);
		}
		sort(phones.begin(), phones.end());
		consist();
	}
}