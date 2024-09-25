#include <iostream>
using namespace std;

int main() {
    int N, A, B; cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>A>>B;
        printf("Case #%d: %d + %d = %d\n", i, A, B, A+B);
    }
    return 0;
}