// 2014-9-4.cpp : 定义控制台应用程序的入口点。
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
#define maxn 1001  
typedef __int64 LL; 
struct P{  
    int x,y,step;  
    P(){}  
    P(int xx,int yy,int s){x=xx,y=yy,step=s;}  
}; 
int n,m,k,d,Map[maxn][maxn],mov[4][2]={{0,1},{0,-1},{1,0},{-1,0}};  
bool vis[maxn][maxn];  
queue<P>Q;
LL bfs()
{
	LL ans=0;  
    int cnt=0;
	while(!Q.empty())  
    {  
        P p=Q.front();Q.pop();  
        for(int i=0;i<4;++i){  
            P tem=p;  
            tem.x+=mov[i][0];  
            tem.y+=mov[i][1];  
            ++tem.step;  
            if(tem.x>0&&tem.y<=n&&tem.y>0&&tem.x<=n&&!vis[tem.x][tem.y])  
            {  
                vis[tem.x][tem.y]=1;  
                if(Map[tem.x][tem.y])  
                {  
                    ans+=Map[tem.x][tem.y]*tem.step;  
                    ++cnt;  
                    if(cnt==k) return ans;  
                }  
                Q.push(tem);  
            }  
        }  
    }  
    return -1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int x,y;  
    scanf("%d%d%d%d",&n,&m,&k,&d);  
    memset(Map,0,sizeof(Map));  
    memset(vis,0,sizeof(vis));  
    while(m--)  
    {  
        scanf("%d%d",&x,&y);  
        vis[x][y]=1;  
        Q.push(P(x,y,0));  
    }  
    for(int i=0;i<k;++i)  
    {  
        scanf("%d%d%d",&x,&y,&m);  
        Map[x][y]=m;  
    }  
    while(d--)  
    {  
        scanf("%d%d",&x,&y);  
        vis[x][y]=1;  
    }  
    cout<<bfs()<<endl;  
    return 0; 
}

