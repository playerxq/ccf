// 2016-4-5-bfs.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = 500 + 5;
const int MAXP = 6 + 5;

int T, N, M, P, res;
char buf[MAXN];
int usr[MAXN], usr_cnt;
struct Krustal {
    struct Edge {
        int u, v, w;
        Edge() {}
        Edge (int u, int v, int w) : u (u), v (v), w (w) {}
        bool operator < (const Edge& e) const {
            return w < e.w;
        }
    } edges[MAXN * MAXP];
    int par[MAXN], tot;
    void init() {
        tot = 0;
    }
    int Find (int x) {
        return -1 == par[x] ? x : (par[x] = Find (par[x]) );
    }
    void add_edge (int u, int v, int w) {
        edges[tot ++] = Edge (u, v, w);
    }
    int Kruskal() {
        memset (par, -1, sizeof (par) );
        int u, v, w, pu, pv, cnt = 0, ret = 0;
        sort (edges, edges + tot);
        for (int i = 0; i < tot; i++) {
            if (cnt == usr_cnt - 1) break;
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            pu = Find (u), pv = Find (v);
            if (pu == pv) continue;
            par[pv] = pu;
            ret += w;
            cnt ++;
        }
        return ret;
    }
} mst ;
struct Dijistra
{
	struct Edge {
        int v, w, next;
        Edge() {}
        Edge (int v, int w, int next) : v (v), w (w), next (next) {}
    } edges[MAXN * MAXP * 2];
	struct QNode
	{
		int u,w;
		QNode () {}
		QNode (int u,int w): u(u),w(w) {}
		bool operator >(const QNode& e) const 
		{
			return w>e.w;
		}
	} cur;
	int head[MAXN], tot;
    int dist[MAXN];
    bool vis[MAXN];
    priority_queue<QNode, vector<QNode>, greater<QNode> > Q;
	void init() {
        tot = 0;
        memset (head, -1, sizeof (head) );
        memset (dist, 0x3f, sizeof (dist) );
        memset (vis, false, sizeof (vis) );
    }
	void add_edge (int u, int v, int w) {
        edges[tot] = Edge (v, w, head[u]);
        head[u] = tot ++;
    }
	int dijistr(int src, int dis)
	{
		int u,v,w;
		Q.push(QNode(src,dist[src] = 0));
		while(!Q.empty())
		{
			cur = Q.top();
			Q.pop();
			u = cur.u;
			if(vis[u])
				continue;
			vis[u] = 1;
			for(int i = head[u];~i;i = edges[i].next)
			{
				v = edges[i].v, w = edges[i].w;
                if (!vis[v] && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    Q.push (QNode (v, dist[v]) );
                }
			}
		}
		return dist[dis];
	}
} dij;
int solve() {
    int u, v, w;
    if (usr_cnt == N) {
        mst.init();
        for (int i = 1; i <= M; i++) {
            scanf ("%d %d %d", &u, &v, &w);
            mst.add_edge (u, v, w);
        }
        return mst.Kruskal();
    } else if (usr_cnt == 2) {
        dij.init();
        for (int i = 1; i <= M; i++) {
            scanf ("%d %d %d", &u, &v, &w);
            dij.add_edge (u, v, w);
            dij.add_edge (v, u, w);
        }
        return dij.dijistr (usr[0], usr[1]);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf ("%d", &T);
    while (T --) {
        usr_cnt = 0;
        scanf ("%d %d %d", &N, &M, &P);
        scanf ("%s", buf + 1);
        for (int i = 1; i <= N; i++) {
            if (buf[i] == '1') usr[usr_cnt ++] = i;
        }
        res = solve();
        printf ("%d\n", res);
    }
}

