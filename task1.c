#include <stdio.h>

int main()
{
	int n;
	char c;
	int i, j, k;

	scanf("%d ", &n);
	scanf("%c", &c);

	//primele n-1 linii ->

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < i; j++) {
			printf("  ");
		}
		for (k = 0; k < n - (i + 1); k++) {
			printf("%c ", c);
		}
		printf("%c\n", c);
	}

	//ultima linie ->

	for (i = 0; i < n - 1; i++)
		printf("  ");
	printf("%c\n", c);

    return 0;
}

