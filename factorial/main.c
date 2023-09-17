#include <stdio.h>
#include <stdlib.h>

int recursive(int start);
int iterate(int start);
int check(int target);

int main() {

    int ans_rec = recursive(6);
    int ans_ite = iterate(6);

    printf("%d\n", ans_rec);
    printf("%d\n", ans_ite);

    int compare = check(100);
    printf("%s\n", compare ? "TRUE" : "FALSE");

    return 0;
}

int recursive(int start) {
    if (start == 0) {
        return 1;
    } else {
        return start * recursive(start - 1);
    }
}

int iterate(int start) {
    int result = 1;
    for (int i = start; i > 1; i--)
        result *= i; 
    return result;
}

int check(int target) {
    int result = 0;
    for (int i = 0; i <= target; i++) {
        int rec = recursive(i);
        int ite = iterate(i);
        if (rec != ite) {
            return 0;
        }
    }
    return 1;
}