// 2014-3-2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int map[2600][1500];
struct Node
{
	int x1,y1,x2,y2,num;
} win[15];
int ref[15];
int N,M,ind;
int x1,y1,x2,y2,x,y;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i = 1;i<=N;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		win[ind].x1 = x1;
		win[ind].y1 = y1;
		win[ind].x2 = x2;
		win[ind].y2 = y2;
		win[ind].num = i;
		for(int r = x1;r<=x2;r++)
		{
			for(int c = y1;c<=y2;c++)
			{
				map[r][c]=i;
			}
		}
		ref[i] = ind;
		ind++;
	}
	for(int i = 0;i<M;i++)
	{
		scanf("%d%d",&x,&y);
		if(map[x][y]==0)
			printf("IGNORED\n");
		else
		{
			printf("%d\n",map[x][y]);
			int p= map[x][y];
			int k = ref[map[x][y]];
			for(int i = win[k].x1;i<=win[k].x2;i++)
			{
				for(int j = win[k].y1;j<=win[k].y2;j++)
				{
					map[i][j] = p;
				}
			}
		}
	}
}

