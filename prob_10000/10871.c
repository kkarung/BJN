#include <stdio.h>
#define MAX 10000

int main(void) {
	int n, arr[MAX], i;

	scanf("%d", &n);

	for (i = 0; i <= n;i++) {
		scanf("%d", &arr[i]);//
		if (arr[i] < arr[0]) {
			printf("%d ", arr[i]);
		}
	}

	return 0;
}
