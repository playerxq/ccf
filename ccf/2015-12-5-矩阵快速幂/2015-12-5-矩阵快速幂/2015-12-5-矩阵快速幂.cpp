// 2015-12-5-矩阵快速幂.cpp : 定义控制台应用程序的入口点。
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
int A[1005][1005];
int temp[1005][1005];
int b[1005];
int c[1005];
int m,n,k,st;
int ans[3][1005][1005];
void pow_m(long long n)
{
	if(n==1)
	{
		return;
	}
	pow_m(n/2);
	if((n/2)%2)
	{
		st = 0;//结果在ans[0]
	}
	else
		st = 1;//结果在ans[1]
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			ans[1-st][i][j] = ans[st][i][1]&ans[st][1][j];
			for(int k = 2;k<=m;k++)
			{
				ans[1-st][i][j] ^= (ans[st][i][k]&ans[st][k][j]); 
			}
		}
	}
	if(n&1)
    {
		if(st==0)
		{
			for(int i = 1;i<=m;i++)
			{
				for(int j = 1;j<=m;j++)
				{
					ans[0][i][j] = ans[1][i][1]&A[1][j];
					for(int k = 2;k<=m;k++)
					{
						ans[0][i][j] ^= (ans[1][i][k]&A[k][j]); 
					}
				}
			}
		}
		else
		{
			for(int i = 1;i<=m;i++)
			{
				for(int j = 1;j<=m;j++)
				{
					temp[i][j] = ans[0][i][1]&A[1][j];
					for(int k = 2;k<=m;k++)
					{
						temp[i][j] ^= (ans[0][i][k]&A[k][j]); 
					}
				}
			}
			for(int i = 1;i<=m;i++)
			{
				for(int j = 1;j<=m;j++)
					ans[0][i][j]=temp[i][j];
			}
		}
    }
	else
	{
		if(st==1)
		{
			for(int i = 1;i<=m;i++)
			{
				for(int j = 1;j<=m;j++)
					ans[1][i][j]=ans[0][i][j];
			}
		}
	}
	return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&m);
	char s[1005];
	getchar();
	for(int i = 1;i<=m;i++)
	{
		scanf("%s",s);
		for(int j = 0;j<strlen(s);j++)
		{
			A[i][j+1] = s[j]-'0';
		}
	}
	scanf("%s",s);
	for(int j = 0;j<strlen(s);j++)
		b[j+1]=s[j]-'0';
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&k);
		if(k==0)
			printf("%s\n",s);
		else
		{
			for(int x = 1;x<=m;x++)
			{
				for(int y = 1;y<=m;y++)
				{
					ans[0][x][y]=A[x][y];
				}
			}
			pow_m(k);
			if(k%2)
			{
				for(int x = 1;x<=m;x++)
				{
					c[x] = ans[0][x][1]&b[1];
					for(int y =2;y<=m;y++)
					{
						c[x] ^= (ans[0][x][y]&b[y]);
					}
				}
			}
			else
			{
				for(int x = 1;x<=m;x++)
				{
					c[x] = ans[1][x][1]&b[1];
					for(int y = 2;y<=m;y++)
					{
						c[x] ^= (ans[1][x][y]&b[y]);
					}
				}
			}
			for(int x = 1;x<=m;x++)
			{
				printf("%d",c[x]);
			}
			printf("\n");
		}
	}

}

