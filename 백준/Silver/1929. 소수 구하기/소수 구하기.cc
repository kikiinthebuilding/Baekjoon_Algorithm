#include <iostream>
using namespace std;

#define MAX 1000001
bool arr[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int M, N; cin >> M >> N;
	arr[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (arr[i])
			continue;
		for (int j = i * i; j <= N; j += i)
			arr[j] = true;
	}

	for (int i = M; i <= N; i++)
		if (!arr[i])
			cout << i << "\n";
}