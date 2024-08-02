#include <iostream>
#include <string>
using namespace std;
#define MIL 2000000

bool arr[MIL + 1];

void arrSosoo() {
	fill_n(arr, MIL, true);

	arr[0] = arr[1] = false;
	for (int i = 2; i <= MIL; i++) {
		if (arr[i] == true) {
			for (int j = i * 2; j <= MIL; j += i)
				arr[j] = false;
		}
	}
}

bool daeri1577(int n) {
	string n2 = to_string(n);
	int len = n2.length();
	for (int i = 0; i <= len / 2; i++)
	{
		if (n2[i] != n2[len - 1 - i])
			return false;
	}
	return true;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	arrSosoo();
	int n;
	cin >> n;
	int result = 0;

	while (1) {
		if (arr[n] && daeri1577(n))
		{
			result = n;
			break;
		}
		n++;
	}

	printf("%d", result);

	return 0;
}
