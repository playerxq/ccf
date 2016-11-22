// 2016-4-4.cpp : 定义控制台应用程序的入口点。
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
int n,m,t;
int r,c,a,b; 
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
struct posdata{  
    int time;  
    int newtime;  
    int dmin;  
    int dmax;  
}; 
posdata data[100+1][100+1];
#define isDanger(a,b,t) (data[a][b].dmin<=t&&data[a][b].dmax>=t)  
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,j;  
    int ntime; 
	scanf("%d%d%d",&n,&m,&t); 
	for(i=1;i<n+1;++i) 
	{
        for(j=1;j<m+1;++j)  
		{
			posdata a;
			a.dmax = a.dmin = a.newtime = a.time = -1;
			data[i][j]=a;
		}
	}
	for(i=0;i<t;++i){  
        scanf("%d%d%d%d",&r,&c,&a,&b);  
		posdata a1;
		a1.dmax = b;
		a1.dmin = a;
		a1.newtime = -1;
		a1.time = -1;
        data[r][c]=a1; 
    }
	data[1][1].time = 0;
	for(ntime=0;ntime<1000;++ntime)
	{
		for(i=1;i<n+1;++i)
		{
			for(j=1;j<m+1;++j)
			{
				if(data[i][j].time==ntime)
				{
					if(i!=n&&!isDanger(i+1,j,ntime+1))
					{
						data[i+1][j].newtime = ntime+1;
					}
					if(j!=m&&!isDanger(i,j+1,ntime+1))
					{
						data[i][j+1].newtime = ntime+1;
					}
					if(i!=1&&!isDanger(i-1,j,ntime+1))
					{
						data[i-1][j].newtime = ntime+1;
					}
					if(j!=1&&!isDanger(i,j-1,ntime+1))
					{
						data[i][j-1].newtime = ntime+1;
					}
				}
			}
		}
		for(i=1;i<n+1;++i)  
			for(j=1;j<m+1;++j)  
				data[i][j].time = data[i][j].newtime;
		if(data[n][m].time!=-1)  
			break;
	}
	printf("%d",ntime+1);
}

