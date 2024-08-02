#include <iostream>
using namespace std;
int main(void) {
    int n; cin>>n;

    if(n>=90) printf("A");
    else if(n>=80) printf("B");
    else if(n>=70) printf("C");
    else if(n>=60) printf("D");
    else printf("F");

    return 0;
}
