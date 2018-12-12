#include<stdio.h>
#define max 100


int creatcost(int cost[][max])
{
    int vexnum, arcnum, i, j, k, v1, v2;
    printf("\ninput the vexnum,arcnum:");
    scanf("%d,%d", &vexnum, &arcnum);
    for (i = 1; i <= vexnum; i++)
        for (j = 1; j <= vexnum; j++)
        {
            cost[i][j] = 0;
        }
    for (k = 0; k < arcnum; k++)
    {
        printf("v1,v2=");
        scanf("%d,%d", &v1, &v2);
        cost[v1][v2] = 1;
    }
    return vexnum;
}

int main()
{
    while (1) {
        int i, j, vexnum;
        int cost[max][max];
        vexnum = creatcost(cost);
        printf("the Adjacency Matrix is:\n");
        for (i = 1; i <= vexnum; i++)
        {
            for (j = 1; j <= vexnum; j++)
                printf("%3d", cost[i][j]);
            printf("\n");
        }
        system("pause");
    }
    return 0;
}
