#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int cnt; cin>>cnt;

    while(cnt--) {
        deque<int> deq;
        string p, data; int n;
        bool rvrs=0, err=0;
        cin>>p>>n>>data;

        string temp="";
        for(int i=0;i<data.length();i++) {
            if(data[i]=='[') continue;
            else if(data[i]>='0' && data[i]<='9')
                temp+=data[i];
            else if((data[i]==',' || data[i]==']') && temp!="") {
                deq.push_back(stoi(temp));
                temp="";
            }
        }

        for(int i=0; p[i]!='\0';i++) {
            if(p[i]=='R')
                rvrs=!rvrs;
            else if(p[i]=='D') {
                if(deq.empty()) {
                    err=1; break;
                }
                if(rvrs) deq.pop_back();
                else deq.pop_front();
            }
        }

        if(err) cout<<"error\n";
        else if(deq.empty()) cout<<"[]\n";
        else if(rvrs) {
            cout<<"[";
            while(deq.size()>1) {
                cout<<deq.back()<<",";
                deq.pop_back();
            }
            cout<<deq.back()<<"]\n";
        }
        else {
            cout<<"[";
            while(deq.size()>1) {
                cout<<deq.front()<<",";
                deq.pop_front();
            }
            cout<<deq.front()<<"]\n";
        }
    }

    return 0;
}