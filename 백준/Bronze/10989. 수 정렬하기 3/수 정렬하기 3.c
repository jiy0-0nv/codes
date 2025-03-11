#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t;
    scanf("%d", &n);

    int *arr = (int *)calloc(10001, sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d", &t);
        arr[t] += 1;
    }
    for (int i=1;i<10001;i++){
        for (int j=0;j<arr[i];j++) printf("%d\n", i);
    }
    return 0;
}