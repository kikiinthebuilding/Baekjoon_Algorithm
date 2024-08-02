#include <iostream>
using namespace std;
int main(void) {
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) {
            if(j<i) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}