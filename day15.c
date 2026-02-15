#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    int min_dim = (m < n) ? m : n;
    for(int i = 0; i < min_dim; i++) {
        sum += matrix[i][i];
    }
    
    printf("%d\n", sum);
    return 0;
}
