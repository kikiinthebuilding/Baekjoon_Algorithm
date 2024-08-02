#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
int N, K;
int schedule[MAX];
int pages[MAX] = { 0, };
int cnt = 0, in = 0;

void multi2(int x) {
	bool flag = false;
	if (find(begin(pages), end(pages), x) != end(pages))
		return;

	for (int j = 0; j < N; j++) {
		if (pages[j] == 0) {
			pages[j] = x;
			flag = true;
			break;
		}
	}
	if (flag) return;

	int lastOrder = 0, index = 0;
	for (int j = 0; j < N; j++) {
		int temp = 0;
		for (int t = in + 1; t < K; t++) {
			if (pages[j] == schedule[t])
				break;
			temp++;
		}
		if (temp > lastOrder) {
			lastOrder = temp;
			index = j;
		}
	}
	pages[index] = x;
	cnt++;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	for (int i = 0; i < K; i++)
		cin >> schedule[i];
	for (int i = 0; i < K; i++) {
		multi2(schedule[i]);
		in++;
	}
	cout << cnt;
}