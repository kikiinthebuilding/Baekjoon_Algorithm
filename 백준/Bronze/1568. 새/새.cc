#include <iostream>
using namespace std;

int main() {
    int N, cnt=0, K=1; cin>>N;
    while(N) {
        if(N<K) K=1;
        N-=K; K++;
        cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}