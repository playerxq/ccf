// 2015-12-4.cpp : 定义控制台应用程序的入口点。
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
int p[10005];
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int degree[10005],dep[10005],vis1[10005];
struct Edge
{
	int v,next,id;
	Edge(){}
	Edge(int vv, int n,int i): v(vv),next(n),id(i) {}
};
int n,m;
vector<int> v[10005];
bool vis[10005][10005];
vector<int> ve;
void init()
{
	memset(degree,0,sizeof(degree));
	memset(vis,0,sizeof(vis));
	ve.clear();
	for(int i = 1;i<=n;i++)
	{
		p[i]=i;
		dep[i]=0;
		vis1[i]=0;
	}
}
void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b)
		return;
	if(dep[a]>dep[b])
		p[b]=a;
	else
	{
		if(dep[a]==dep[b])
			dep[b]++;
		p[a]=b;
	}
	return;
}
void dfs(int s)
{
	for(int i = 0;i<v[s].size();i++)
	{
		if(vis[s][v[s][i]]==0)
		{
			vis[s][v[s][i]]=vis[v[s][i]][s]=1;
			dfs(v[s][i]);
			ve.push_back(v[s][i]);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	int a,b;
	for(int i = 0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		union_set(a,b);
		vis1[a]=vis1[b]=1;
		degree[a]++;
		degree[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)
		sort(v[i].begin(),v[i].end());
	int count = 0;
	for(int i = 1;i<=n;i++)
	{
		if(vis1[i]&&(p[i]==i))
			count++;
		else if(!vis1[i])
			count++;
	}
	if(count!=1)
	{
		printf("-1\n");
		return 0;
	}
	count = 0;
	for(int i = 1;i<=n;i++)
	{
		if(degree[i]%2)
		{
			count++;
		}
	}
	if(count!=0&&count!=2)
	{
		printf("-1\n");
		return 0;
	}
	if(count==2&&(degree[1]%2==0))
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		dfs(1);
		ve.push_back(1);
		while(!ve.empty())
		{
			printf("%d",ve.back());
			ve.pop_back();
			if(!ve.empty())
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

