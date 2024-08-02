#include <iostream>
#include <vector>
using namespace std;

const char quack[5] = {'q', 'u', 'a', 'c', 'k'};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> ducks;
    char letter;

    while((letter=getchar())!='\n') {
        if(ducks.empty()){
            ducks.push_back(1);
        }
        else {
            bool sw = false;
            for(int & duck : ducks) {
                if(quack[duck] == letter) {
                    duck++; duck %= 5;
                    sw = true;
                    break;
                }
            }
            if (sw) continue;
            else if (letter != quack[0]) {
                cout<<-1<<endl;
                return 0;
            }
            ducks.push_back(1);
        }
    }
    
    for(int duck : ducks) {
        if(duck != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout<<ducks.size()<<endl;
    return 0;
}