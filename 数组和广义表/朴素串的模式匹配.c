#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 256
typedef struct {
	char data[MAXSIZE];
	int length;
}strtp;



int SimpleMatch(strtp str1, strtp str2) {
	int i = 0, j = 0;

	while (i<str1.length && j<str2.length)
	{
		if (str1.data[i] == str2.data[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
		if (j == str2.length - 1){
			return i;
		}
	}
	return 0;
}

void main() {
	int p;
	strtp str1 = { "ababcabcacbab" ,13 };
	strtp str2 = { "bbcac" ,5 };
	p = SimpleMatch(str1, str2);
	printf("%d", p);
	system("pause");
}
