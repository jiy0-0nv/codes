#include <stdio.h>

int main() {
    int a, b, c, ans;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) ans = b;
    else ans = a;
    if (a + b - ans > c) ans += c;
    else ans = a + b;
    if (ans > a + b + c - ans) ans = a + b + c;
    else ans += ans - 1;
    printf("%d", ans);
}