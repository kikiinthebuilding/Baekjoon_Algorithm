#include <iostream>
#include <string>
using namespace std;
int main(void) {
    string str; cin>>str;
    int len = str.size(); int cnt=0;
    for(int i=0;i<len;i++)
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            cnt++;
    printf("%d", cnt);
    return 0;
}
