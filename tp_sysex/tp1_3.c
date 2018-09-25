#include <stdio.h>

int main(void)
{
	unsigned char u_char = 128;
	int _int = 384;
	printf("int : %d; char : %d\n", (int)u_char, (char)u_char);
	printf("char : %d; unsigned char : %d\n", (char)_int, (unsigned char)_int);
	printf("char : %d\n", (char)u_char);

	return 0;
}
