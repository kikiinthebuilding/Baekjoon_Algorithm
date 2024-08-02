#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> alp;
vector<char> answ;
int L, C;

bool chk() {
	int vowCnt = 0, conCnt = 0;
	for (int i = 0; i < L; i++) {
		if (answ[i] == 'a' || answ[i] == 'e' || answ[i] == 'i' || answ[i] == 'o' || answ[i] == 'u')
			vowCnt++;
		else
			conCnt++;
	}
	if (vowCnt >= 1 && conCnt >= 2) return true;
	return false;
}

void pwMaker(int d) {
	if (answ.size() == L) {
		if (chk()) {
			for (int i = 0; i < L; i++)
				cout << answ[i];
			cout << "\n";
		}
		return;
	}
	for (int i = d; i < C; i++) {
		answ.push_back(alp[i]);
		pwMaker(i + 1);
		answ.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char temp; cin >> temp;
		alp.push_back(temp);
	}
	sort(alp.begin(), alp.end());
	pwMaker(0);
}