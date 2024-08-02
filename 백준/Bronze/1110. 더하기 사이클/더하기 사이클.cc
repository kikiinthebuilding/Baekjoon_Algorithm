#include <iostream>
#include <vector>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num; cin>>num;
    vector<int> v;
    v.push_back(num);
    do{
        int temp;
        temp = (v.back()%10)*10 + (v.back()/10+v.back()%10)%10;
        v.push_back(temp);
    }while(v.back()!=num);
    printf("%d", v.size()-1);
    return 0;
}