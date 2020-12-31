#include <stdio.h>

int main(void) {
	int i, j, temp, arr[1000] = {0, }, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
