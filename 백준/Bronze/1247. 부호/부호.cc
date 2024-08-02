#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, overflow; long long sum, temp;
    for(int i=0; i<3; i++) {
        cin>>T; sum=0; overflow=0;
        while(T--) {
            cin>>temp;
            if(sum>0 && temp>LLONG_MAX-sum) overflow++;
            else if(sum<0 && temp<LLONG_MIN-sum) overflow--;
            sum+=temp;
        }
        
        if(overflow>0) cout<<"+\n";
        else if(overflow<0) cout<<"-\n";
        else {
            if(sum>0) cout<<"+\n";
            else if(sum<0) cout<<"-\n";
            else cout<<"0\n";
        }
    }

    return 0;
}