#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int n[3]; cin>>n[0]>>n[1]>>n[2];
    sort(n, n+3);
    cout<<n[0]<<" "<<n[1]<<" "<<n[2];
    return 0;
}