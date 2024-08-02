#include <iostream>
#include <algorithm>
using namespace std;

struct country {
	int country_number;
	int gold;
	int sliver;
	int bronze;

};

bool cmp(country a, country b) {
	if (a.gold > b.gold) return true;
	else if (a.gold == b.gold) {
		if (a.sliver > b.sliver) return true;
		if (a.sliver == b.sliver) {
			if (a.bronze > b.bronze) return true;
		}
	}

	return false;
}

country arr[1001];
int n, k;
int n1, n2, n3, n4;
int result = 0,val=0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2 >> n3 >> n4;
		arr[i].country_number = n1;
		arr[i].gold = n2;
		arr[i].sliver = n3;
		arr[i].bronze = n4;
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		if (arr[i].country_number == k) {
			result = i;
			break;
		}
	}
	for (int i = result - 1;; i--) {
		if (arr[i].gold != arr[result].gold || arr[i].sliver != arr[result].sliver || arr[i].bronze != arr[result].bronze) {
			break;
		}
		val++;
	}
	cout << result - val + 1 << endl;
}