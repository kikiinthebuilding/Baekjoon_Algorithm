#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
    deque<int> deq; string str;

    short comcnt; cin>>comcnt;

    while(comcnt-->0)
    {
        cin>>str;
        if(str=="push_front")
        {
            int num; cin>>num;
            deq.push_front(num);
        }
        else if(str=="push_back")
        {
            int num; cin>>num;
            deq.push_back(num);
        }

        else if(str=="pop_front")
        {
            if(!deq.empty()) {
                cout<<deq.front()<<endl;
                deq.pop_front();
            }
            else
                cout<<"-1"<<endl;
        }
        else if(str=="pop_back")
        {
            if(!deq.empty()) {
                cout<<deq.back()<<endl;
                deq.pop_back();
            }
            else
                cout<<"-1"<<endl;
        }

        else if(str=="size")
            cout<<deq.size()<<endl;

        else if(str=="empty")
            cout<<deq.empty()<<endl;

        else if(str=="front")
        {
            if(!deq.empty())
                cout<<deq.front()<<endl;
            else
                cout<<"-1"<<endl;
        }
        else if(str=="back")
        {
            if(!deq.empty())
                cout<<deq.back()<<endl;
            else
                cout<<"-1"<<endl;
        }
    }

    return 0;
}