#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int hour, min, time; cin>>hour>>min>>time;
    hour += time/60;
    min += time%60;
    if(min>=60) {
        min-=60;
        hour++;
    }
    if(hour>=24) hour-=24;

    cout<<hour<<" "<<min<<endl;

    return 0;
}