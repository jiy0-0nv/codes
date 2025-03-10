#include <stdio.h>

int stars(int i, int n){
    for(int j=0; j<n-1-i; j++){
        printf(" ");
    }
    for(int j=0; j<i*2+1; j++){
        printf("*");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        stars(i, n);
    }
    for(int i=n-2; i>=0; i--){
        stars(i, n);
    }
    return 0;
}