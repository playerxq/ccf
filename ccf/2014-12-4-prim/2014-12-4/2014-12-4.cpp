// 2014-12-4.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int f[1005];
const int maxx = 0x3f3f3f3f;
int n,m,id,minx,sum;
int used[1005];
int map[1005][1005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			map[i][j]=maxx;
	for(int i = 1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		map[u][v]=c;
		map[v][u]=c;
	}
	for(int i = 2;i<=n;i++)
	{
		if(map[1][i])
		{
			f[i]=map[1][i];
		}
		else
			f[i]=maxx;
	}
	used[1]=1;
	int k;
	for(int i = 2;i<=n;i++)
	{
		minx=maxx;
		for(int j=1;j<=n;j++)
		{
			if(!used[j]&&f[j]<minx)
			{
				minx=f[j];k=j;
			}
		}
		used[k]=1;sum+=f[k];
		for(int j=1;j<=n;j++)
		{
			if(!used[j]&&(f[j]>map[k][j]))
			{
				f[j]=map[k][j];
			}
		}
	}
	printf("%d\n",sum);
}

