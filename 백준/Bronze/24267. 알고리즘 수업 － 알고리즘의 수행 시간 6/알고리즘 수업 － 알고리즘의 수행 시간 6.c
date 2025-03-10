#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n3", ((n-2)*(n-1)*(2*n-3)/6+(n-2)*(n-1)/2)/2);
}