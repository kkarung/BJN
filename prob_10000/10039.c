#include <stdio.h>

int main(void) {
	int sum = 0, i, score;

	for (i = 0; i < 5; i++) {
		scanf("%d", &score);
		if (score < 40)
			sum += 40;
		else
			sum += score;
	}
	printf("%d", sum / 5);
}
