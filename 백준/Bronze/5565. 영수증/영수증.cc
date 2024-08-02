#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int total, temp;
    cin>>total;
    for(int i=0; i<9; i++) {
        cin>>temp;
        total-=temp;
    }
    cout<<total<<endl;

    return 0;
}

