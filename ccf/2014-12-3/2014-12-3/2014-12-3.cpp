// 2014-12-3.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <list>
#include <map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct Node
{
	int line;
	int flag;
	int isCancel;
	double p;
	int s;
	Node(int f, double p, int s, int l):flag(f), p(p), s(s), line(l), isCancel(false){}
};
typedef long long LL;
const int inf = 0x7f7f7f7f; // 2139062143
const double eps = 1e-8;
list<Node> nn;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	char op[10];
	double p;
	int s;
	int cnt = 1;
	while(scanf("%s",op)!=EOF)
	{
		if(op[0]=='b')
		{
			cin>>p>>s;
			nn.push_back(Node(1,p,s,cnt++));
		}
		else if(op[0]=='s')
		{
			cin>>p>>s;
			nn.push_back(Node(0,p,s,cnt++));
		}
		else
		{
			cin >> s;
            list<Node>::iterator it = nn.begin();
            for(; it != nn.end() && it->line != s; ++it);
            it->isCancel = 1; //标记被Cancel
            cnt++;
		}
	}
	map<double, bool> vis;
    for(list<Node>::iterator it = nn.begin(); it != nn.end(); ++it){
        if(!it->isCancel) vis[it->p] = false;
    }
	LL ans_s = 0;
    double ans_p = 0;
	for(list<Node>::iterator it = nn.begin(); it != nn.end(); ++it){
        if(!vis[it->p]){
            vis[it->p] = true;
            double p0 = it->p;
            LL buy = 0, sell = 0;
            for(list<Node>::iterator it1 = nn.begin(); it1 != nn.end(); ++it1){
                if( it1->flag && !it1->isCancel && it1->p >= p0)  buy  += it1->s;
                if(!it1->flag && !it1->isCancel && it1->p <= p0)  sell += it1->s;
            }
            LL t = min(buy, sell);
            if(ans_s < t){
                ans_s = t;
                ans_p = p0;
            } else if(ans_s == t){
                ans_p = max(p0, ans_p);
            }
        }
    }

    cout << fixed << setprecision(2) << ans_p << " " << ans_s << endl;

    return 0;
}

