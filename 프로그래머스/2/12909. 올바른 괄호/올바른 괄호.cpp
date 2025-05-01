#include<string>
#include <iostream>

using namespace std;

bool solution(string s) {
    
    int left_cnt=0, right_cnt=0;
    
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') left_cnt++;
        else if(s[i]==')') right_cnt++;
        
        if(right_cnt>left_cnt) return false;
    }
    if(left_cnt!=right_cnt) return false;

    return true;
}