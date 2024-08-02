#include <iostream>
using namespace std;

long check_students(int A, int B, int C) {
    A -= B;
    if (A <= 0) return 1;
    return (A + C - 1) / C + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    long N, B, C, result=0;
    cin>>N;
    long A[N]; for(int i=0; i<N; i++) cin>>A[i];
    cin>>B>>C;
    
    for(long i=0; i<N; i++) result += check_students(A[i], B, C);
    cout<<result<<endl;

    return 0;
}