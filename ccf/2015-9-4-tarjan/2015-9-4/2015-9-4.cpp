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
vector<int> ve[10005];
int n,m;
int cnt,ans;
int low[10005],dfn[10005];
int top,index;
bool instack[10005];
int belong[10005],stack[10005];
void tarjan(int u)
{
	stack[top++] = u;
	instack[u] = 1;
	dfn[u]=low[u]=index++;
	for(int i = 0;i<ve[u].size();i++)
	{
		int v = ve[u][i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v])
		{
			low[u] = min(dfn[v],low[u]);
		}
	}
	if(low[u]==dfn[u])
	{
		cnt=0;
		int v;
		do{
			v = stack[--top];
			instack[v]=0;
			cnt++;
		}while(u!=v);
		ans+=((cnt-1)*cnt)/2;
	}
}
void init_tarjan()
{
	top = index = 0;
	for(int i = 1;i<=n;i++)
	{
		low[i]=dfn[i]=0;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) ve[i].clear();
	while(m--){  
        int x, y;  
        scanf("%d%d", &x, &y);  
        ve[x].push_back(y);  
    }
	init_tarjan();
	for(int i = 1;i<=n;i++)
	{
		if(!dfn[i])
			tarjan(i);
	}
	printf("%d\n",ans);
}