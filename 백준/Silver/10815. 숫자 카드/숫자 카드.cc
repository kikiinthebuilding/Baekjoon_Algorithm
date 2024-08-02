#include <iostream>
#include <algorithm>
using namespace std;

bool bin_finder(int* arr, int length, int target) {
    int bgn=0, fin=length-1, mid;
    while(fin-bgn>=0) {
        mid=(bgn+fin)/2;
        if(arr[mid]==target)
            return 1;
        else if(arr[mid]>target)
            fin = mid-1;
        else
            bgn = mid+1;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr, arr+n);

    cin>>m;

    int target_arr[m];
    for(int i=0;i<m;i++) {
            cin>>target_arr[i];
            cout<<bin_finder(arr, n, target_arr[i])<<" ";
    }

    return 0;
}
