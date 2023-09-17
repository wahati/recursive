#include <stdio.h>
#include <stdlib.h>

int recursive(int number);
int iterate(int number);
int check(int target);

int main() {

    int ans_rec = recursive(6);
    int ans_ite = iterate(6);

    printf("%d\n", ans_rec);
    printf("%d\n", ans_ite);

    int compare = check(10);
    printf("%s\n", compare ? "TRUE" : "FALSE");

    return 0;
}

int recursive(int number) {
    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return recursive(number - 2) + recursive(number - 1);
    }
}

int iterate(int number) {
    // if (number == 0 || number == 1) {
    //     return 1;
    // } else {
        int first = 1;
        int second = 1;
        for (int i = 1; i < number; i++) {
            int temp = first;
            first = second;
            second = temp + second;
        }
        return second;
    // }
}

int check(int target) {
    int result = 0;
    for (int i = 0; i < target; i++) {
        int rec = recursive(i);
        printf("%d\n", rec);
        int ite = iterate(i);
        printf("%d\n", ite);
        if (rec != ite) {
            return 0;
        }
    }
    return 1;
}