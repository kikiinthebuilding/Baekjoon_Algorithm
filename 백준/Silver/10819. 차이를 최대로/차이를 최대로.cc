#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 9
int N; // 개수
int arr[MAX]; 
bool flag[MAX];
vector<int> v;
int result, cnt = 0;

void brute() {
	if (v.size() == N) {
		int temp = 0;
		for (int i = 0; i < N - 1; i++)
			temp += abs(v[i + 1] - v[i]);
		result = max(result, temp);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!flag[i]) {
			flag[i] = true;
			v.push_back(arr[i]);
			brute();
			v.pop_back();
			flag[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	brute();
	cout << result;
}