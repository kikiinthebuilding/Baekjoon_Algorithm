#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main(void) {
    int n1, n2;
    cin>>n1>>n2;
    cout<<gcd(n1,n2)<<endl<<lcm(n1,n2);
    return 0;
}

int gcd(int a, int b) {
    while (b != 0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int lcm(int a, int b) {
    int rslt;
    int gcdNum = gcd(a, b);
    if (gcdNum==0)
        return 0;
    else {
        rslt = a*b/gcdNum;
        return rslt;
    }
}
