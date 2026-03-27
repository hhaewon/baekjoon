#include <stdio.h>

int main() {
    int a0, a1, c, n0;
    scanf("%d %d %d %d", &a1, &a0, &c, &n0);
    if (a1==c && a0<=0) {
        printf("1");
    } else if (c-a1 > 0 && a0 <= n0*(c-a1)) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}