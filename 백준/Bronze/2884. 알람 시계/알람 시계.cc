#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
    int h, m; cin>>h>>m;
    if(m-45<0) {
        m=m+15;
        if(h==0) h=23;
        else h--;
    }
    else m=m-45;
    cout<<h<<" "<<m;
    return 0;
}