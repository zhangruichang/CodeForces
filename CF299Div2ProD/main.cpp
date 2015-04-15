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
#define seed 1007ULL
typedef unsigned long long ll;
using namespace std;
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
char s[maxn];
ll d[maxn],b[maxn];
bool ok[maxn];
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


int init(string &s)
{
    int sz = s.size();
    for(int i = 0; i < sz;++i)
    {
        ll x = s[i] - 'a';
        if(i==0)
        {
            d[i] = x;
            b[i] = 1;
        }
        else
        {
            d[i] = d[i-1]*seed + x;
            b[i] = b[i-1]*seed;
        }
    }
    ll t = d[sz-1];
    for(int i = 1; i < sz;++i)
    {
        int L = sz - i;
        ll x = t - d[i-1]*b[L];
        if(d[L-1]==x)return i;
    }
    return -1;
}
ll quick_exp(ll a,int b)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        string p;
        cin>>p;
        int L = init(p);
        memset(s,'0',n);
        s[n+1] = 0;
        vector<int>y;
        for(int i = 0; i < m; i++)
        {
            int x;
            scanf("%d",&x);
            y.push_back(x-1);
        }
        int sz = p.size(),now = 0;
        bool ok = true;
        for(int i = 0; i < m; i++)
        {
            if(i+1<m)
            {
                int t = y[i+1]-y[i];
                if(t<sz&&t!=L)
                {
                    ok = false;
                    break;
                }
            }
            int st = y[i];
            now = max(now,st);
            if(now-1==st)now--;
            for(int j = 0; st+j>=now&&j<sz;j++,now++) {
                s[now] = p[j];
            }
        }
        if(!ok)
        {
            puts("0");
        }
        else
        {
            int tot = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i]=='0')tot++;
            }
            ll ans = quick_exp(26,tot);
            cout<<ans<<endl;
        }
    }
    return 0;
}

