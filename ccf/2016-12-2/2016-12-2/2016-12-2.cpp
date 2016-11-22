// 2016-12-2.cpp : 定义控制台应用程序的入口点。
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
int n,p;
int map[21][6];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&p);
		int flag = 0;
		for(int r = 1;r<=20&&!flag;r++)
		{
			for(int c = 1;c<=5&&!flag;c++)
			{
				if(map[r][c]==0)
				{
					int cnt = 0;
					int temp = c;
					while(map[r][temp]==0&&temp<=5)
					{
						temp++;
						cnt++;
					}
					if(cnt>=p)
					{
						int temp = c;
						int tt = 0;
						while(map[r][temp]==0&&tt<p)
						{
							map[r][temp]=1;
							printf("%d",(r-1)*5+temp);
							temp++;
							tt++;
							if(tt<p)
								printf(" ");
							else
								printf("\n");
						}
						flag = 1;
						break;
					}
					else
					{
						continue;
					}
				}
			}
		}
		if(flag)
			continue;
		else
		{
			int tt = p;
			for(int r = 1;r<=20&&!flag;r++)
			{
				for(int c = 1;c<=5&&!flag;c++)
				{
					if(map[r][c]==0)
					{
						map[r][c]=1;
						printf("%d",(r-1)*5+c);
						tt--;
						if(tt)
							printf(" ");
						else
						{
							printf("\n");
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
}

