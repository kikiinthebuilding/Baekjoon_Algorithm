#include <iostream>
#include <cstring>

using namespace std;

char temp[5];

void oct_to_bin(int oct) {
    switch(oct) {
        case 0 :
            strcpy(temp, "000");
            break;
        case 1 :
            strcpy(temp, "001");
            break;
        case 2 :
            strcpy(temp, "010");
            break;
        case 3 :
            strcpy(temp, "011");
            break;
        case 4 :
            strcpy(temp, "100");
            break;
        case 5 :
            strcpy(temp, "101");
            break;
        case 6 :
            strcpy(temp, "110");
            break;
        case 7 :
            strcpy(temp, "111");
            break;
    }
}

int main(void) {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n = getchar()-'0';
    if(n==0) cout<<0;
    else {
        oct_to_bin(n);
        if(temp[0]=='0') {
            if(temp[1]=='0') {
                cout<<temp[2];
            }
            else {
                cout<<temp[1]<<temp[2];
            }
        }
        else {
            cout<<temp;
        }

        while((n=getchar())!='\n') {
            n-='0';
            oct_to_bin(n);
            cout<<temp;
        }
    }
    return 0;
}
