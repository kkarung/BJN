#include <stdio.h>

int main(void) {
	int word[27] = { 0 }, c, i;
	int maxi = 0, maxv = 0;

	while ((c = getchar()) != '\n') {
		if (c >= 97 && c <= 122)
			i = c - 97;
		else if (c >= 65 && c <= 90)	
			i = c - 65;
		
		word[i]+=1;

		if (maxv < word[i]) {
			maxi = i;
			maxv = word[i];
		}
		else if (maxv == word[i])
			maxi = -2;
	}

	printf("%c", maxi+65);
}
