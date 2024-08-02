#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt; cin>>cnt;
    int sum1=100, sum2=100, n1, n2;
    while(cnt--) {
        cin>>n1>>n2;
        if(n1==n2) continue;
        else if(n1>n2) sum2=sum2-n1;
        else sum1=sum1-n2;
    }
    printf("%d\n%d", sum1, sum2);
    return 0;
}