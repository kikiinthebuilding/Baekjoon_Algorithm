#include <iostream>
using namespace std;
int main(void) {
    int num, max=0, maxIndex=10;
    for(int i=0;i<9;i++)
    {
        cin>>num;
        if(num>max) {
            max=num; maxIndex=i+1;
        }
    }
    printf("%d\n%d",max,maxIndex);
}