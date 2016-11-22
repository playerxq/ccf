// 2016-12-5.cpp : 定义控制台应用程序的入口点。
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
int n,q;
struct point
{
	int x,y;
} p[300001];
int headx[300001];
int nextx[300001];
int heady[300001];
int nexty[300001];
int vis[300001];
int cx[300001];
int cy[300001];
int ind;
int judge[300001];
int Hash(int s)
{
    int seed = (s >> 1) + (s << 1);
    return (seed & 0x7FFFFFFF) % 300001;
}
int insert_x(int s, int y)
{
    int h = Hash(s);
	cx[h]++;
    int u = headx[h];
	int pre = -1;
	while(u!=-1&&p[u].y<y)
	{
		pre = u;
		u = nextx[u];
	}
	if(pre==-1)
	{
		nextx[ind] = u;
		headx[h] = ind;
	}
	else if(u==-1)
	{
		nextx[pre] = ind;
	}
	else
	{
		nextx[pre] = ind;
		nextx[ind] = u;
	}
    return 1;
}
int insert_y(int s, int x)
{
    int h = Hash(s);
	cy[h]++;
    int u = heady[h];
    int pre = -1;
	while(u!=-1&&p[u].x<x)
	{
		pre = u;
		u = nexty[u];
	}
	if(pre==-1)
	{
		nexty[ind] = u;
		heady[h] = ind;
	}
	else if(u==-1)
	{
		nexty[pre] = ind;
	}
	else
	{
		nexty[pre] = ind;
		nexty[ind] = u;
	}
    return 1;
}
int find_x(int y)
{
	if(judge[Hash(y)])
		return 1;
	return 0;
}

int maxx;
int le,ri,us,dx;
int calc(int l, int u, int x)
{
	int tt = -1;
	for(int i = l+1;i<u;i++)
	{
		le = ri = us = dx = 0;
		if(find_x(i))
			continue;
		int s = Hash(i);
		int u = heady[s];
		while(u!=-1)
		{
			if(p[u].x<x)
				le++;
			else
				break;
			u = nexty[u];
		}
		ri = cy[s]-le;
		s = Hash(x);
		u = headx[s];
		while(u!=-1)
		{
			if(p[u].y<i)
				dx++;
			else
				break;
			u = nextx[u];
		}
		us = cx[s]-dx;
		int t = min(le,min(ri,min(dx,us)));
		if(t>tt)
			tt = t;
	}
	return tt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&q);
	int x,y,cnt;
	memset(headx,-1,sizeof(headx));
	memset(heady,-1,sizeof(heady));
	memset(nextx,-1,sizeof(nextx));
	memset(nexty,-1,sizeof(nexty));
	memset(vis,0,sizeof(vis));
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	while(n--)
	{
		scanf("%d%d",&x,&y);
		p[ind].x=x;
		p[ind].y = y;
		insert_x(x,y);
		insert_y(y,x);
		ind++;
	}
	maxx = -1;
	cnt = 0;
	for(int i = 0;i<ind;i++)
	{
		int k = Hash(p[i].x);
		if(vis[k]==0)
		{
			memset(judge,0,sizeof(judge));
			vis[k]=1;
			int lo = p[headx[k]].y;
			int uo = lo;
			int u = headx[k];
			while(u!=-1)
			{
				judge[Hash(p[u].y)]=1;
				if(p[u].y>uo)
					uo = p[u].y;
				if(p[u].y<lo)
					lo = p[u].y;
				u = nextx[u];
			}
			int temp = calc(lo,uo,p[i].x);//这条X轴的最大层数
			if(temp==maxx)
				cnt++;//又找到一个最大的
			else if(temp>maxx)
			{
				maxx = temp;
				cnt = 1;
			}
		}
	}
	if(q==1)
		printf("%d\n",maxx);
	else
		printf("%d\n",cnt);
}
