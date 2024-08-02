#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T;
    int arr[3] = {300, 60, 10};
    int cnt[3] = {0,};

    int index=0;
    while(T) {
        if(T-arr[index]>=0) {
            T-=arr[index];
            cnt[index]++;
        }
        else if(index==2 && T-arr[index]<0) {
            cout<<-1<<endl;
            return 0;
        }
        else index++;
    }

    for(int i=0; i<3; i++) {
        cout << cnt[i] << " ";
    }
    cout<<endl;

    return 0;
}