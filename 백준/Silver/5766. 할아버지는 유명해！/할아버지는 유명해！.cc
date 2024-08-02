#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    while(true) {

        int arr[10001] = {0, };
        cin>>N>>M;
        if(N==0 && M==0) break;

        for(int i=0; i<N*M; i++) {
            int num; cin>>num;
            arr[num]++;
        }

        int max=-1, maxIndex=-1;
        for(int i=1; i<=10000; i++) {
            if(max<arr[i]) {
                max=arr[i];
                maxIndex = i;
            }
        }
        arr[maxIndex]=-1;
        max = *max_element(arr, arr+10000);
        for(int i=1; i<=10000; i++) {
            if(max==arr[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}