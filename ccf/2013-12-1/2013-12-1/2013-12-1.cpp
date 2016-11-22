// 2013-12-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
#include<cstring>  
using namespace std;  
  
int num[10100];     //num[3]=2 表示3出现了2次    
  
int main(){  
    int n,temp;  
    while(cin>>n){  
        for(int i=1;i<=n;i++){  
            cin>>temp;  
            num[temp]++;  
        }  
        int Max=0,Mark=0;  
        for(int i=10100-1;i>=1;i--){  
            if(Max<=num[i])  
                Max=num[i],Mark=i;  
        }  
        cout<<Mark<<"\n";  
    }  
    return 0;   
} 

