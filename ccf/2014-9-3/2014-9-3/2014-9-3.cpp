// 2014-9-3.cpp : 定义控制台应用程序的入口点。
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
char a[105];
char b[105];
int p[105];
int m,n,q;
void get_P()
{
	int i = 2;
	p[1] = 0;
	int j = 0;
	for(;i<=m;i++)
	{
		if(q==1)
		{
			while(j>0&&b[j+1]!=b[i])
				j=p[j];
			if(b[i]==b[j+1])
			{
				j++;
				p[i] = j;
			}
		}
		else
		{
			while(j>0&&toupper(b[j+1])!=toupper(b[i]))
				j=p[j];
			if(toupper(b[j+1])==toupper(b[i]))
			{
				j++;
				p[i] = j;
			}
		}
	}
}
int kmp()
{
	int j = 0;
	int i = 1;
	for(;i<=n;i++)
	{
		if(q==1)
		{
			while(j>0&&a[i]!=b[j+1])
				j = p[j];
			if(a[i]==b[j+1])
				j++;
			if(j==m)
			{
				return 1;
			}
		}
		else
		{
			while(j>0&&toupper(b[j+1])!=toupper(a[i]))
				j = p[j];
			if(toupper(b[j+1])==toupper(a[i]))
				j++;
			if(j==m)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	scanf("%s",b+1);
	m = strlen(b+1);
	get_P();
	scanf("%d",&q);
	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		scanf("%s",a+1);
		n = strlen(a+1);
		if(kmp())
			printf("%s\n",a+1);
	}
}

