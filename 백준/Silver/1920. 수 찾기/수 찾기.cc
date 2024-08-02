#include <iostream>
#include <algorithm>

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
    int n, m;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    std::sort(arr, arr+n);
    scanf("%d", &m);
    int target_arr[m];
    for(int i=0;i<m;i++) {
            scanf("%d", &target_arr[i]);
            printf("%d\n", bin_finder(arr, m, target_arr[i]));
    }
    return 0;
}
