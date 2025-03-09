#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a < x){
            printf("%d ", a);
        }
    }
    return 0;
}