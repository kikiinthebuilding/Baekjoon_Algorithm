#include <iostream>
#include <vector>
using namespace std;

bool counter(string str) {
    int cnt=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(')
            cnt++;
        else if(str[i]==')')
        {
            if(cnt==0) return 0;
            else if(cnt>0) cnt--;
            else break;
        }
    }
    if(cnt==0) return 1;
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt;
    cin>>cnt;
    
    vector<string> str(cnt);
    for(int i=0; i<cnt; i++) {
        cin>>str[i];
        if(counter(str[i])) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    
    return 0;
}