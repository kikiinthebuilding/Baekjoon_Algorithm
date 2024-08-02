/* 참고 : https://4z7l.github.io/2021/04/29/algorithms-boj-21608.html */
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct info {
    int x, y;
    int blankCnt = 0;
    int friendCnt = 0;

    bool operator <(const info& i) const {
        if (friendCnt == i.friendCnt) {
            if (blankCnt == i.blankCnt) {
                if (x == i.x)
                    return y > i.y;
                else
                    return x > i.x;
            }
            else return blankCnt < i.blankCnt;
        }
        else return friendCnt < i.friendCnt;
    }
};

struct student {
    int id;
    int preferredStudent[4];
    int x, y;
};

const int liked[] = { 0, 1, 10, 100, 1000 };
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    /* 값 입력 */
    int N; cin >> N;

    int map[N][N];
    memset(map, 0, sizeof(map));

    vector<student> students(N * N);
    for (int i = 0; i < N * N; i++) {
        cin >> students[i].id;
        for (int & j : students[i].preferredStudent) {
            cin >> j;
        }
    }

    for (int s = 0; s < N * N; s++) {
        priority_queue<info> pQ;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!map[i][j]) {
                    int blankCnt = 0, friendCnt = 0;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (!map[nx][ny]) blankCnt++;
                        else {
                            for (int k : students[s].preferredStudent) {
                                if (map[nx][ny] == k) {
                                    friendCnt++;
                                    break;
                                }
                            }
                        }
                    }
                    pQ.push({ i, j, blankCnt, friendCnt });
                }
            }
        }

        if (!pQ.empty()) {
            int x = pQ.top().x;
            int y = pQ.top().y;

            map[x][y] = students[s].id;
            students[s].x = x;
            students[s].y = y;
        }
    }

    int sum = 0;
    for (int s = 0; s < N * N; s++) {
        int x = students[s].x;
        int y = students[s].y;

        int friends = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int k : students[s].preferredStudent) {
                if (map[nx][ny] == k) {
                    friends++;
                    break;
                }
            }
        }
        sum += liked[friends];
    }
    cout << sum;

    return 0;
}
