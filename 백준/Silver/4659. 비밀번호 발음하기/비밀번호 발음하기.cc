#include <iostream>
#include <string>
using namespace std;

char moeum[5] = {'a', 'e', 'i', 'o', 'u'};

bool isMoeum(char c) {
    for(int i=0; i<5; i++)
        if(c == moeum[i])
            return true;
    return false;
}

bool checkPW(string s) {
    bool sw_moeum = 0;
    for(int i=0; i<s.length(); i++) {
        if(isMoeum(s[i])) sw_moeum = 1;
        if(s.length()>=3 && i<s.length()-2) {
            if((isMoeum(s[i]) && isMoeum(s[i+1]) && isMoeum(s[i+2]))
                || (!isMoeum(s[i]) && !isMoeum(s[i+1]) && !isMoeum(s[i+2])))
                return false;
        }
        if(s.length()>=2 && i<s.length()-1) {
            if(s[i]==s[i+1] && s[i]!='e' && s[i]!='o')
                return false;
        }
    }
    
    if(sw_moeum==0) 
        return false;
        
    return true;
}

int main() {
    string s; cin>>s;
    while(s.compare("end")!=0) {
        cout<<"<"<<s<<"> is ";
        if(!checkPW(s)) {
            cout<<"not ";
        }
        cout<<"acceptable."<<endl;
        cin>>s;
    }
    return 0;
}