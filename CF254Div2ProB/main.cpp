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
#include<sstream>
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
int a[60][60], indegree[60], n, t, m, x, y;

bool v[60];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m)
    {
        memset(a, 0, sizeof a);
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            a[x][y]=1;
            a[y][x]=1;
        }
        for(int i=1;i<=n;i++)
        {
            indegree[i]=0;
            for(int j=1;j<=n;j++)
                indegree[i]+=a[i][j];
        }
        LL ans=1;
        int mindeg=INT_MAX, mini=-1;;
        memset(v, 0 ,sizeof v);
        for(int i=1;i<=n;i++)
        {
            if(mindeg>indegree[i])
                mindeg=indegree[i], mini=i;
        }
        v[mini]=1;int last=mini;
        for(int i=2;i<=n;i++)
        {
            int mindeg=INT_MAX, mini=-1;;
            for(int j=1;j<=n;j++)
            {
                if(v[j]) continue;
                if(a[last][j] && mindeg>indegree[j])
                    mindeg=indegree[j], mini=j;
            }
            if(mini!=-1) v[mini]=1, ans*=2;
            else
            {
                int mindeg=INT_MAX;
                for(int j=1;j<=n;j++)
                {
                    if(v[j]) continue;
                    if(mindeg>indegree[j]) mindeg=indegree[j], mini=j;
                }
                v[mini]=1;
            }
            last=mini;
        }
        cout<<ans<<endl;
    }
	return 0;
}
