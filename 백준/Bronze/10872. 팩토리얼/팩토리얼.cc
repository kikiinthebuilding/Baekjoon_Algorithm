#include <iostream>
using namespace std;
int main(void) {
    int n; cin>>n;
    int fact=1;
    for(int i=2; i<=n; i++)
        fact=fact*i;
    printf("%d", fact);
    return 0;
}