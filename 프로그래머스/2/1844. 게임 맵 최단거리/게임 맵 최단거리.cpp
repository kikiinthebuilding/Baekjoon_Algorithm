#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<vector<int>> maps) {
    int sero = maps.size(), garo = maps[0].size();
    vector<vector<bool>> visited(sero, vector<bool>(garo, false));

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    queue<tuple<int, int, int>> q; // y, x, 거리
    q.emplace(0, 0, 1); visited[0][0] = true;

    while (!q.empty()) {
        auto [y, x, dist] = q.front(); q.pop();

        if (y == sero - 1 && x == garo - 1) return dist;

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= sero || nx < 0 || nx >= garo) continue;

            if (maps[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.emplace(ny, nx, dist + 1);
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps) {
    return bfs(maps);
}
