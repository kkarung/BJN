#include <stdio.h>
#define MAX 10000

int main(void) {
	int n, i, arr[MAX];
	int m = 0, sum = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] > m) {
			m = arr[i];
		}
	}

	printf("%f", (double)sum/m/n*100);
	return 0;
}
