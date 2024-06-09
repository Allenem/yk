#include<stdio.h>

int main() {
    int i = 10, j = 0, k = 1;
    printf("% d\n", j = 0); // 0
    printf("% d\n", k = 1); // 1
    printf("% d\n", k);     // 1
    printf("% d\n", k = 2); // 2
    printf("% d\n", k);     // 2

    if (j = 0) i++;         // j = 0, 返回0，不执行
    else i--;               // i = i - 1 = 9
    printf("% d\n", i);     // 9
}


