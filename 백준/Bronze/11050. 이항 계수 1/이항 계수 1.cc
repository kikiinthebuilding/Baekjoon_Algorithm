#include <iostream>
using namespace std;

int main(void) {
    int N, K; cin>>N>>K;
    int n1=1, n2=1;

    for(int i=K+1; i<=N; i++)
        n1*=i;

    for(int j=1; j<=N-K; j++)
        n2*=j;

    cout<<n1/n2<<endl;

    return 0;
}