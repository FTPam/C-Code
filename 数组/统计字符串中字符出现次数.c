#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char a[100];
	gets(a);
	for (int i = 97; i <= 122; i++) {
		int count = 0;
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] == (char)i) {
				count++;
			}
		}
		if (count) {
			printf("%c=%d\n", i, count);
		}
	}
}
