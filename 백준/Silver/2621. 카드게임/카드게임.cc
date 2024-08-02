#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<char, int>> card;

bool compare(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second < b.second;
}

bool contCheck() {
	for (int i = 0; i < 4; i++) {
		if (card[i + 1].second - card[i].second != 1)
			return false;
	}
	return true;
}

int calSameCol() {
	int cnt = 1, sameCol = 1, savePoint = 0;
	for (int i = savePoint; i < 4; i++) {
		cnt = 1;
		for (int j = i+1; j < 5; j++) {
			if (card[i].first == card[j].first) {
				cnt++;
			}
			else {
				savePoint = i + cnt;
				continue;
			}
		}

		if (cnt == 5) return 5;
		else if (cnt > sameCol)
			sameCol = cnt;
	}
	return sameCol;
}

int calSameNum() {
	int cnt = 1, sameNum = 1;
	for (int i = 0; i < 4; i++) {
		cnt = 1;
		for (int j = i + 1; j < 5; j++) {
			if (card[i].second == card[j].second) {
				cnt++;
			}
		}
		if (cnt == 4) return 4;
		else if (cnt > sameNum)
			sameNum = cnt;
	}
	return sameNum;
}


int calScore() {
	sort(card.begin(), card.end());
	int sameCol = calSameCol(), sameNum = calSameNum();
	int score = 0, maxScore = 0;
	if (sameCol == 5) { // Rule 1
		if (contCheck()==true) {
			score = 900 + card[4].second; 
			if (maxScore < score) maxScore = score;
		}
		else { // Rule 4
			int temp = 0;
			sort(card.begin(), card.end(), compare);
			score = 600 + card[4].second;
			if (maxScore < score) maxScore = score;
		}	
	}

	sort(card.begin(), card.end(), compare);

	if (sameNum == 4) { // Rule 2
		int temp;
		if (card[0].second == card[1].second) temp = card[0].second;
		else temp = card[2].second;
		score = 800 + temp;
		if (maxScore < score) maxScore = score;
	}

	else if (sameNum == 3) {
		if (card[0].second == card[2].second && card[3].second == card[4].second) { // Rule 3
			score = 700 + card[0].second * 10 + card[4].second;
			if (maxScore < score) maxScore = score;
		}
		else if (card[2].second == card[4].second && card[0].second == card[1].second) {
			score = 700 + card[4].second * 10 + card[0].second;
			if (maxScore < score) maxScore = score;
		}

		else { // Rule 6
			score = 400 + card[2].second;
			if (maxScore < score) maxScore = score;
		}
	}

	else if (sameNum == 2) {
		if ((card[0].second == card[1].second && card[2].second == card[3].second)
			|| (card[0].second == card[1].second && card[3].second == card[4].second)
			|| (card[1].second == card[2].second && card[3].second == card[4].second)) { //Rule 7
			score = 300 + card[3].second * 10 + card[1].second;
			if (maxScore < score) maxScore = score;
		}

		else { //Rule 8
			int temp = 0;
			for (int i = 0; i < 4; i++) {
				if (card[i].second == card[i + 1].second) {
					temp = card[i].second;
					break;
				}
			}
			score = 200 + temp;
			if (maxScore < score) maxScore = score;
		}
	}

	else if (contCheck() == true) { // Rule 5
		score = 500 + card[4].second;
		if (maxScore < score) maxScore = score;
	}

	else { // Rule 9
		score = 100 + card[4].second;
		if (maxScore < score) maxScore = score;
	}

	return maxScore;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		char temp; int temp2; cin >> temp >> temp2;
		card.push_back(pair<char, int>(temp, temp2));
	}

	printf("%d", calScore());

	return 0;
}
