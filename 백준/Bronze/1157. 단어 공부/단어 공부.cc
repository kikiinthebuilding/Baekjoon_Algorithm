#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input; cin>>input;
    int alp_cnt[36] = {0, };

    for(int i=0; i<input.size(); i++) {
        input[i] = toupper(input[i]);
        alp_cnt[input[i]-65]++;
    }

    int max=0, maxIndex=-1; bool dup = false;
    for(int i=0; i<36; i++) {
        if(max==alp_cnt[i]) {
            dup = true;
        }
        else if(max<alp_cnt[i]) {
            dup = false;
            max = alp_cnt[i];
            maxIndex = i;
        }
    }

    if(dup) cout<<"?\n";
    else printf("%c\n", maxIndex+65);
    return 0;
}