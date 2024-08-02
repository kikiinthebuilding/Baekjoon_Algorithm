#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tar; cin>>tar;
    int num, cnt=0;
    for(int i=0; i<5; i++) {
        cin>>num;
        if(tar==num)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}