/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn = 5e6 + 10;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
LL dp[maxn], P[maxn], Sum[maxn], n, t, m, a, b;

void Init()
{
    memset(P, 0, sizeof P);
    P[1]=1;
    for(LL i=2;i*i<=maxn;i++)
    {
        if(!P[i])
        {
            for(LL j=i*i;j<=maxn;j+=i)
                P[j]=i;
        }
    }
    dp[1]=dp[2]=dp[3]=1;
	for(LL i=2;i<=maxn;i++)
		dp[i]= (P[i] ? (dp[i/P[i]]+1) : 1);
	Sum[0]=0;
	for(LL i=1;i<=maxn;i++) Sum[i]=Sum[i-1]+dp[i];
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    Init();
    t=getint();
    for(int ti=1;ti<=t;ti++)
    {
        a=getint(), b=getint();
		printf("%d\n", Sum[a]-Sum[b]);
    }
	return 0;
}
