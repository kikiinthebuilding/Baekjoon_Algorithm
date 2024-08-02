#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int row=0, col=0;
    bool flag=false;
    int cnt; cin>>cnt;
    string arr[cnt];

    for(int i=0;i<cnt;i++) cin>>arr[i];

    for(int i=0;i<cnt;i++)
    {
        flag=false;
        for(int j=1;j<cnt;j++)
        {
            if(arr[i][j-1]=='.' && arr[i][j]=='.' && flag==false) {
                row++;
                flag=true;
            }

            else if(arr[i][j]=='X')
                flag=false;
        }
    }

    flag=false;

    for(int j=0;j<cnt;j++)
    {
        flag=false;
        for(int i=1;i<cnt;i++)
        {
            if(arr[i-1][j]=='.' && arr[i][j]=='.' && flag==false) {
                col++;
                flag=true;
            }

            else if(arr[i][j]=='X')
                flag=false;
        }
    }


    cout<<row<<" "<<col;

    return 0;
}
