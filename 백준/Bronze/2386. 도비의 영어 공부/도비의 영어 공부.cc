#include <iostream>
#include <string>
using namespace std;

int main() {
    string str; int cnt=0; char c;
    while(getline(cin, str) && (c=str[0])!='#') {
        cnt=0;
        for(int i=2; i<str.size(); i++)
            if(c==str[i] || c==(str[i]+32))
                cnt++;
        cout<<c<<" "<<cnt<<endl;
    }
}