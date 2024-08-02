#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int edge[3] = {-1, -1, -1};

    while(1) {
        int sum=0;
        for(int & i : edge) {
            cin>>i; sum+=i;
        }
        if(sum==0) break;
        sort(edge, edge+3);

        if(edge[0]+edge[1]<=edge[2])
            cout<<"Invalid\n";
        else if(edge[0]==edge[1] && edge[0]==edge[2])
            cout<<"Equilateral\n";
        else if((edge[0]==edge[1] && edge[0]!=edge[2]) || (edge[1]==edge[2] && edge[0]!=edge[2]))
            cout<<"Isosceles\n";
        else
            cout<<"Scalene\n";
    }

    return 0;
}