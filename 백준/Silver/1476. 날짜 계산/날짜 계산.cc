#include <iostream>
using namespace std;

int main(void) {
    int E, S, M;
    int yE, yS, yM; yE=yS=yM=0;
    int year=1;
    cin>>E>>S>>M;
    while(1) {
        if((yE+1)==E && (yS+1)==S && (yM+1)==M)
        {
            cout<<year<<endl;
            break;
        }
        else {
            year++; yE++; yS++; yM++;
            yE=yE%15; yS=yS%28; yM=yM%19;
        }
    }

    return 0;
}
