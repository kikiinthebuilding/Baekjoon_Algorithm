#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s; getline(cin, s);
    stringstream ss(s);
    string s1; int cnt=0;
    while (ss>>s1)
        cnt++;
    cout<<cnt<<'\n';
    return 0;
}