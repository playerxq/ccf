// 2015-12-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>  
#include<cstring>  
using namespace std;  
int main()  
{  
    int d[30][30];  
    int flag[30][30];  
    int n,m;  
    int i,j;  
    scanf("%d%d",&n,&m);  
    for(i=0;i<n;i++)  
        for(j=0;j<m;j++)  
            scanf("%d",&d[i][j]);  
    memset(flag,0,sizeof(flag));  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m;j++)  
        {  
            if(j-1>=0&&j+1<=m-1)  
            {  
                if(d[i][j-1]==d[i][j]&&d[i][j+1]==d[i][j])  
                    flag[i][j-1]=flag[i][j]=flag[i][j+1]=1;  
            }  
            if(i-1>=0&&i+1<=n-1)  
            {  
                if(d[i-1][j]==d[i][j]&&d[i+1][j]==d[i][j])  
                    flag[i-1][j]=flag[i][j]=flag[i+1][j]=1;  
            }  
        }  
    }  
    for(i=0;i<n;i++)  
    {  
        for(j=0;j<m-1;j++)  
        {  
            if(flag[i][j])  
                printf("0 ");  
            else  
                printf("%d ",d[i][j]);  
        }  
        if(flag[i][m-1])  
            printf("0\n");  
        else  
            printf("%d\n",d[i][m-1]);  
    }  
    return 0;  
}

