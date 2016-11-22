// 2014-9-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#define NUM 100
using namespace std;

int main()
{
    int n,a[105][105] = {0};
    cin >> n;
    while(n--)
    {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1+1;i <= x2;i++)
        {
            for(int j = y1+1;j <= y2;j++)   a[i][j] = 1;
        }
    }
    int num = 0;
    for(int i = 1;i <= NUM;i++)
    {
        for(int j = 1;j <= NUM;j++)
        {
            if(a[i][j]) num++;
        }
    }
    cout << num << endl;
    return 0;
}

