#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NANO 10000000
int X, N;
vector<int> Ls;

void findPiece() {
	int hole = X * NANO;
	bool flag = false;
	int i = 0, j = Ls.size() - 1;
	while (i < j) {
		if (Ls[i] + Ls[j] == hole) {
			flag = true;
			break;
		}
		else if (Ls[i] + Ls[j] < hole)
			i++;
		else
			j--;
	}
	if (!flag)
		cout << "danger" << "\n";
	else
		cout << "yes " << Ls[i] << " " << Ls[j] << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (cin >> X >> N) {
		Ls.clear();
		for (int i = 0; i < N; i++) {
			int temp; cin >> temp;
			Ls.push_back(temp);
		}
		sort(Ls.begin(), Ls.end());
		findPiece();
	}
}