#include <iostream>
#include <cmath>
using namespace std;
int getHex(int dest);

int main(void)
{
    int src=1, dest, result;
    cin>>dest;
    result = getHex(dest);
    cout<<result;
    return 0;
}

int getHex(int dest) {
    if (dest==1) return 1;
    int round, i=1, n=0;
    round = ceil((dest-2)/6);
    while(n<=round) {
        n=n+i;
        i++;
    }
    return i;
}