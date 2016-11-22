// 2013-12-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
#include<stdio.h>  
using namespace std;  
int main()  
{  
    string s;  
    cin>>s;  
    int cnt=1;  
    int sum=0;  
    for(int i=0;i<=10;i++)  
    {  
        if(cnt==10)  
        {  
            break;  
        }  
        if(s[i]>='0'&&s[i]<='9')  
        {  
            sum+=cnt*(s[i]-'0');  
            cnt++;  
        }  
    }  
    sum%=11;  
    if(sum==10)  
    {  
        if(s[12]=='X')  
            cout<<"Right"<<endl;  
        else  
        {  
            s[12]='X';  
            cout<<s<<endl;  
        }  
    }  
    else  
    {  
        if(s[12]-'0'==sum)  
            cout<<"Right"<<endl;  
        else  
        {  
            s[12]=sum+'0';  
            cout<<s<<endl;  
        }  
    }  
    return 0;  
} 

