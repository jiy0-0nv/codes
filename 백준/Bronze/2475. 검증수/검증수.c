#include <stdio.h>

int main()
{
    int n, ans = 0;
    for(int i = 0; i < 5; i++){
        scanf("%d", &n);
        ans += n * n;
    }

    printf("%d", ans % 10);
    return 0;
}