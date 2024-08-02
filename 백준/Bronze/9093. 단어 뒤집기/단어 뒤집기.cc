#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin>>T; cin.ignore();
    while(T--) {
        string s; getline(cin, s);
        s.push_back('\n');

        string rev;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==' ' || s[i]=='\n') {
                reverse(rev.begin(), rev.end());
                cout<<rev<<s[i];
                rev.clear();
            }
            else {
                rev.push_back(s[i]);
            }
        }
    }

    return 0;
}