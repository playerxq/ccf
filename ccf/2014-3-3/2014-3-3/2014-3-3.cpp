// 2014-3-3.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int n;
char cmd[55];
int cmd_len;
vector<char> v_c_n;
vector<char> v_c_y;
map<char, string> mm;
string cc;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%s",cmd);
	cmd_len = strlen(cmd);
	int flag = 0;
	int next = 1;
	for(int now = 0;now<cmd_len;now++)
	{
		if(cmd[now+1]==':')
		{
			v_c_y.push_back(cmd[now]);
			now++;
		}
		else
			v_c_n.push_back(cmd[now]);
	}
	scanf("%d",&n);
	getchar();
	for(int i = 1;i<=n;i++)
	{
		printf("Case %d:",i);
		getline(cin,cc);
		if(!mm.empty())
			mm.clear();
		int flag = 0;
		int para = 0;
		char ncmd;
		string npara;
		std::size_t pos=cc.find(" ");
		do
		{
			if(!flag)
				flag = 1;
			if(flag)
			{
				pos++;
				if(cc[pos]!='-'&&para==0)
					break;
				else if(para==1)
				{
					std::size_t npos = cc.find(" ",pos+1);
					npara = cc.substr(pos,npos-pos);
					mm[ncmd] = npara;
					para = 0;
				}
				else if(para==0)
				{
					vector<char>::iterator iter;
					ncmd = cc[++pos];
					for(iter = v_c_y.begin();iter!=v_c_y.end();iter++)
					{
						if(*iter == ncmd)
						{
							para = 1;
							break;
						}
					}
					if(!para)
					{
						for(iter = v_c_n.begin();iter!=v_c_n.end();iter++)
						{
							if(*iter == ncmd)
							{
								mm[ncmd]=" ";
								break;
							}
						}
						if(iter==v_c_n.end())
							break;
					}
				}
			}
		}while((pos=cc.find(" ",pos+1))!=string::npos);
		for(map<char, string>::iterator it = mm.begin();it!=mm.end();it++)
		{
			printf(" -%c",it->first);
			if(it->second!=" ")
			{
				cout<<" "<<it->second;
			}	
		}
		printf("\n");
	}
}

