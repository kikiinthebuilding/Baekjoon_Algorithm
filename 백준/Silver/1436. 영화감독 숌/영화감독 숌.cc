#include <iostream>
using namespace std;

int N;
void checker(int num) {
    string numToString = to_string(num);
    for(int i=0; i<numToString.size()-2; i++) {
        if(numToString[i]=='6') {
            if(numToString[i+1]=='6' && numToString[i+2]=='6') {
                N--;
                return;
            }
        }
    }
}

int main(void) {
    cin>>N;

    int num=665;
    while(N) {
        num++;
        checker(num);
    }
    cout<<num;

    return 0;
}