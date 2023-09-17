#include <stdio.h>
#include <stdlib.h>

int recursive(int number1, int number2);
int iterate(int number1, int number2);
int check(int target);

int main() {

    int ans_rec = recursive(200000, 240000);
    int ans_ite = iterate(200000, 240000);

    printf("%d\n", ans_rec);
    printf("%d\n", ans_ite);

    int compare = check(10);
    printf("%s\n", compare ? "TRUE" : "FALSE");

    return 0;
}

int recursive(int number1, int number2) {
    if (number1 == 0) {
        return number2;
    } else if (number2 == 0) {
        return number1;
    } else {
        if (number1 > number2) {
            return recursive(number1 % number2, number2);
        } else {
            return recursive(number1, number2 % number1);
        }
    }
}

int iterate(int number1, int number2) {
    while (number1 != 0 && number2 != 0) {
        if (number1 > number2) {
            number1 = number1 % number2;
        } else {
            number2 = number2 % number1;
        }
    }
    if (number1 == 0) {
        return number2;
    } else {
        return number1;
    }
}

int check(int target) {
    int result = 0;
    for (int i = 0; i < target; i++) {
        int rec = recursive(i, i + 10);
        printf("%d\n", rec);
        int ite = iterate(i, i + 10);
        printf("%d\n", ite);
        if (rec != ite) {
            return 0;
        }
    }
    return 1;
}