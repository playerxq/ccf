// 2015-9-3.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <istream>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int n,m;
string str[105];
string key,value;
char cmd[105][105];
char temp[105];
char str1[105][200];
map<string,string> mm;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(int i = 0;i<n;i++)
	{
		getline(cin,str[i]);
	}
	for(int i = 0;i<m;i++)
	{
		cin>>key;
		getline(cin,value);
		value.erase(1,1);
		value.erase(value.length()-1,1);
		mm[key] = value;
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<str[i].length();j++)
		{
			if(str[i][j]=='{'&&str[i][j+1]=='{'&&str[i][j+2]==' ')
			{
				int k = j;
				while(str[i][k]!='}'||str[i][k-1]!=' '||str[i][k+1]!='}'&&k<str[i].length())  
                {  
                    k++;  
                }
				if(str[i][k]=='}'||str[i][k-1]==' '||str[i][k+1]=='}')
				{
					string ss =str[i].substr(j+3,k-j-4);
					if(mm[ss]!="")
					{
						str[i].insert(k+2,mm[ss]);
						str[i].erase(j,k-j+3);
					}
					else
						str[i].erase(j,k-j+2);
				}
			}
		}
		cout<<str[i]<<endl; 
	}
}

