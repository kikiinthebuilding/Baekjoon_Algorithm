#include <iostream>
using namespace std;
int main(void) {
    int arr[31];
    int num=1;
    for(int i=0; i<31; i++) {
            arr[i]=num;
            num=num*2;
    }

    int n; cin>>n;
    for(int i=0; i<31; i++)
        if(arr[i]==n) {
            cout<<"1";
            return 0;
        }
    cout<<"0";

    return 0;
}