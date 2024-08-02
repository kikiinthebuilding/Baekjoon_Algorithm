#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int x, y, w, h; cin>>x>>y>>w>>h;
    cout<<min(min(x, y), min(w-x, h-y))<<endl;

    return 0;
}