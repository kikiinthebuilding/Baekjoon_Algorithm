#include <iostream>
using namespace std;

int main() {
    string s; cin>>s;
    for(int i=0; i<3; i++) {
        for(int ii=0; ii<3; ii++) {
            if(i==1 && ii==1) cout<<":"<<s<<":";
            else cout<<":fan:";
        }
        cout<<endl;
    }
    return 0;
}