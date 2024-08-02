#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[3], sum=0;
    for(int i=0; i<3; i++) cin>>arr[i];
    sort(arr, arr+3);
    while(arr[2] >= arr[0] + arr[1]) {
        arr[2]--;
    }
    for(int i=0; i<3; i++) sum+=arr[i];
    cout << sum << '\n';

    return 0;
}

