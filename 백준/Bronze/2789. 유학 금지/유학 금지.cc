#include <iostream>
using namespace std;

bool delete_cambridge(char c) {
    if(c=='C' || c=='A' || c=='M' || c=='B' || c=='R' || c=='I' || c=='D' || c=='G' || c=='E')
        return true;
    return false;
}

int main() {
    string s, answer; cin>>s;
    for(int i=0; i<s.size(); i++) {
        if(!delete_cambridge(s[i]))
            answer.push_back(s[i]);
    }
    cout<<answer<<endl;
    return 0;
}