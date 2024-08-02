#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    int max=-1, x, y;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin>>num;
            if(max<=num) {
                max = num;
                x = i, y = j;
            }
        }
    }
    cout<<max<<endl;
    cout<<x+1<<" "<<y+1<<endl;

    return 0;
}
