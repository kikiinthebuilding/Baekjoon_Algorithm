#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[31]; int num;
    for(int i=0;i<28;i++) {
        cin>>num;
        arr[num]=num;
    }

    for(int i=1;i<=30;i++)
        if(arr[i]!=i)
            printf("%d\n", i);

    return 0;
}