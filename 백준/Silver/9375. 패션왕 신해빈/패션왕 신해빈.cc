#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, T; cin>>T;

    while(T--) {
        map<string, int> closet;
        cin>>N;

        string t1, t2;
        while(N--) {
            cin>>t1>>t2;
            if(closet.find(t2) == closet.end())
                closet.insert({t2, 1});
            else
                closet[t2]++;
        }

        int result=1;
        for(auto & iter : closet) {
            result *= (iter.second+1);
        }
        result--;
        cout<<result<<'\n';
    }

    return 0;
}