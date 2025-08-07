#include <stdio.h>

void main()
{

	int a = 10;
	int* pa;
	pa = &a;

	/*printf("%d, %d\n", *pa, a);

	a = 20;

	printf("%d, %d", *pa, a);*/

	printf("&a: %u, pa: %u\n", &a, pa);
	printf("a: %d, *pa: %d\n", a, *pa);

	*pa = 20;
	printf("a:%d, *pa: %d\n", a, *pa);
	printf("pa+1 : %p\n", pa + 1);
	char c = 'a';
	pa = &c;
	printf("pa: %p, pa+1: %p\n", pa, pa + 1);
}