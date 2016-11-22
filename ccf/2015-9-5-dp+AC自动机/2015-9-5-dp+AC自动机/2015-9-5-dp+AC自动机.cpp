// 2015-9-5-dp+AC自动机.cpp : 定义控制台应用程序的入口点。
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
const int MX = 1e4 + 5;
int tot;
typedef long long LL;  
typedef pair<int, int> PII;  
typedef vector<LL> vec;  
typedef vector<vec> mat; 
int rear;
const LL INF = 0x3f3f3f3f3f3f3f3f;  
struct Node
{
	int next[26];
	int fail;
	int count;
	void init()
    {
        memset(next,0,sizeof(next));
        fail=0;
        count=0;
    }
} node[MX];
void init()
{
	tot = 0;
	node[0].init();
}
int insert(char* s)
{
	int i = 0,index;
	int p = 0;
	while(s[i])
	{
		index = s[i]-'a';
		if(node[p].next[index]==0)
		{
			node[++tot].init();
			node[p].next[index]=tot;
		}
		p = node[p].next[index];
		i++;
	}
	node[p].count++;
	return 0;
}
void mat_fill(mat &A, LL val) {  
    for(int i = 0; i < A.size(); i++) {  
        for(int j = 0; j < A[0].size(); j++) {  
            A[i][j] = val;  
        }  
    }  
} 
queue<int> Q;
mat build_ac()
{
	int cur,son,i,p;
	Q.push(0);
	while(!Q.empty())
	{
		p = Q.front();
		Q.pop();
		for(int i = 0;i<26;i++)
		{
			if(node[p].next[i]!=0)
			{
				cur = node[p].fail;
				son = node[p].next[i];
				if(p==0)//根
                    node[son].fail=0;
				else
				{
					while(cur!=0&&node[cur].next[i]==0)
						cur = node[cur].fail;
					node[son].fail = node[cur].next[i];
				}
				if(node[node[son].fail].count)
					node[son].count+=node[node[son].fail].count;
				Q.push(son);
			}
			else//使用fail指向的后缀的next来拼接
                node[p].next[i]=node[node[p].fail].next[i];
		}
	}
	mat A(tot+1, vec(tot+1));
	mat_fill(A, -INF);  
    for(int i = 0; i <tot+1; i++) {  
        for(int j = 0; j < 26; j++) {  
			int chd = node[i].next[j];
			A[chd][i] = node[node[i].next[j]].count;  
        } 
    }
    return A;
}
mat mat_mul(mat &A, mat &B) {  
    mat C(A.size(), vec(B[0].size()));  
    mat_fill(C, -INF);  
    for(int i = 0; i < A.size(); i++) {  
        for(int j = 0; j < B[0].size(); j++) {  
            for(int k = 0; k < B.size(); k++) {  
                if(A[i][k] + B[k][j] >= 0) {  
                    C[i][j] = max(C[i][j], A[i][k] + B[k][j]);  
                }  
            }  
        }  
    }  
    return C;  
}
mat mat_pow(mat A, LL n) {  
    mat B = A; n--;  
    while(n) {  
        if(n & 1) B = mat_mul(B, A);  
        A = mat_mul(A, A);  
        n >>= 1;  
    }  
    return B;  
}
char S[MX]; 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n; LL m; //FIN;  
    scanf("%d%lld", &n, &m);  
    init();  
    for(int i = 1; i <= n; i++) {  
        scanf("%s", S);  
        insert(S);  
    }  
    mat A = build_ac();  
    A = mat_pow(A, m);  
  
    LL ans = 0;  
    for(int i = 0; i < tot; i++) {  
        ans = max(ans, A[i][0]);  
    }  
    printf("%lld\n", ans);  
    return 0;
}

