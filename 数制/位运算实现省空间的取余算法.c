#pragma warning(disable:4996)
#include <stdio.h>

unsigned mod(unsigned a, unsigned b, unsigned c) {
	unsigned sum = a * ((b >> 30) & 1);
	for (int i = 29; i >= 0; i--) {
    //https://ask.csdn.net/questions/7557658?answer=53580358
    /*把sum计算行改成这样：
    sum = ((sum %c)<<1)%c + a * ((b >> i) & 1);
    测试结果是对了
    先求余，再 * 2，最后还要求余
    倍数乘任何数肯定还是倍数。所以用余数乘也可以。不过余数乘2以后可能会大于余数，所以还得再次求余*/
		sum = ((sum % c) << 1) % c + a * ((b >> i) & 1);
	}
	return sum % c;
}

int main() {
	unsigned a, b, c;
	printf("Input unsigned integer numbers a, b, c:\n");
	scanf("%u %u %u", &a, &b, &c);
	printf("%u*%u%%%u=%u\n", a, b, c, mod(a, b, c));
}
