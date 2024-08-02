#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string temp; cin >> temp;
	vector<int> v;
	for (int i = 0; i < temp.size(); i++)
		v.push_back(temp[i] - '0');
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
}