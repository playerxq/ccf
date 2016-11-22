// 2015-3-1.cpp : 定义控制台应用程序的入口点。
//
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
int n,m;
int map[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i = m;i>=1;i--)
	{
		for(int j = 1;j<=n;j++)
		{
			printf("%d ",map[j][i]);
		}
		printf("\n");
	}
}

