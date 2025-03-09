#include <stdio.h>

int main()
{
    int x, n;
    scanf("%d\n%d", &x, &n);
    int a, b;
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        x -= a * b;
    }
    if(x){
        printf("No");
    }else{
        printf("Yes");
    }
    
    return 0;
}