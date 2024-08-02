#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> ch;
int cur = 0;

void moveCh(int ord) {
	string temp;
	switch (ord) {
	case 1:
		cur++;
		printf("1");
		break;
	case 2:
		cur--;
		printf("2");
		break;
	case 3:
		temp = ch[cur];
		ch[cur] = ch[cur + 1];
		ch[cur + 1] = temp;
		cur++;
		printf("3");
		break;
	case 4:
		temp = ch[cur];
		ch[cur] = ch[cur - 1];
		ch[cur - 1] = temp;
		cur--;
		printf("4");
		break;
	}
}

void ctrlCh() {
	while (ch[cur].compare("KBS1") != 0) {
		moveCh(1);
	}
	while (cur != 0) {
		moveCh(4);
	}
	while (ch[cur].compare("KBS2") != 0) {
		moveCh(1);
	}
	while (cur != 1) {
		moveCh(4);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		ch.push_back(temp);
	}
	ctrlCh();
	return 0;
}
