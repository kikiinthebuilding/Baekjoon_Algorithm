#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cup[4] = {0, 1, 2, 3};

    int T; cin>>T;

    int n1, n2, i1, i2;
    while(T--) {
        cin>>n1>>n2;
        for(int i=1; i<=3; i++) {
            if(n1==cup[i]) i1=i;
            if(n2==cup[i]) i2=i;
        }
        swap(cup[i1], cup[i2]);
    }

    cout<<cup[1]<<endl;

    return 0;
}

