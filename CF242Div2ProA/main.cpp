/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], n;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    string str;
    while(cin>>n)
    {
        cin>>str;int s=0, b=0, n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]=='x') s++;
            else b++;
        }
        int ans;
        if(n/2>b)
        {
            ans=n/2-b;
            int ansi=0;
            for(int i=0;i<n && ansi<ans; i++)
            {
                if(str[i]=='x') str[i]='X', ansi++;
            }
        }
        else
        {
            ans=b-n/2;
            int ansi=0;
            for(int i=0;i<n && ansi<ans; i++)
            {
                if(str[i]=='X') str[i]='x', ansi++;
            }
        }
        cout<<ans<<endl;
        cout<<str<<endl;
    }
	return 0;
}
