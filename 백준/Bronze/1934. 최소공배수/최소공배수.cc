#include <iostream>
#include <cmath>
using namespace std;
int lcm2(int n1, int n2);

int main(void)
{
    int len;
    cin>>len;
    int arr[len][2]; int resultArr[len];
    for(int i=0;i<len;i++)
        for(int j=0;j<2;j++)
            cin>>arr[i][j];
    for(int i=0;i<len;i++)
    {
        resultArr[i]=lcm2(arr[i][0], arr[i][1]);
        cout<<resultArr[i]<<endl;
    }
    return 0;
}

int lcm2(int n1, int n2) {
    int a=n1, b=n2, rslt;
    while (b != 0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    if (a==0)
        return 0;
    else {
        rslt = n1*n2/a;
        return rslt;
    }
}