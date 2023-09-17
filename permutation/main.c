#include <stdio.h>
#include <stdlib.h>

int recursive(int element);
int iterate(int element);
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

int recursive(int element) {
    if (element == 0 || element == 1) {
        return 1;
    } else {
        return element * recursive(element - 1);
    }
}

int iterate(int element) {
    int permutation = 1;
    for (int i = 1; i <= element; i++) {
        permutation *= i;
    }
    return permutation;
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