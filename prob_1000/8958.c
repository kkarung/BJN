#include <stdio.h>
#include <string.h>

int main(void) {
	int s, sum, n, k, i = 0;
	char a[80];
	
	scanf("%d", &n);
	while (n > i++) {
		scanf("%s", a);
		for (k = 0, sum = 0, s = 0; k < strlen(a); k++) {
			if (a[k] == 'O')
				sum += (++s);
			else
				s = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}
