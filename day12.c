#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m, n;
	if (scanf("%d %d", &m, &n) != 2) return 0;

	if (m != n) {
		// consume remaining input (optional) and print result
		for (int i = 0; i < m; ++i) {
			for (int j = 0, tmp; j < n; ++j) scanf("%d", &tmp);
		}
		printf("Not a Symmetric Matrix\n");
		return 0;
	}

	int size = m;
	int **a = malloc(size * sizeof(int*));
	if (!a) return 0;
	for (int i = 0; i < size; ++i) {
		a[i] = malloc(size * sizeof(int));
		if (!a[i]) return 0;
		for (int j = 0; j < size; ++j) scanf("%d", &a[i][j]);
	}

	int symmetric = 1;
	for (int i = 0; i < size && symmetric; ++i) {
		for (int j = i+1; j < size; ++j) {
			if (a[i][j] != a[j][i]) { symmetric = 0; break; }
		}
	}

	if (symmetric) printf("Symmetric Matrix\n");
	else printf("Not a Symmetric Matrix\n");

	for (int i = 0; i < size; ++i) free(a[i]);
	free(a);
	return 0;
}
