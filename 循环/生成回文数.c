#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

//判断数字是否为回文数，最高支持64位整型
int isPal(int n) {
	int num[64], length;
	for (length = 0; n != 0; length++) {
		num[length] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < length/2; i++) {
		if (num[i] != num[length - i - 1]) {
			return 0;
		}
	}
	return 1;
}

//将十进制整数倒过来
int reverse(int n) {
	int num = 0;
	while (n != 0) {
		num = num * 10 + n % 10;
		n /= 10;
	}
	return num;
}

int main() {
	printf("please enter a number optionaly:");
	int num;
	scanf("%d", &num);
	printf("The generation process of palindrome:\n");
	for (int i = 1; !isPal(num); i++) {
		printf("   [%d]: %ld+%ld=%ld\n", i, num, reverse(num), num + reverse(num));
		num = num + reverse(num);
	}
	printf("Here we reached the aim at last !\n");
}
