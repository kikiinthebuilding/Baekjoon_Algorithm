#include <string>
#include <vector>
#include <iostream>
using namespace std;

string ten_to_two(int n) {
    int two; string s;
    for(two=1; n/two>1; two*=2);
    while(two) {
        if(n/two) {
            s.push_back('1');
            n-=two;
        }
        else s.push_back('0');
        two/=2;
    }
    return s;
}

vector<int> solution(string s) {
    int zero_cnt=0, stage_cnt=0;
    string one; one+='1';
    
    while(s.compare(one)!=0) {
        string temp; int temp_zero_cnt=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') 
                temp_zero_cnt++;
        }
        temp.append(s.size()-temp_zero_cnt, '1');
        
        s=ten_to_two(temp.size());
        
        zero_cnt += temp_zero_cnt;
        stage_cnt++;
    }

    return {stage_cnt, zero_cnt};
}