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
int l[1001];
int r[1001];
int a[1001];
int n;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		l[i] = r[i] = i;
	}
	for(int i = 1;i<n;i++)
	{
		while(a[l[i]-1]>=a[i])
			l[i] = l[l[i]-1];
	}
	for(int i = n-2;i>=0;i--)
	{
		while(a[r[i]+1]>=a[i])
			r[i] = r[r[i]+1];
	}
	int maxx = -1;
	for(int i = 0;i<n;i++)
	{
		if(maxx<(r[i]-l[i]+1)*a[i])
			maxx = (r[i]-l[i]+1)*a[i];
	}
	printf("%d\n",maxx);
}