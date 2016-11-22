// 2015-12-3.cpp : 定义控制台应用程序的入口点。
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
char map[105][105];
int vis[105][105];
int n,m,q,c;
char ch;
int xa,ya,xb,yb,x,y;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void init()
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
			map[i][j]='.';
	}
}
int ok(int x , int y)
{
	if(x>=0&&x<n&&y>=0&&y<m&&((map[x][y]!='-')&&(map[x][y]!='|')&&(map[x][y]!='+')))
		return 1;
	return 0;
}
void dfs(int x, int y)
{
	if(vis[x][y])
		return;
	vis[x][y]=1;
	map[x][y]=ch;
	for(int i = 0;i<4;i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(map[nx][ny]==ch)
			continue;
		if(ok(nx,ny))
			dfs(nx,ny);
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d%d",&m,&n,&q);
	init();
	for(int i = 0;i<q;i++)
	{
		scanf("%d",&c);
		if(c==0)
		{
			scanf("%d%d%d%d",&ya,&xa,&yb,&xb);
			xa = n-1-xa;
			xb = n-1-xb;
			if(ya==yb)
			{
				int st = min(xa,xb);
				int ed = max(xa,xb);
				for(int k = st;k<=ed;k++)
				{
					if(map[k][ya]!='-'&&map[k][ya]!='+')
						map[k][ya]='|';
					else
						map[k][ya]='+';
				}
			}
			else
			{
				int st = min(ya,yb);
				int ed = max(ya,yb);
				for(int k = st;k<=ed;k++)
				{
					if(map[xa][k]!='|'&&map[xa][k]!='+')
						map[xa][k]='-';
					else
						map[xa][k]='+';
				}
			}
		}
		else
		{
			scanf("%d%d",&y,&x);
			x = n-1-x;
			scanf(" %c",&ch);
			memset(vis,0,sizeof(vis));
			dfs(x,y);
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

