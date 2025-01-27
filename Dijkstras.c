#include<stdio.h>
#include<stdlib.h>
//s is visited and d is distance
int a[20][20],s[10],d[20],i,j,k,n,min,u,v;
void dijkstra()
{
    for(i=1;i<=n;i++)
    {
        s[i] = 0;
        d[i] = a[v][i];
    }
    s[v] = 1;
    d[v] = 0;
    for(k=2;k<=n;k++)
    {
        min = 999;
        for(i=1;i<=n;i++)
        {
            if(s[i]==0 && d[i]<min)
            {
                min = d[i];
                u = i;
            }
        }
        s[u] = 1;
        for(i=1;i<=n;i++)
        {
            if(s[i]==0)
            {
                if(d[i]>(d[u]+a[u][i]))
                {
                    d[i] = d[u] + a[u][i];
                }
            }
        }
    }
}
void main()
{

    printf("Enter the number of nodes in the graph: \n");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            a[i][j]=999;
        }
    }
    printf("Enter the source node: \n");
    scanf("%d",&v);
    dijkstra();
    printf("The shortest path from node %d is \n",v);
    for(i=1;i<=n;i++)
    {
        printf("%d -> %d = %d \n",v,i,d[i]);
    }
}