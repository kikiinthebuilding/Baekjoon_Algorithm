#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T; cin>>T;
    while(T--) {
        string s1, s2;
        cin>>s1>>s2;

        int gap = s1.size() - s2.size();

        string temp; temp.append(abs(gap), '0');

        if(gap > 0) s2.insert(0, temp);
        else s1.insert(0, temp);

        for(int i=s1.size()-1; i>=0; i--) {
            s1[i]+=(s2[i]-'0');
            if(s1[i]=='2' || s1[i]=='3') {
                if(i==0) {
                    temp.clear();
                    temp.append(1, '1');
                    s1[i]%2 ? s1[i]='1' : s1[i]='0';
                    s1.insert(0, temp);
                    break;
                }
                s1[i-1]++;
                s1[i]%2 ? s1[i]='1' : s1[i]='0';
            }
        }
        bool sw = false;
        for(char i : s1) {
            if(!sw && i=='0') continue;
            if(i=='1') sw=true;
            cout<<i;
        }
        if(!sw) cout<<0;
        cout<<endl;
    }

    return 0;
}
