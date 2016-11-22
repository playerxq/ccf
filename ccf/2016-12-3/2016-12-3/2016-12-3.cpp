// 2016-12-3.cpp : 定义控制台应用程序的入口点。
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
struct suicong
{
	int h,a;
} sn[2][8];
int c[2];
int h[2];
int h1,a,p;
char cmd[7];
int w,cnt;
int f,e,st,de;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	memset(sn,0,sizeof(sn));
	h[0] = h[1] = 30;
	c[0] = c[1] = 0;
	w = 0;
	st = 0;
	while(n--)
	{
		scanf("%s",cmd);
		de = 1-st;
		if(cmd[0]=='s')
		{
			scanf("%d%d%d",&p,&a,&h1);
			if(p<=c[st])
			{
				for(int k = c[st];k>=p;k--)
				{
					sn[st][k+1].a = sn[st][k].a;
					sn[st][k+1].h = sn[st][k].h;
				}
			}
			c[st]++;
			sn[st][p].a = a;
			sn[st][p].h = h1;
		}
		else if(cmd[0]=='a')
		{
			scanf("%d%d",&f,&e);
			if(e!=0)
			{
				sn[st][f].h-=sn[de][e].a;
				sn[de][e].h-=sn[st][f].a;
				if(sn[st][f].h<=0)
				{
					for(int k = f+1;k<=c[st];k++)
					{
						sn[st][k-1].a = sn[st][k].a;
						sn[st][k-1].h = sn[st][k].h;
					}
					c[st]--;
				}
				if(sn[de][e].h<=0)
				{
					for(int k = e+1;k<=c[de];k++)
					{
						sn[de][k-1].a = sn[de][k].a;
						sn[de][k-1].h = sn[de][k].h;
					}
					c[de]--;
				}
			}
			else
			{
				h[de]-=sn[st][f].a;
				if(h[de]<=0)
				{
					if(de==0)
						w = -1;
					else
						w = 1;
				}
			}
		}
		else
		{
			st = 1-st;
		}
	}
	printf("%d\n",w);
	printf("%d\n",h[0]);
	if(c[0]==0)
		printf("0\n");
	else
	{
		printf("%d ",c[0]);
		for(int i = 1;i<=c[0];i++)
		{
			printf("%d",sn[0][i].h);
			if(i<c[0])
				printf(" ");
			else
				printf("\n");
		}
	}
	printf("%d\n",h[1]);
	if(c[1]==0)
		printf("0\n");
	else
	{
		printf("%d ",c[1]);
		for(int i = 1;i<=c[1];i++)
		{
			printf("%d",sn[1][i].h);
			if(i<c[1])
				printf(" ");
			else
				printf("\n");
		}
	}
}

