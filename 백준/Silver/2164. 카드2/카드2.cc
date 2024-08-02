#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;

    queue<int> pack;
    for(int i=1; i<=N; i++)
        pack.push(i);

    if(pack.size()==1)
        cout<<1<<'\n';

    else {
        while(1) {
            pack.pop();
            if(pack.size()==1) break;

            pack.push(pack.front());
            pack.pop();
            if(pack.size()==1) break;
        }

        cout<<pack.front()<<'\n';
    }
    return 0;
}