#include <stdio.h>
#define MAX 1000

int main(void) {
	int c, n, i, j, N, arr[MAX];
	double ave, res[MAX];

	scanf("%d", &c);
	for (i = 0; i < c; i++) {
		N = 0;
		ave = 0;
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
			ave += arr[j];
		}
		ave /= n;

		for (j = 0; j < n; j++) {
			if (arr[j] > ave)
				N += 1;
		}
		res[i] = (double)N / n * 100;
	}
	for (i = 0; i < c; i++)
		printf("%.3f%%\n", res[i]);
}
