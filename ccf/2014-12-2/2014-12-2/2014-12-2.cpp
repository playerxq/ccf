// 2014-12-2.cpp : 定义控制台应用程序的入口点。
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
int n;
int map[505][505];
int flag[505][505];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	int cnt = n*n;
	int sx = 1;
	int sy = 1;
	while(cnt--)
	{
		printf("%d",map[sx][sy]);
		flag[sx][sy]=1;
		if(cnt)
			printf(" ");
		else
			printf("\n");
		if(sx==1&&sy==1)
		{
			sy++;
		}
		else if(sx==1)
		{
			if(flag[sx+1][sy-1]==0)
			{
				sx++;
				sy--;
			}
			else
			{
				if(sy==n)
					sx++;
				else
					sy++;
			}
		}
		else if(sy==1)
		{
			if(flag[sx-1][sy+1]==0)
			{
				sx--;
				sy++;
			}
			else
			{
				if(sx==n)
				{
					sy++;
				}
				else
				{
					sx++;
				}
			}
		}
		else if(sx==n)
		{
			if(flag[sx-1][sy+1]==0)
			{
				sx--;
				sy++;
			}
			else
			{
				if(sy==n)
					break;
				else
				{
					sy++;
				}
			}
		}
		else if(sy==n)
		{
			if(flag[sx+1][sy-1]==0)
			{
				sx++;
				sy--;
			}
			else
			{
				if(sx==n)
					break;
				else
				{
					sx++;
				}
			}
		}
		else
		{
			if(flag[sx-1][sy+1]==0)
			{
				sx--;
				sy++;
			}
			else
			{
				sx++;
				sy--;
			}
		}
	}
}

