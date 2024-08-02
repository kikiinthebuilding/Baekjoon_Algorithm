#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n1, n2; int max=0, sum=0;
    for(int i=0;i<4;i++)
    {
        cin>>n1>>n2;
        sum=sum-n1+n2;
        if(sum>max) max=sum;
    }
    printf("%d", max);
    return 0;
}