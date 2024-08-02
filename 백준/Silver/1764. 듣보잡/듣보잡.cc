#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	vector<string> names, answ;
	string temp;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		names.push_back(temp);
	}
	sort(names.begin(), names.end());

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (binary_search(names.begin(), names.end(), temp))
			answ.push_back(temp);
	}
	sort(answ.begin(), answ.end());

	cout << answ.size() << "\n";
	for (int i = 0; i < answ.size(); i++)
		cout << answ[i] << "\n";
}