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
struct node
{
	int id,d;
};
vector<int > map[20002];
int mark[20002];
int n,m;
int bfs(int s, int& nn)
{
	queue<node> Q;
	node st,next;
	st.id=s;
	st.d=0;
	Q.push(st);
	while(!Q.empty())
	{
		node cur = Q.front();
		Q.pop();
		int len = map[cur.id].size();
		for(int i = 0;i<len;i++)
		{
			if(!mark[map[cur.id][i]])
			{
				mark[map[cur.id][i]]=1;
				nn =  map[cur.id][i];
				next.id=nn;
				next.d=cur.d+1;
				Q.push(next);
			}
		}
	}
	return next.d;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	int u;
	for(int i = 2;i<=n;i++)
	{
		scanf("%d",&u);
		map[u].push_back(i);
		map[i].push_back(u);
	}
	for(int i = n+1;i<=n+m;i++)
	{
		scanf("%d",&u);
		map[u].push_back(i);
		map[i].push_back(u);
	}
	int a,b;
	bfs(1,a);
	memset(mark,0,sizeof(mark));
	printf("%d\n",bfs(a,b));
}