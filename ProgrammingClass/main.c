#include <stdio.h>

int getPowerOf2() {
	static int num1 = 1;
	num1 = num1 * 2;
	return num1;
}

int main() {
	printf("%d\n", getPowerOf2());
	printf("%d\n", getPowerOf2());
	printf("%d\n", getPowerOf2());
	printf("%d\n", getPowerOf2());
	return 0;
}