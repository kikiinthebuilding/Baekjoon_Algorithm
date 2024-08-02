#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int cnt = 0;

	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			int temp; cin >> temp;
			cnt += temp;
		}
		switch (cnt) {
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break; 
		case 2:
				cout << "B\n";
				break; 
		case 3:
				cout << "A\n";
				break; 
		case 4:
				cout << "E\n";
				break;
		}
	}
}