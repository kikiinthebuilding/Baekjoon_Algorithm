#include <iostream>
using namespace std;

int main() {
    int N; cin>>N;
    unsigned long long sum = 0;
    for(int i=1; i<N; i++) {
        sum+=(unsigned long long)N*i+i;
    }
    cout<<sum<<endl;
}