#include <iostream>
#define max 10001
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, temp; scanf("%d", &n);
    int arr[max]={0,};
    for(int i=0;i<n;i++)
    {
        scanf("%d", &temp);
        arr[temp]++;
    }
    for(int i=0; i<max; i++)
        for(int j=0; j<arr[i]; j++)
        printf("%d\n", i);
    return 0;
}
