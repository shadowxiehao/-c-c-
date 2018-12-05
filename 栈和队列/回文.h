#pragma once

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include "栈.h"

int  sympthy(char str[], char s[])
{
    int i = 0, j, n;
    while (str[i] != '\0') i++; // 查字符个数
    n = i;
    for (i = 0; i <= n / 2; i++) s[i] = str[i]; //前一半字符入栈
    j = i;
    while (i < n && str[i] == s[j]) //比较字符串是否是回文
    {
        i++; j--;
    }
    if (i == n) printf("%s\n", "字符串是回文");
    else printf("%s\n", "字符串不是回文");
    return 1;
}

char reverse() {
    Stack *stack = initStack();

    char c1[100];
    scanf("%s", &c1);
    char c2[100];
    scanf("%s", &c2);
    
    sympthy(c1, c2);
}

