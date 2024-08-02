#include <iostream>
using namespace std;

int main(void) {
    int sum, max = 0, maxIndex = -1;
    for (int i = 0; i < 5; i++) {
        int input; sum = 0;
        for (int j = 0; j < 4; j++) {
            cin>>input;
            sum += input;
        }
        if(max<sum) {
            max = sum;
            maxIndex = i+1;
        }
    }

    cout<<maxIndex<<" "<<max<<endl;

    return 0;
}