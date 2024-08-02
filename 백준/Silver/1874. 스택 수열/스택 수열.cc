#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    int cnt, max=0; cin>>cnt;
    char rslt[200000]; int ptr=0;
    stack<int> stk;
    while(cnt--) {
        int num; cin>>num;
        if(num>max) {
            for(int i=max+1;i<=num;i++)
            {
                stk.push(i);
                rslt[ptr++] = '+';
            }
        }
        else if(stk.top()!=num) {
            cout<<"NO";
            return 0;
        }
        stk.pop();
        rslt[ptr++]='-';
        if(max<num) max=num;
    }
    for(int i=0;i<ptr;i++) cout<<rslt[i]<<"\n";

    return 0;
}
