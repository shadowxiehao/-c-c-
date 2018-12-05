
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ELEMTYPE;
// �����������ṹ��
typedef struct HuffmanTree
{
    ELEMTYPE weight;
    ELEMTYPE id;        // id������Ҫ��������Ȩֵ��ͬ�Ľ�㣬����������±�
    struct HuffmanTree* lchild;
    struct HuffmanTree* rchild;
}HuffmanNode;
// ������������
HuffmanNode* createHuffmanTree(int* a, int n)
{
    int i, j;
    HuffmanNode **temp, *hufmTree;
    temp = malloc(n * sizeof(HuffmanNode));
    for (i = 0; i < n; ++i)     // ������a�е�Ȩֵ��������е�weight
    {
        temp[i] = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        temp[i]->weight = a[i];
        temp[i]->id = i;
        temp[i]->lchild = temp[i]->rchild = NULL;
    }
    for (i = 0; i < n - 1; ++i)       // ��������������Ҫn-1�ϲ�
    {
        int small1 = -1, small2;      // small1��small2�ֱ���Ϊ��С�ʹ�СȨֵ���±�
        for (j = 0; j < n; ++j)         // �Ƚ���С�������±긳��small1��small2��ע�⣺��ӦȨֵδ����С��
        {
            if (temp[j] != NULL && small1 == -1)
            {
                small1 = j;
                continue;
            }
            else if (temp[j] != NULL)
            {
                small2 = j;
                break;
            }
        }
        for (j = small2; j < n; ++j)    // �Ƚ�Ȩֵ��Ų��small1��small2ʹ֮�ֱ��Ϊ��С�ʹ�СȨֵ���±�
        {
            if (temp[j] != NULL)
            {
                if (temp[j]->weight < temp[small1]->weight)
                {
                    small2 = small1;
                    small1 = j;
                }
                else if (temp[j]->weight < temp[small2]->weight)
                {
                    small2 = j;
                }
            }
        }
        hufmTree = (HuffmanNode*)malloc(sizeof(HuffmanNode));
        hufmTree->weight = temp[small1]->weight + temp[small2]->weight;
        hufmTree->lchild = temp[small1];
        hufmTree->rchild = temp[small2];
        temp[small1] = hufmTree;
        temp[small2] = NULL;
    }
    free(temp);
    return hufmTree;
}
// �Թ�������ʽ��ӡ��������
void PrintHuffmanTree(HuffmanNode* hufmTree)
{
    if (hufmTree)
    {
        printf("%d", hufmTree->weight);
        if (hufmTree->lchild != NULL || hufmTree->rchild != NULL)
        {
            printf("(");
            PrintHuffmanTree(hufmTree->lchild);
            printf(",");
            PrintHuffmanTree(hufmTree->rchild);
            printf(")");
        }
    }
}
// �ݹ���й���������
void HuffmanCode(HuffmanNode* hufmTree, int depth)      // depth�ǹ������������
{
    static int code[10];
    if (hufmTree)
    {
        if (hufmTree->lchild == NULL && hufmTree->rchild == NULL)
        {
            printf("idΪ%dȨֵΪ%d��Ҷ�ӽ��Ĺ���������Ϊ ", hufmTree->id, hufmTree->weight);
            int i;
            for (i = 0; i < depth; ++i)
            {
                printf("%d", code[i]);
            }
            printf("\n");
        }
        else
        {
            code[depth] = 0;
            HuffmanCode(hufmTree->lchild, depth + 1);
            code[depth] = 1;
            HuffmanCode(hufmTree->rchild, depth + 1);
        }
    }
}
// ����������
void HuffmanDecode(char ch[], HuffmanNode* hufmTree, char string[])     // ch��Ҫ�����01����string�ǽ���Ӧ���ַ�
{
    int i;
    int num[100];
    HuffmanNode* tempTree = NULL;
    for (i = 0; i < strlen(ch); ++i)
    {
        if (ch[i] == '0')
            num[i] = 0;
        else
            num[i] = 1;
    }
    if (hufmTree)
    {
        i = 0;      // �����ѽ���01���ĳ���
        while (i < strlen(ch))
        {
            tempTree = hufmTree;
            while (tempTree->lchild != NULL && tempTree->rchild != NULL)
            {
                if (num[i] == 0)
                {
                    tempTree = tempTree->lchild;
                }
                else
                {
                    tempTree = tempTree->rchild;
                }
                ++i;
            }
            printf("%c", string[tempTree->id]);     // ���������Ӧ�����ַ�
        }
    }
}
int main()
{
    while (1){
    int i, n;
    printf("������Ҷ�ӽ��ĸ�����\n");
    while (1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("�����������������nֵ��");
    }
    int* arr;
    arr = (int*)malloc(n * sizeof(ELEMTYPE));
    printf("������%d��Ҷ�ӽ���Ȩֵ��\n", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    getchar();
    fflush(stdin);      // ǿ����������е����ݣ�Ҳ������������Ȩֵ����ʱ�Ļس���
    char ch[100], string[100];
    printf("������������%d��Ҷ�ӽ�������������ַ���\n", n);
    gets(string);
    HuffmanNode* hufmTree = NULL;
    hufmTree = createHuffmanTree(arr, n);
    printf("�˹��������Ĺ������ʽΪ��\n");
    PrintHuffmanTree(hufmTree);
    printf("\n��Ҷ�ӽ��Ĺ���������Ϊ��\n");
    HuffmanCode(hufmTree, 0);
    printf("Ҫ���������������:\n");
    gets(ch);
    printf("������Ϊ��\n");
    HuffmanDecode(ch, hufmTree, string);
    printf("\n");
    free(arr);
    free(hufmTree);
    printf("\n");
    system("pause");
}
    return 0;
}
