#include <iostream>
using namespace std;

int main() {
    long long n1, n2; cin>>n1>>n2;
    if(n1>n2) swap(n1, n2);
    cout<<(n2-n1)<<endl;
}