// 2016-12-1.cpp : 定义控制台应用程序的入口点。
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
int n;
int a,b,MAX;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	scanf("%d",&a);
	MAX = -1;
	for(int i = 1;i<n;i++)
	{
		if(i%2)
		{
			scanf("%d",&b);
			if(abs(a-b)>MAX)
				MAX = abs(a-b);
		}
		else
		{
			scanf("%d",&a);
			if(abs(a-b)>MAX)
				MAX = abs(a-b);
		}
	}
	printf("%d\n",MAX);
}

