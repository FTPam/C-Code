#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

//判断是否为回文数，最长支持64位整型
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

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", isPal(num));
}
