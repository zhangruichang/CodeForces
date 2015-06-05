/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
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
int a[maxn], n, t, m;

char s[200];
bool dp[200][8];
int p[200][8];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    scanf("%s", s+1);
    memset(dp, 0, sizeof dp);memset(p, 0, sizeof p);
    dp[0][0]=1;
    bool ok=0;
    stack<char> st;
    for(int i=1;!ok && s[i];i++)
    {
        int x=s[i]-'0';
        for(int j=0;!ok && j<i;j++)
        {
            for(int k=0;!ok && k<8;k++)
            {
                if(!dp[j][k]) continue;
                p[i][(k*10+x)%8]=j;
                dp[i][(k*10+x)%8]=1;
                if((k*10+x)%8==0)
                {
                    ok=1;
                    int t=i, cur=0;
                    while(t)
                    {
                        st.push(s[t]);
                        int tmp=t;
                        t=p[t][cur];
                        int tcur=cur;
                        for(cur=0;cur<8;cur++)
                        {
                            if(dp[t][cur] && (cur*10+s[tmp]-'\0')%8==tcur) break;
                        }
                    }
                }
            }
        }
    }
    if(st.empty()) puts("NO");
    else
    {
        puts("YES");
        while(!st.empty())
        {
            cout<<st.top();st.pop();
        }
        cout<<endl;
    }
	return 0;
}
