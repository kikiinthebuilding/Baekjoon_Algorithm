#include <iostream>
#include <string>
using namespace std;

void printScore(string s) {
    if(s[0]=='A' && s[1]=='+') cout<<"4.3"<<endl;
    else if(s[0]=='A' && s[1]=='0') cout<<"4.0"<<endl;
    else if(s[0]=='A' && s[1]=='-') cout<<"3.7"<<endl;
    else if(s[0]=='B' && s[1]=='+') cout<<"3.3"<<endl;
    else if(s[0]=='B' && s[1]=='0') cout<<"3.0"<<endl;
    else if(s[0]=='B' && s[1]=='-') cout<<"2.7"<<endl;
    else if(s[0]=='C' && s[1]=='+') cout<<"2.3"<<endl;
    else if(s[0]=='C' && s[1]=='0') cout<<"2.0"<<endl;
    else if(s[0]=='C' && s[1]=='-') cout<<"1.7"<<endl;
    else if(s[0]=='D' && s[1]=='+') cout<<"1.3"<<endl;
    else if(s[0]=='D' && s[1]=='0') cout<<"1.0"<<endl;
    else if(s[0]=='D' && s[1]=='-') cout<<"0.7"<<endl;
    else cout<<"0.0"<<endl;
}

int main() {
    string s; cin>>s;
    printScore(s);
}