// 2014-12-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>  
#include<algorithm>  
#include<cstring>  
#include<string>  
using namespace std;  
int main()  
{  
    int n;  
    int num;  
    int red[1005];  
    int ans[1005];  
    int bns[1005];  
    scanf("%d",&n);  
    memset(ans,0,sizeof(ans));  
    memset(bns,0,sizeof(bns));  
    for(int i=0;i<n;i++)  
    {  
        scanf("%d",&red[i]);  
        ans[red[i]]++;  
    }  
    for(int i=0;i<n;i++)  
    {  
        if(ans[red[i]]!=bns[red[i]])  
        {  
            bns[red[i]]++;  
            if(i==n-1)  
            printf("%d\n",bns[red[i]]);  
            else  
            printf("%d ",bns[red[i]]);  
        }  
    }  
    return 0;  
}

