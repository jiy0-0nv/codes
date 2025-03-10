#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[100][100] = {0, };
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)scanf("%d", &arr[i][j]);
    }

    int t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &t);
            printf("%d ", t + arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}