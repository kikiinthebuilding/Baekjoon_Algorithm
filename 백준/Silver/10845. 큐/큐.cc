#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    queue<int> que; string str;
    short comcnt; cin>>comcnt;

    while(comcnt-->0)
    {
        cin>>str;
        if(str=="push") {
            int num; cin>>num;
            que.push(num);
        }
        else if(str=="pop") {
            if(!que.empty())
            {
                cout<<que.front()<<endl;
                que.pop();
            }
            else cout<<"-1"<<endl;
        }
        else if(str=="size")
            cout<<que.size()<<endl;
        else if(str=="empty")
            cout<<que.empty()<<endl;
        else if(str=="front")
        {
            if(!que.empty())
                cout<<que.front()<<endl;
            else
                cout<<"-1"<<endl;
        }
        else if(str=="back")
        {
            if(!que.empty())
                cout<<que.back()<<endl;
            else
                cout<<"-1"<<endl;
        }
    }
    return 0;
}