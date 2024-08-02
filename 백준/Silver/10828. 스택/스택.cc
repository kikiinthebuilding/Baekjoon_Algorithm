#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> s;

    int N; cin>>N;
    for(int i=0; i<N; i++) {
        char temp[10]; cin>>temp;

        if(strcmp(temp, "push")==0) {
            int tmp; cin>>tmp;
            s.push(tmp);
        }
        else if(strcmp(temp, "pop")==0) {
            if(s.empty()) cout<<-1<<endl;
            else {
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else if(strcmp(temp, "size")==0) {
            cout<<s.size()<<endl;
        }
        else if(strcmp(temp, "empty")==0) {
            cout<< (s.empty() ? 1 : 0) <<endl;
        }
        else if(strcmp(temp, "top")==0) {
            cout<< (s.empty() ? -1 : s.top()) <<endl;
        }
    }
}
