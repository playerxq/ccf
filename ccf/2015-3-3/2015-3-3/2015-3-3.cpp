// 2015-3-3.cpp : 定义控制台应用程序的入口点。
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
int mon,num,week,st,ed;
int day_o[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int day_r[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int ww[202][13][32];
int check(int y)
{
	if(y%400==0)
		return 1;
	else if((y%4==0)&&(y%100))
		return 1;
	return 0;
}
void init()
{
	int week = 2;
	for(int i = 1850;i<=2050;i++)
	{
		for(int j = 1;j<=12;j++)
		{
			if(check(i))
			{
				for(int k = 1;k<=day_r[j];k++)
				{
					ww[i-1850+1][j][k] = week;
					week++;
					if(week==8)
						week = 1;
				}
			}
			else
			{
				for(int k = 1;k<=day_o[j];k++)
				{
					ww[i-1850+1][j][k] = week;
					week++;
					if(week==8)
						week = 1;
				}
			}
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d%d%d%d",&mon,&num,&week,&st,&ed);
	init();
	int cnt = 0;
	int flag = 0;
	for(int i = st;i<=ed;i++)
	{
		flag = 0;
		int cnt = 0;
		if(check(i))
		{
			for(int j = 1;j<=day_r[mon];j++)
			{
				if(ww[i-1850+1][mon][j]==week)
				{
					cnt++;
					if(cnt==num)
					{
						printf("%04d\/%02d\/%02d\n",i,mon,j);
						flag = 1;
						break;
					}
				}
			}
			if(!flag)
				printf("none\n");
		}
		else
		{
			for(int j = 1;j<=day_o[mon];j++)
			{
				if(ww[i-1850+1][mon][j]==week)
				{
					cnt++;
					if(cnt==num)
					{
						printf("%04d\/%02d\/%02d\n",i,mon,j);
						flag = 1;
						break;
					}
				}
			}
			if(!flag)
				printf("none\n");
		}
	}
}

