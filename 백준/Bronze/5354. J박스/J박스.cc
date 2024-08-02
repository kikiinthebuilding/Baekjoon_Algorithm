#include <iostream>
#include <memory.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        char arr[N][N]; memset(arr, 'J', sizeof(arr));
        for(int i=0; i<N; i++)
            arr[0][i] = arr[N-1][i] = arr[i][0] = arr[i][N-1] = '#';

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                cout<<arr[i][j];
            cout<<endl;
        }
        if(T>0) cout<<endl;
    }


    return 0;
}