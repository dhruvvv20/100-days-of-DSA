#include <stdio.h>


long long pow_int(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		long long half = pow_int(a, b / 2);
		return half * half;
	} else {
		return a * pow_int(a, b - 1);
	}
}

double pow_double(double a, long long b) {
	if (b == 0) return 1.0;
	if (b % 2 == 0) {
		double half = pow_double(a, b / 2);
		return half * half;
	} else {
		return a * pow_double(a, b - 1);
	}
}

int main(void) {
	long long a, b;
	if (scanf("%lld %lld", &a, &b) != 2) return 0;

	if (b >= 0) {
		long long res = pow_int(a, b);
		printf("%lld\n", res);
	} else {
		double res = pow_double((double)a, -b);
		printf("%g\n", 1.0 / res);
	}

	return 0;
}

