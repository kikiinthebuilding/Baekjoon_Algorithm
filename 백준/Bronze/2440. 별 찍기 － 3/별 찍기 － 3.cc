#include <iostream>
using namespace std;
int main(void) {
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}