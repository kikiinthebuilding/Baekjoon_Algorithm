#include <iostream>
#include <queue>
using namespace std;

void findNum(int arr[5][5], int num) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(arr[i][j] == num) {
                arr[i][j] = -1;
                return;
            }
        }
    }
}

int findBingo(int arr[5][5]) {
    int lineCnt=0;
    for(int i=0; i<5; i++) {
        bool sw=0;
        for(int j=0; j<5; j++) {
            if(arr[i][j]!=-1) {
                sw=1; break;
            }
        }
        if(!sw) lineCnt++;
    }

    for(int i=0; i<5; i++) {
        bool sw=0;
        for(int j=0; j<5; j++) {
            if(arr[j][i]!=-1) {
                sw=1; break;
            }
        }
        if(!sw) lineCnt++;
    }

    if(arr[0][0]==-1 && arr[1][1]==-1 && arr[2][2]==-1 && arr[3][3]==-1 && arr[4][4]==-1)
        lineCnt++;
    if(arr[0][4]==-1 && arr[1][3]==-1 && arr[2][2]==-1 && arr[3][1]==-1 && arr[4][0]==-1)
        lineCnt++;

    return lineCnt;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int chulsoo[5][5]; queue<int> mc;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>chulsoo[i][j];

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++) {
            int temp; cin>>temp;
            mc.push(temp);
        }

    int lineCnt=0;
    while (lineCnt<3) {
        int call = mc.front(); mc.pop();
        findNum(chulsoo, call);
        if(mc.size()<=13) {
            lineCnt = findBingo(chulsoo);
        }
    }

    cout<<25-mc.size()<<endl;

    return 0;
}