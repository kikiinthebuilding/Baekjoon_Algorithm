#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M; cin>>N>>M;

    vector<int> n;
    for(int i=1; i<=N; i++) n.push_back(i);

    vector<bool> r;
    for(int i=1; i<=n.size(); i++) {
        if(i<=M) r.push_back(1);
        else r.push_back(0);
    }

    do {
        for(int i=0; i<n.size(); i++) {
            if(r[i])
                cout<<n[i]<<' ';
        }
        cout<<'\n';
        reverse(n.begin()+M, n.end());
    } while (next_permutation(n.begin(), n.end()));

    return 0;
}

