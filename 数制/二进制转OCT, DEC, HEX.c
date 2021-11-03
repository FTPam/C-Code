#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	//由于二进制数用int型存储空间浪费很大
	//所以用数组来存储每一位的数值
	int input[100], length = 0;
	char ichar;
	long int dec = 0, oct = 0, hex = 0;
	printf("Input a binary number:\n");
	//将二进制数读入数组
	ichar = getchar();
	for (length = 0; ichar != '\n'; length++) {
		input[length] = ichar - 48;
		ichar = getchar();
	}
	//二进制转十进制
	for (int i = length - 1, q = 1; i >= 0; i--) {
		dec = dec + input[i] * q;
		q = q * 2;
	}
	printf("The number is %d in decimal\n", dec);
	//二进制转八进制
	//思路是每3个数字为一组，每次处理一组
	//当数字个数不为3的整倍数时，先处理多出来的部分，再处理剩下的部分
	printf("The number is ");
	if (length % 3 != 0) {
		for (int i = length % 3 - 1, q = 1; i >= 0; i--) {
			oct = oct + input[i] * q;
			q = q * 2;
		}
		printf("%d", oct);
	}
	for (int i = length % 3; i < length; i = i + 3) {
		printf("%d", input[i] * 4 + input[i + 1] * 2 + input[i + 2]);
	}
	printf(" in octal\n");
	printf("The number is "); 
	//二进制转十六进制
	//思路是每4位一个组，每次处理一个组
	//当数字个数不为4的整倍数时，先处理多出来的部分，再处理剩下的部分
	if (length % 4 != 0) {
		for (int i = length % 4 - 1, q = 1; i >= 0; i--) {
			hex = hex + input[i] * q;
			q = q * 2;
		}
		if (hex > 9) {
			printf("%c", hex - 10 + 65);
		}
		else {
			printf("%d", hex);
		}
	}
	for (int i = length % 4; i < length; i = i + 4) {
		hex = input[i] * 8 + input[i + 1] * 4 + input[i + 2] * 2 + input[i + 3];
		if (hex > 9) {
			printf("%c", hex - 10 + 65);
		}
		else {
			printf("%d", hex);
		}
	}
	printf(" in hexadecimal\n");
}
