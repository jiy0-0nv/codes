#include <stdio.h>

int main() {
    int maxNum=-1;
    int r, c;
    int n;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            scanf("%d", &n);
            if(n>maxNum){
                maxNum=n;
                r=i;
                c=j;
            }
        }
    }
    printf("%d\n%d %d", maxNum, r, c);
}