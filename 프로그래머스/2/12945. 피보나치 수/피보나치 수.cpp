#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int fibo[100001]; fibo[0]=0; fibo[1]=1;
    
    for(int i=2; i<=n; i++) {
        fibo[i]=(fibo[i-1]+fibo[i-2])%1234567;
    }
    
    return fibo[n];
}