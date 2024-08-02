#include <iostream>
using namespace std;

int N;
char map[10][10], user[10][10];

char around(int y, int x) {
    const int dy[8] = {-1, -1, -1, 0, 0, 1 ,1, 1};
    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int cnt=0;
    for(int i=0; i<8; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if(nx<0 || ny<0 || nx>=N || ny>=N)
            continue;
        if(map[ny][nx]=='*')
            cnt++;
    }
    return cnt+'0';
}

void makeOutput() {
    bool sw=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(user[i][j]=='x') {
                if(map[i][j]=='*') {
                    sw = 1;
                    user[i][j] = '*';
                }
                else
                    user[i][j] = around(i, j);
            }
        }
    }

    if(sw)
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(user[i][j]=='.' && map[i][j]=='*')
                    user[i][j]='*';
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>user[i][j];

    //cout<<endl;
    makeOutput();
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<user[i][j];
        }
        cout<<endl;
    }
    return 0;
}