#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int weight;
    int height;
    int rank;
}Build;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N; cin>>N;
    Build build[N];
    for(int i=0; i<N; i++) {
        cin>>build[i].weight>>build[i].height;
        build[i].rank = 1;
    }

    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(build[j].weight < build[i].weight && build[j].height < build[i].height)
                build[j].rank++;
            else if(build[j].weight > build[i].weight && build[j].height > build[i].height)
                build[i].rank++;
        }
    }

    for(int i=0; i<N; i++) {
        cout<<build[i].rank<<" ";
    }
    cout<<endl;

    return 0;
}