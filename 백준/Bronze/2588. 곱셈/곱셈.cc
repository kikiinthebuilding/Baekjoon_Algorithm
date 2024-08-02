#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n1, n2; cin>>n1>>n2;

    cout<<n1*(n2%10)<<endl;
    cout<<n1*((n2%100)/10)<<endl;
    cout<<n1*(n2/100)<<endl;
    cout<<n1*n2<<endl;

    return 0;
}