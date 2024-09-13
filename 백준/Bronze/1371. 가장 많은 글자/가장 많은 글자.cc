#include <iostream>
#include <vector>
using namespace std;

int main() {
    int alphabet[26] ={0, };
    string s;
    while(getline(cin, s))
        for(int i=0; i<s.length(); i++)
            alphabet[s[i]-97]++;
    
    int max=0; vector<int> maxIndex;
    for(int i=0; i<26; i++) {
        if(alphabet[i]>max) {
            max = alphabet[i];
            maxIndex.clear();
            maxIndex.push_back(i);
        }
        else if(alphabet[i]==max) {
            maxIndex.push_back(i);
        }
    }
    
    for(int i=0; i<maxIndex.size(); i++)
        printf("%c", maxIndex[i]+97);
    return 0;
}