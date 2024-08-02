#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int num;
    int max=-1000000, min=1000000;
    while(n--) {
        cin>>num;
        if(num>max) max=num;
        if(num<min) min=num;
    }
    printf("%d %d", min, max);
    return 0;
}
