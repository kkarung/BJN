#include <stdio.h>

int main(void) {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	

	if (a > b) {
		if (b > c) printf("%d", b);//a>b>c

		else {//a>b, c>=b
			if (a > c) printf("%d", c);//a>c>=b
			else printf("%d", a);//c>=a>b
		}
	}

	else {//b>=a
		if (a > c) printf("%d", a);//b>=a>c

		else {//b>=a, c>=a
			if (b > c) printf("%d", c);//b>c>=a
			else printf("%d",b);//c>=b>=a
		}

	}
	
	return 0;
}
