#include <iostream>
using namespace std;


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin>>N;
    int target; cin>>target;

    const int dx[] = {0,1,0,-1};
    const int dy[] = {-1,0,1,0};
    int arr[N][N]; arr[N/2][N/2] = 1;
    pair<int, int> cursor = {N/2, N/2};

    int repeat=1, index=0;
    bool sw=0;
    while(1) {
        for(int i=1; i<=repeat; i++) {
            arr[cursor.first+dy[index]][cursor.second+dx[index]]=arr[cursor.first][cursor.second]+1;
            cursor.first += dy[index]; cursor.second += dx[index];
            if(arr[cursor.first][cursor.second]==N*N) { sw=1; break; }
        }
        index++; if(index==4) index=0;
        if(index%2==0) repeat++;
        if(sw) break;
    }

    int target_x, target_y;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<arr[i][j]<<" ";
            if(arr[i][j]==target) {target_y=i; target_x=j;}
        }
        cout<<endl;
    }
    cout<<target_y+1<<" "<<target_x+1<<endl;

    return 0;
}
