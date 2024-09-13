#include <iostream>
using namespace std;

bool palindrome(string s) {
    int len = s.length();
    for(int i=0; i<len/2; i++) {
        if(s[i]!=s[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s; bool sw;
    while((cin>>s) && s[0]!='0') {
        if(palindrome(s)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}