// 2016-12-4-dijistra.cpp : 定义控制台应用程序的入口点。
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
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int MAXN = 10000 + 5;
const int MAXM = 100000 + 5;
struct edge
{
	int v,next,w;
	edge() {}
	edge(int v1, int next1, int w1)
	{
		v = v1;
		next = next1;
		w = w1;
	}
};
edge ed[1000050];
int head[MAXN];
int ed_ind,n,m;
void init() {
    ed_ind = 0;
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int w) {
    ed[ed_ind] = edge(v, head[u], w);
    head[u] = ed_ind ++;
}
struct Node
{
	int u,cost;
	Node() {}
    Node(int u, int cost) : u(u), cost(cost) {}
    friend bool operator < (struct Node a, struct Node b)
	{
		return b.cost<a.cost;
	}
} cur;
priority_queue<Node> Q;
int cost[MAXN];
bool vis[MAXN];
void Q_init() {
    while(!Q.empty()) Q.pop();
    memset(vis, false, sizeof(vis));
    memset(cost, 0x3f, sizeof(cost));
}
void dijistr()
{
	int u,v,w;
	Q.push(Node(1,cost[1]=0));
	while(!Q.empty())
	{
		cur = Q.top();
        Q.pop();
        u = cur.u;
        if(vis[u]) continue;
        vis[u] = true;
		for(int i = head[u];~i;i = ed[i].next)
		{
			v = ed[i].v;
			w = ed[i].w;
			if(!vis[v]&&w+cost[u]<cost[v])
				Q.push(Node(v,cost[v]=cost[u]+w));
		}
	}
}
int minx[MAXN];
queue<int> Que;
int get_ans()
{
	int u,v,w;
	memset(minx, 0x3f, sizeof(minx));
	Que.push(1);
    minx[1] = 0;
	while(!Que.empty()) {
        u = Que.front();
        Que.pop();
        for(int i = head[u]; ~i; i = ed[i].next)  {
            v = ed[i].v, w = ed[i].w;
            if(cost[v] == cost[u] + w) {
                minx[v] = min(minx[v], w);
                Que.push(v);
            }
        }
    }
	int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += minx[i];
    }
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int u, v, w, ans;
    while(~scanf("%d %d", &n, &m)) {
        init();
        for(int i = 1; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        Q_init();
        dijistr();
        ans = get_ans();
        printf("%d\n", ans);
    }
    return 0;
}

