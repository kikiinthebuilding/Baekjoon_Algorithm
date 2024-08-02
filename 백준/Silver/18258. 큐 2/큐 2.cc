#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

queue<int> q;

void myQueue() {
    string s; cin >> s;

    if(s.compare("push") == 0) {
        int num; cin>>num;
        q.push(num);
    }
    else if(s.compare("pop")==0) {
        if(!q.empty()) {
            cout<<q.front()<<'\n';
            q.pop();
        }
        else
            cout<<-1<<'\n';
    }
    else if(s.compare("size")==0) {
        cout<<q.size()<<'\n';
    }
    else if(s.compare("empty")==0) {
        if(!q.empty())
            cout<<0<<'\n';
        else
            cout<<1<<'\n';
    }
    else if(s.compare("front")==0) {
        if(!q.empty())
            cout<<q.front()<<'\n';
        else
            cout<<-1<<'\n';
    }
    else if(s.compare("back")==0) {
        if(!q.empty())
            cout<<q.back()<<'\n';
        else
            cout<<-1<<'\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;

    while(N--) {
        myQueue();
    }

    return 0;
}