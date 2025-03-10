#include <stdio.h>
#include <string.h>

int main() {
    int t;
    char s[10001];
    char a, b;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        scanf("%s", s);
        if(strlen(s)==7){
            a = s[0];
            b = s[2];
            if (a!=b && s[1]==a && s[3]==b && s[4]==a && s[5]==b && s[6]==b){
                printf("1\n");
                continue;
            }
        }
        printf("0\n");
    }
    return 0;
}