#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string s) {
    if(islower(s[0])) s[0]=toupper(s[0]);
    
    for(int i=1; i<s.size(); i++) {
        if(s[i]==' ') continue;
        if(s[i-1]==' ' && islower(s[i])) s[i]=toupper(s[i]);
        if(s[i-1]!=' ' && isupper(s[i])) s[i]=tolower(s[i]);
    }
    
    return s;
}