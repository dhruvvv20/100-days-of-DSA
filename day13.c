#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int **a = malloc(r * sizeof(int*));
    for (int i = 0; i < r; ++i) {
        a[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; ++j) scanf("%d", &a[i][j]);
    }

    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int first = 1; // to control spacing

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) {
            if (!first) putchar(' ');
            printf("%d", a[top][j]);
            first = 0;
        }
        top++;
        if (top > bottom) break;

        for (int i = top; i <= bottom; ++i) {
            if (!first) putchar(' ');
            printf("%d", a[i][right]);
            first = 0;
        }
        right--;
        if (left > right) break;

        for (int j = right; j >= left; --j) {
            if (!first) putchar(' ');
            printf("%d", a[bottom][j]);
            first = 0;
        }
        bottom--;
        if (top > bottom) break;

        for (int i = bottom; i >= top; --i) {
            if (!first) putchar(' ');
            printf("%d", a[i][left]);
            first = 0;
        }
        left++;
    }

    putchar('\n');

    for (int i = 0; i < r; ++i) free(a[i]);
    free(a);
    return 0;
}
