#include <iostream>
using namespace std;
int main(void) {
    int n; cin>>n;
    int cuteN=0, nCuteN=0;
    while(n--) {
        bool num; cin>>num;
        if(num) cuteN++;
        else nCuteN++;
    }
    printf("Junhee is ");
    if(cuteN < nCuteN) printf("not ");
    printf("cute!");
}
