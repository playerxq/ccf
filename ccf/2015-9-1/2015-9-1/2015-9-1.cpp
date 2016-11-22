// 2015-9-1.cpp : 定义控制台应用程序的入口点。
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
int a;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	int cnt = 0;
	int pre = -1;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a);
		if(a!=pre)
			cnt++;
		pre = a;
	}
	printf("%d\n",cnt);
}

