
#include <stdlib.h>
#include<stdio.h>
void main()
{
    int a[30][30], b[30][30];
    int i, j, M, N;
    printf("�����������:");
    scanf("%d", &M);
    printf("�����������:");
    scanf("%d", &N);
    for (i = 0; i < M; i++)
    {
        printf("������� %d ��Ԫ��", (i + 1));
        for (j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    }
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            b[j][i] = a[i][j];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            printf("%4d", b[i][j]);
        printf("\n");
    }
    system("pause");
}
