#include<stdio.h>

int main() {
    int a = 100, x = 10, y = 20, k1 = 5, k2 = 0;
    if (x < y)                // 10 < 20 进入
        if (y != 10)          // 20 != 10 进入
            if (!k1)          // !5 = 0 进else
                a = 1;
            else
                if (k2)       // 0 不进
                    a = 10;
    a = -1;                   // a = -1
    printf("% d\n", a);       // -1
}

