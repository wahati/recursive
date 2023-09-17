#include <stdio.h>
#include <stdlib.h>

int recursive(int stack);
int iterate(int stack);
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

int recursive(int stack) {
    if (stack == 1) {
        return 1;
    } else {
        return 1 + 2 * recursive(stack - 1);
    }
}

int iterate(int stack) {
    int step_count = 1;
    for (int i = 1; i < stack; i++) {
        step_count = 1 + 2 * step_count;
    }
    return step_count;
}

int check(int target) {
    int result = 0;
    for (int i = 1; i < target; i++) {
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