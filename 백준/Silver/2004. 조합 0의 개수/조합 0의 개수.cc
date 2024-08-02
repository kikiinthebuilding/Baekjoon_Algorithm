#include <iostream>
using namespace std;

pair<long long,long long> count_2_5(long long X) {
    long long cnt2 = 0, cnt5 = 0;
    
    for(long long i=2; i<=X; i*=2)
        cnt2 += X/i;
    for(long long i=5; i<=X; i*=5)
        cnt5 += X/i;
    
    return {cnt2, cnt5};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; cin>>N>>M;

    pair<long long, long long> cntN = count_2_5(N);
    pair<long long, long long> cntN_M = count_2_5(N-M);
    pair<long long, long long> cntM = count_2_5(M);

    long long cnt2 = (cntN.first-(cntN_M.first+cntM.first));
    long long cnt5 = (cntN.second-(cntN_M.second+cntM.second));
    cout<<(cnt2<cnt5?cnt2:cnt5)<<'\n';

    return 0;
}