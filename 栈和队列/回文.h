#pragma once

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include "ջ.h"

int  sympthy(char str[], char s[])
{
    int i = 0, j, n;
    while (str[i] != '\0') i++; // ���ַ�����
    n = i;
    for (i = 0; i <= n / 2; i++) s[i] = str[i]; //ǰһ���ַ���ջ
    j = i;
    while (i < n && str[i] == s[j]) //�Ƚ��ַ����Ƿ��ǻ���
    {
        i++; j--;
    }
    if (i == n) printf("%s\n", "�ַ����ǻ���");
    else printf("%s\n", "�ַ������ǻ���");
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

