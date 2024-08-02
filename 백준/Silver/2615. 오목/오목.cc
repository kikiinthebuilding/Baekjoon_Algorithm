#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int badukpan[19][19];
bool checked[19][19][4][3]; // y, x, dir, color
const int dy[4] = {0, 1, 1, -1};
const int dx[4] = {1, 0, 1, 1};
int dfs(int y, int x, int dir, int color, int cnt) {
    checked[y][x][dir][color] = true;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny<0 || nx<0 || ny>=19 || nx>=19 || badukpan[ny][nx]!=color) {
        if(cnt==5) return color;
        else return 0;
    }
    return dfs(ny, nx, dir, color, cnt+1);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);;

    for(int i=0; i<19; i++)
        for(int j=0; j<19; j++)
            cin>>badukpan[i][j];

    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            if(badukpan[j][i] != 0) {
                for(int k=0; k<4; k++) {
                    if(checked[j][i][k][badukpan[j][i]]) continue;
                    if(dfs(j, i, k, badukpan[j][i], 1) != 0) {
                        cout<<badukpan[j][i]<<'\n'<<j+1<<' '<<i+1;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<0;
    return 0;
}