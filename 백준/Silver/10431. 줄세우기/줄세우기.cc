#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int P; cin>>P;

    int line[20], cnt;
    while(P--) {
        int N; cin>>N;
        cnt = 0;
        for(int i=0; i<20; i++)
            cin>>line[i];
        for(int i=0; i<20; i++) {
            for(int j=i; j<20; j++) 
                if(line[i] > line[j]) 
                    cnt++;
        }
        cout<<N<<" "<<cnt<<'\n';
    }
    return 0;
}