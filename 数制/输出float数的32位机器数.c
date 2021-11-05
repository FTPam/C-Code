#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	float input;
	int* p;
	p = &input;
	printf("Input a float number : \n");
	scanf("%f", &input);
	printf("%X", *p);
}
