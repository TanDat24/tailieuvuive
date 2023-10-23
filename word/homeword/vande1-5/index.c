#include <stdio.h>
#include <math.h>
int main() {
    int a, b;
    char op;
    printf("\nNhap phep toan: ");
    scanf("%c", &op);

    printf("\nNhap 2 so a, b vao: ");
    scanf("%d%d", &a, &b);

    switch (op)
    {
    case '+':
        printf("%d + %d = %d", a, b, a+b);
        break;
    case '-':
        printf("%d - %d = %d", a, b, a-b);
        break;
    case '*':
        printf("%d * %d = %d", a, b, a*b);
        break;
    case '/':
        printf("%d / %d = %d", a, b, a/b);
        break;
    default:
    printf("\nKhong co phep toan nay!!");
        break;
    }
    return 0;
}