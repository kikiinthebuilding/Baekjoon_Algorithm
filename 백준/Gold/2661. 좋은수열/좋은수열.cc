#include <iostream>
#include <string>
using namespace std;

int N;
bool flag = 0;

bool isValid(string s) {
	int len = s.size();
	int end = len - 1;
	for (int i = 1; i <= len / 2; i++) {
		string s1 = s.substr(end - i, i);
		string s2 = s.substr(end, i);
		if (!s1.compare(s2)) return false;
		end--;
	}
	return true;
}

void dfs(int i, string s) {
	if (flag || !isValid(s)) return;
	if (i == N) {
		cout << s << '\n';
		flag = true;
		return;
	}
	dfs(i + 1, s + '1');
	dfs(i + 1, s + '2');
	dfs(i + 1, s + '3');
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dfs(0, "");
}