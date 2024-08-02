#include <stdio.h>
#define max 1000000
bool prmArr[max+1];

void mkArr(int n) {
    for(int i=2; i*i<=n; i++)
        if(prmArr[i]==false)
            for(int j=i*i; j<=n; j+=i)
                prmArr[j]=true;
}

int main(void) {
    mkArr(max);
    while(1) {
        int num; bool suc=false;
        scanf("%d", &num);
        if(num==0) return 0;
        for(int i=2;i<=max;i++) {
            if(!prmArr[i] && !prmArr[num-i])  {
                printf("%d = %d + %d\n", num, i, num-i);
                suc=true;
                break;
            }
        }
        if(!suc) printf("Goldbach's conjecture is wrong \n");
    }
    return 0;
}
