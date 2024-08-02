#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n, m;
    string s; char temp;
    
    while( (temp=getchar()) != ':')
        s.push_back(temp);
    n = stoi(s);
    s.clear();
    
    while( (temp=getchar()) != '\n')
        s.push_back(temp);
    m = stoi(s);

    int sml = n < m ? n : m;

    int gcd = 0;
    for(int i=2; i <= sml; i++)
        if(n % i == 0 && m % i == 0)
            gcd = i;

    if(gcd)
        printf("%d:%d\n", n/gcd, m/gcd);
    else
        printf("%d:%d\n", n, m);

    return 0;
}