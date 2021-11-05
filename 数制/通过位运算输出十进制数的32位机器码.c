#pragma warning(disable:4996)
#include <stdio.h>

void DecToBin(int a, char b[33]) {
	int output, fan = 1;
	for (int i = 0; i < 32; i++) {
		//把第i位数字移动到末尾
		output = a >> (31 - i);
		//与1进行与运算
		output = output & fan;
		b[i] = output + 48;
	}
	b[32] = '\0';
}

int main() {
	char b[33];
	int a;
	scanf("%d", &a);
	DecToBin(a, b);
	printf("%s", b);
}

