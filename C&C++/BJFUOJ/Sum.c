#include <stdio.h>

int main() {
    int n;
    // 循环读取多组输入，直到没有输入为止
    while (scanf("%d", &n) != EOF) {
        // 利用等差数列求和公式计算
        int sum = n * (n + 1) / 2;
        printf("%d\n", sum);
    }
    return 0;
}