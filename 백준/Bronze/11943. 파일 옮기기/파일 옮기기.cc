#include <iostream>
using namespace std;
int main(void) {
    int arr[2][2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cin>>arr[i][j];

    int sum = ((arr[1][0]+arr[0][1]) <= (arr[0][0] + arr[1][1])) ? (arr[1][0]+arr[0][1]) : (arr[0][0] + arr[1][1]);
    cout<<sum;
    return 0;
}