#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string prestr; cin>>prestr;
    int cnt; cin>>cnt;

    list<char> li(prestr.begin(), prestr.end());
    list<char>::iterator i;
    auto cursor=li.end();

    while(cnt--) {
        char cmd; cin>>cmd;
        if(cmd=='L' && cursor!=li.begin())
            cursor--;
        else if(cmd=='D' && cursor!=li.end())
            cursor++;
        else if(cmd=='B' && cursor!=li.begin()) {
            cursor=li.erase(--cursor);
        }
        else if(cmd=='P') {
            char temp; cin>>temp;
            li.insert(cursor, temp);
        }
    }

    for(i=li.begin(); i!=li.end(); i++)
        cout<<*i;
    return 0;
}

//list 클래스 공부 확실하게 할 것