#include <iostream>
using namespace std;

int moeum(string s) {
    int cnt=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            cnt++;
    }
    return cnt;
}

int main() {
    string s; 
    while(getline(cin, s) && s[0]!='#') {
        cout<<moeum(s)<<'\n';
    }
    
    return 0;
}