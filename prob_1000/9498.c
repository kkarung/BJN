#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	if (n > 100 || n < 0) printf("올바르지 않은 숫자입니다.");
	else if (n >= 90) printf("A");
	else if (n >= 80) printf("B");
	else if (n >= 70) printf("C");
	else if (n >= 60) printf("D");
	else printf("F");

	return 0;
}
