#include <stdio.h>
#include <stdlib.h>
void merge_logs() {
    int p, q;
    if (scanf("%d", &p) != 1) return;
    int *server1 = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++) scanf("%d", &server1[i]);
    if (scanf("%d", &q) != 1) return;
    int *server2 = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) scanf("%d", &server2[i]);
    int i = 0, j = 0;
    while (i < p && j < q) {
        if (server1[i] <= server2[j]) {
            printf("%d ", server1[i++]);
        } else {
            printf("%d ", server2[j++]);
        }
    }
    while (i < p) printf("%d ", server1[i++]);
    while (j < q) printf("%d ", server2[j++]);
    printf("\n");
    free(server1);
    free(server2);
}
int main() {
    merge_logs();
    return 0;
}
