#include <iostream>
using namespace std;

int main() {
    string s; bool sw;
    while((cin>>s) && s[0]!='0') {
        sw = true;
        int len = s.length();
        for(int i=0; i<len/2; i++) {
            if(s[i]!=s[len-i-1]) {
                sw = false;
                break;
            }
        }
        if(sw) cout<<"yes\n";
        if(!sw) cout<<"no\n";
    }
    return 0;
}