#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k; cin>>n>>k;
    queue<int> que;
    cout<<"<";
    for(int i=1;i<=n;i++)
        que.push(i);
    
    while(!que.empty()) {
        for(int i=0;i<k-1;i++) {
            que.push(que.front());
            que.pop();
        }
        cout<<que.front();
        que.pop();
        if(!que.empty()) cout<<", ";
    }
    cout<<">";
    
    return 0;
}

// 알고리즘이 어떻게 작동하는지 파악하는 게 중요!