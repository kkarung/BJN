#include <stdio.h>

int sumFunction(int);
int seed, i;

int main(void) {
	scanf("%d", &seed);
	sumFunction(seed);
}

int sumFunction(int n) {
	int a, b, sum, d;
	i++;
	a = n / 10; b = n % 10;
	sum = a + b; d = sum % 10;
	sum = 10*b + d;
	if (sum == seed) printf("%d", i);
	else sumFunction(sum);
}
