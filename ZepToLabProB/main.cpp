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
typedef vector<int> vi;
#define fi first
#define se second
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
    return !m ? n : GCD(n%m, m);
}
int a[maxn], b[maxn], n, t, m, tn, cur,cnt,maxc;bool maxf;
void dfs(int i)
{
    if(i>tn)
    {
        if(maxf) maxc=max(maxc, cur);
        else cnt+=(maxc-cur);
        return ;
    }
    cur+=a[i];
    dfs(2*i+1);
    //cur-=a[i];
    dfs(2*i+2);
    cur-=a[i];
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n;
    while(cin>>n)
    {
        tn=((1<<(n+1))-2);a[0]=0;
        for(int i=1;i<=tn;i++) scanf("%d", &a[i]);
        //cur.clear();
        //maxf=1;maxc=0;cur=0,cnt=0;
        //dfs(0);
        //cout<<maxc<<endl;
        for(int i=(tn-1)/2+1;i<=tn;i++) b[i]=0;
        for(int i=(tn-1)/2;i>=0;i--)
        {
            b[i]=max(a[2*i+1]+b[2*i+1], a[2*i+2]+b[2*i+2]);
        }
        //cout<<tn<<endl;
        //for(int i=0;i<=(tn-1)/2;i++) cout<<b[i]<<" ";
        int cnt=0;
        for(int i=1;i<=tn;i++)
        {
            cnt+=b[(i-1)/2]-b[i]-a[i];
        }
        cout<<cnt<<endl;
    }
	return 0;
}
