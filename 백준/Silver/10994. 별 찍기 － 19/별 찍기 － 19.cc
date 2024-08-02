#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin>>N;
    int width = (N-1)*4+1;
    bool arr[width][width];
    memset(arr, false, sizeof(arr));

    int n1 = 0, n2 = width-1;
    for(int i=0; i<N; i++) {
        for(int j=n1; j<=n2; j++)
            arr[n1][j] = arr[n2][j] = arr[j][n1] = arr[j][n2] = true;
        n1 += 2; n2 -= 2;
    }

    for(int i=0; i<width; i++) {
        for(int j=0; j<width; j++) {
            if(arr[i][j]) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}