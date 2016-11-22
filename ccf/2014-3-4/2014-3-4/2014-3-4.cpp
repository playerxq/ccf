// 2014-3-4.cpp : 定义控制台应用程序的入口点。
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
#define eps 1e-8 
int n,m,k;
long long r;
int head[205];
struct Edge {
    int v, next;
    Edge() {}
    Edge (int v, int next) : v (v), next (next) {}
} edges[205 * 205 * 2];
int tot;
struct Node
{
	long long x,y;
	int cnt;//1号到当前号已经经过的中转数目
	int num;//m个空位中已经占有的数目
	int id;
	Node () {}
	Node(long long xx, long long yy, int c ,int n, int i):x(xx),y(yy),cnt(c),num(n), id(i){}
	bool operator > (const Node& b) const
	{
		return cnt>b.cnt;
	}
} cur;
void add_edge (int u, int v) {
    edges[tot] = Edge (v, head[u]);
    head[u] = tot ++;
}
struct P
{
	long long x,y;
};
P pp[205];
priority_queue<Node, vector<Node>, greater<Node> > Q;
long long stx,sty,edx,edy;
int vis[205];
int dist[205];
int bfs()
{
	Q.push(Node(stx,sty,0,0,0));
	dist[0]=0;
	while(!Q.empty())
	{
		cur = Q.top();
		Q.pop();
		if(vis[cur.id]==1)
			continue;
		vis[cur.id]=1;
		for(int i = head[cur.id];~i;i=edges[i].next)
		{
			int v = edges[i].v;
			if(vis[v]==0&&dist[v]>dist[cur.id]+1)
			{
				if(v>=n&&cur.num>=k)
					continue;
				else
				{
					dist[v]=dist[cur.id]+1;
					if(v>=n)
					{
						Q.push(Node(pp[i].x,pp[i].y,cur.cnt+1,cur.num+1,v));
					}
					else
					{
						Q.push(Node(pp[i].x,pp[i].y,cur.cnt+1,cur.num,v));
					}
				}
			}
		}
	}
	return dist[1]-1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d%d%lld",&n,&m,&k,&r);
	long long x,y;
	for(int i = 0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		pp[i].x=x;
		pp[i].y=y;
		if(i==0)
		{
			stx=x;
			sty=y;
		}
		else if(i==1)
		{
			edx=x;
			edy=y;
		}
	}
	for(int i = n;i<n+m;i++)
	{
		scanf("%lld%lld",&x,&y);
		pp[i].x=x;
		pp[i].y=y;
	}
	memset(vis,0,sizeof(vis));
	memset (dist, 0x3f, sizeof (dist) );
	memset (head, -1, sizeof (head) );
	for(long long i = 0;i<m+n;i++)
	{
		for(long long j = i;j<m+n;j++)
		{
			if((pp[i].x-pp[j].x)*(pp[i].x-pp[j].x)+(pp[i].y-pp[j].y)*(pp[i].y-pp[j].y) <= r*r)
			{
				add_edge(i,j);
				add_edge(j,i);
			}
		}
	}
	printf("%lld\n",bfs());
}
