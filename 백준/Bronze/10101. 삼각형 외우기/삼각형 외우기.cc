#include <iostream>
using namespace std;
int main(void) {
    int n1, n2, n3; cin>>n1>>n2>>n3;
    if(n1+n2+n3!=180)
        cout<<"Error";
    else {
        if(n1==n2 && n2==n3)
            cout<<"Equilateral";
        else if(n1==n2 || n2==n3 || n3==n1)
            cout<<"Isosceles";
        else
            cout<<"Scalene";
    }
    return 0;
}