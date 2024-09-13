#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s, s1; getline(cin, s);
    stringstream ss(s);
    int cnt=0;
    while (ss>>s1) cnt++;
    cout<<cnt<<'\n';
    return 0;
}