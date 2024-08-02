#include <iostream>
using namespace std;

int main()
{
    int stat, flex, prof;
    cin>>stat>>flex>>prof;

    if(flex>=prof)
        cout<<"-1";
    else
        cout<<stat/(prof-flex)+1;
    return 0;
}