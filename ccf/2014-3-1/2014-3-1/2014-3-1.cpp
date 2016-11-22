// 2014-3-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int fun(int x)
{
    return x>0?x:-x;
}
bool cmp(int a,int b)
{
    return fun(a)<fun(b);
}

int main()
{
    int n,a[505];
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    int num = 0;
    for(int i = 1;i < n;i++)
    {
        if(fun(a[i]) == fun(a[i+1]))
        {
            num++;
            i++;
        }
    }
    cout << num << endl;
    return 0;
}

