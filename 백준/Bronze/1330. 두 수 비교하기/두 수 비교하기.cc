#include <iostream>
using namespace std;
int main(void) {
    int n1, n2; cin>>n1>>n2;
    if(n1<n2) cout<<"<";
    else if(n1>n2) cout<<">";
    else cout<<"==";
    return 0;
}