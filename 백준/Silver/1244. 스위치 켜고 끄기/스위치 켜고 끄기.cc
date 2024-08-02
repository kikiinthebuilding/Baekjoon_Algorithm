#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin>>N;
    bool switchs[N];
    for(int i=0; i<N; i++)
        cin>>switchs[i];
    int M; cin>>M;
    pair<int, int> students[M]; // 성별, 학생이 받은 수
    for(int i=0; i<M; i++)
        cin>>students[i].first>>students[i].second;

    for(int i=0; i<M; i++) {
        int gender = students[i].first;
        int getNum = students[i].second;

        if(gender==1) {
            int j = getNum-1;
            while (j < N) {
                switchs[j] = !switchs[j];
                j+=getNum;
            }
        }
        else {
            int j = getNum-1;
            switchs[j] = !switchs[j];
            int scope=1;
            while(j+scope < N && j-scope >= 0) {
                if(switchs[j+scope]==switchs[j-scope]) {
                    switchs[j+scope] = !switchs[j+scope];
                    switchs[j-scope] = !switchs[j-scope];
                    scope++;
                }
                else break;
            }
        }
    }

    for(int i=0; i<N; i++) {
        if(i%20==0 && i!=0) printf("\n");
        printf("%d ", switchs[i]);
    }

    return 0;
}
