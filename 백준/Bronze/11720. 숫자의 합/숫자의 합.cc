#include <iostream>
using namespace std;

int main(void) {
    int N; cin >> N; getchar();
    int sum = 0, temp;

    for(int i=0; i<N; i++) {
        temp = getchar() - '0';
        sum += temp;
    }
    cout<<sum;

    return 0;
}