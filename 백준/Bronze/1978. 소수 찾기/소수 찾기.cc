#include <iostream>
using namespace std;

int findOne(int n);
int sumArr(int* arr, int len);

int main(void) {
    int them;
    cin>>them;
    int arr[them], finArr[them];
    for(int i=0;i<them;i++)
        cin>>arr[i];
    for(int i=0;i<them;i++)
        finArr[i]=findOne(arr[i]);
    cout<<sumArr(finArr, them);
    return 0;
}

int findOne(int n) {
    int cnt=0;
    for(int i=2;i<=n;i++)
        if(n%i==0 && n!=0)
            cnt++;
    if(cnt==1) return 1;
    else return 0;
}

int sumArr(int* arr, int len) {
    int temp=0;
    for(int i=0;i<len;i++)
        temp+=arr[i];
    return temp;
}
