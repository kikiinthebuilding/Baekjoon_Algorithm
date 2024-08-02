#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin>>N;
    vector<string> vs;
    for(int i=0; i<N; i++) {
        string temp; cin>>temp;
        for(int j=0; j<temp.size(); j++) {
            if(temp[j]=='.') {
                string input = temp.substr(j+1);
                vs.push_back(input);
            }
        }
    }

    sort(vs.begin(), vs.end());

    vs.push_back("///");
    int cnt=1;
    for(int i=1; i<vs.size(); i++) {
        if(vs.at(i) == vs.at(i-1)) {
            cnt++;
        }
        else {
            cout<<vs.at(i-1)<<" "<<cnt<<endl;
            cnt=1;
        }
    }


    return 0;
}