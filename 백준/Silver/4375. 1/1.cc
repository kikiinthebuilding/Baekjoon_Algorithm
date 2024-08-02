#include <iostream>
using namespace std;
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N, num; int cnt;
    while(cin>>N) {
        num = 1; cnt = 1;
        while(1) {
            num %= N;
            if(num==0) break;
            num = (num*10)%N + 1;
            cnt++;
        }
        cout<<cnt<<'\n';
    }

    return 0;
}