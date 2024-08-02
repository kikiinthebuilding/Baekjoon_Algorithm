#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int n1, int n2) {
    return n1>n2;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) cin>>a[i];
    int b[n]; for(int i=0; i<n; i++) cin>>b[i];

    sort(a, a+n); sort(b, b+n, desc);

    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i]*b[i];

    cout<<sum;

    return 0;
}