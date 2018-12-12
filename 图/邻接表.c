
#include<stdio.h>
#include<malloc.h>
#include <windows.h>
#define max 100     
typedef struct node
{
    int adjvex;
    struct node*next;
}arcnode;
typedef struct
{
    int vertex;
    arcnode*firstarc;
}vexnode;
vexnode adjlist[max];
int creatadjlist()
{
    arcnode*ptr;
    int arcnum, vexnum, k, v1, v2;
    printf("input the vexnum,arcnum:");
    scanf("%d,%d", &vexnum, &arcnum);
    for (k = 1; k <= vexnum; k++)
        adjlist[k].firstarc = 0;
    for (k = 0; k < arcnum; k++)
    {
        printf("v1,v2=");
        scanf("%d,%d", &v1, &v2);
        ptr = (arcnode*)malloc(sizeof(arcnode));/*ºËÐÄ........*/
        ptr->adjvex = v2;
        ptr->next = adjlist[v1].firstarc;
        adjlist[v1].firstarc = ptr;
        ptr = (arcnode*)malloc(sizeof(arcnode));
        ptr->adjvex = v1;
        ptr->next = adjlist[v2].firstarc;
        adjlist[v2].firstarc = ptr;         /*.....   ºËÐÄ*/
    }
    return vexnum;
}
int main()
{
    while (1) {
        int i, n;
        arcnode*p;
        n = creatadjlist();
        printf("the Adjacency List:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d=>", i);
            p = adjlist[i].firstarc;
            while (p != NULL)
            {
                printf("---->%d", p->adjvex);
                p = p->next;
            }
            putchar('\n');
        }
        system("pause");
    }
    return 0;
}
