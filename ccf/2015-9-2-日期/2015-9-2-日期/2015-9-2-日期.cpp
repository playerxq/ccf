// 2015-9-2-日期.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<stack>  
#include<queue>  
#include<vector>  
#include<deque>  
#include<map>  
#include<set>  
#include<algorithm>  
#include<string>  
#include<iomanip>  
#include<cstdlib>  
#include<cmath>  
#include<sstream>  
#include<ctime>  
using namespace std;  
  
int monthone[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  
int monthtwo[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};  
  
bool selectYear(int year)  
{  
    bool flag;  
    if(((year%4==0)&&(year%100!=0))||(year%400==0))  
        flag=true;  
    else  
        flag=false;  
    return flag;  
}  
  
int main()  
{  
    int year;  
    int day;  
    int temp;  
    int i=1;  
    scanf("%d",&year);  
    scanf("%d",&day);  
    if(selectYear(year)==false)  
    {  
        while(day>0)  
        {  
            temp=day;  
            day=day-monthone[i];  
            i++;  
        }  
    }  
    else if(selectYear(year)==true)  
    {  
        while(day>0)  
        {  
            temp=day;  
            day=day-monthtwo[i];  
            i++;  
        }  
    }  
    printf("%d\n%d\n",i-1,temp);  
    return 0;  
} 

