#include <iostream>
#include<algorithm>
using namespace std;
void findCpl(int* arr, int len, int diff);

int main(void) {
    int arr[9], sum=0;
    for(int i=0;i<9;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    int diff=sum-100;
    findCpl(arr, 9, diff);
        sort(arr, arr+9);
    for(int i=2;i<9;i++)
        cout<<arr[i]<<endl;

    return 0;
}

void findCpl(int* arr, int len, int diff)
{
    for(int i=0; i<len-1; i++)
        for(int j=i+1; j<len; j++)
            if(arr[i]+arr[j]==diff) {
                arr[i]=arr[j]=-1;
                return;
            }
}