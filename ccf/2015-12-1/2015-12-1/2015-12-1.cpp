// 2015-12-1.cpp : 定义控制台应用程序的入口点。
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
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	int sum = 0;
	while(n)
	{
		sum+=n%10;
		n/=10;
	}
	printf("%d\n",sum);
}

