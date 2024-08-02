#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin>>N;
    int res, cnt2=0, cnt5=0;
    for(int i=1; i<=N; i++) {
        int temp = i;
        while(temp%2==0) {
            cnt2++;
            temp/=2;
        }
        temp = i;
        while(temp%5==0) {
            cnt5++;
            temp/=5;
        }
    }
    cout<<(res = cnt2<cnt5?cnt2:cnt5)<<endl;

    return 0;
}