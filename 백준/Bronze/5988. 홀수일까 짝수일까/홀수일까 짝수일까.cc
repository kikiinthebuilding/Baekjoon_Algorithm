#include <iostream>
#include <string>
using namespace std;
int main(void) {
    long long cnt; cin>>cnt;
    while(cnt--) {
        string k; cin>>k;
        if(k.back()%2==0) printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
