#include <stdio.h>

int sub(int num1, int num2) {
    return num1 - num2;
}

int mul(int num1, int num2) {
    return num1 * num2;
}

int main() {
    int num1, num2, result;
    char op;

    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf(" %c", &op);

    if (op == '-') {
        result = sub(num1, num2);
        printf("%d\n", result);
    } else if (op == '+') {
        result = num1 + num2;
        printf("%d\n", result);
    } else if (op == '*') {
        result = mul(num1, num2);
        printf("%d\n", result);
    } else {
        printf("Invalid operator\n");
    }

    return 0;
}