#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<char> alp;
    int cnt=0; bool sw=0;
    int N; cin>>N;
    while(N--) {
        sw=0;
        alp.clear();
        string str; cin >> str;
        alp.push_back(str[0]);
        for(int i=1; i < str.size(); i++) {
            if(str[i] == str[i - 1])
                continue;
            if (find(alp.begin(), alp.end(), str[i]) != alp.end()) {
                sw=1; break;
            }
            alp.push_back(str[i]);
        }
        if(sw) continue;
//        cout<<"["<<str<<"]"<<endl;
        cnt++;
    }

    cout<<cnt;

    return 0;
}