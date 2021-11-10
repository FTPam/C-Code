#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

//用辗转相除法递归求最大公约数
int gcp(int a, int b) {
	if (a <= 0 || b <= 0) {
		return -1;
	}
	if (a < b) {
		int t = a;
		a = b;
		b = t;
	}
	if (a % b != 0) {
		b = gcp(b, a % b);
	}
	return b;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcp(a, b));
}
