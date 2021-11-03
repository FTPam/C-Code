#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	//由于二进制数用int型存储空间浪费很大
	//所以用数组来存储每一位的数值
	int input[100], length = 0, q = 1;
	char ichar;
	int dec = 0, oct = 0, hex = 0;
	printf("Input a binary number:\n");
	//将二进制数读入数组
	ichar = getchar();
	for (length = 0; ichar != '\n'; length++) {
		input[length] = ichar - 48;
		ichar = getchar();
	}
	//二进制转十进制
	for (int i = length - 1; i >= 0; i--) {
		dec = dec + input[i] * q;
		q = q * 2;
	}
	q = 1;
	//二进制转八进制
	for (int i = 0; i < length % 3; i++) {
		oct = input[i] * q;
		q = q * 2;
	}
	for (int i = length % 3; i * 3 < length; i++) {
		oct = oct * 10 + input[i * 3] * 4 + input[i * 3 + 1] * 2 + input[i * 3 + 2];
	}
	q = 1;
	printf("The number is %d in decimal\n", dec);
	printf("The number is %d in octal\n", oct);
	printf("The number is "); 
	//二进制转十六进制
	if (length % 4 != 0) {
		for (int i = 0; i < length % 4; i++) {
			hex = input[i] * q;
			q = q * 2;
		}
		if (hex > 9) {
			printf("%c", hex - 10 + 65);
		}
		else {
			printf("%d", hex);
		}
	}
	
	for (int i = length % 4; i * 4 < length; i++) {
		hex = input[i * 4] * 8 + input[i * 4 + 1] * 4 + input[i * 4 + 2] * 2 + input[i * 4 + 3];
		if (hex > 9) {
			printf("%c", hex - 10 + 65);
		}
		else {
			printf("%d", hex);
		}
	}
	printf("in hexadecimal\n");
}
