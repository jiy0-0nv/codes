#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int ans;
    ans = (int)(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2) + pow(e, 2)) % 10;
    printf("%d", ans);
    
    return 0;
}