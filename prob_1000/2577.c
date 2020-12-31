#include <stdio.h>

int main(void) {
	int a, b, c, num, n, list[11] = {0,};

	scanf("%d %d %d", &a, &b, &c);
	num = a * b * c;
	do {
		n = num % 10;
		list[n]++;
	} while ((num /= 10) != 0);

	for (n = 0; n < 10; n++)
		printf("%d\n", list[n]);
}
