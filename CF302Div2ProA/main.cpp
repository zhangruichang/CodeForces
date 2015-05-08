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
int n, t, m;

pair<int, int> a[26];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int k;string str;
    while(cin>>k>>str)
    {

    for(int i=0;i<26;i++) a[i]={-1, -1};
    int lastc=str[0]-'a', lasti=0;
    a[str[0]-'a']={0,-1};
    for(int i=1;i<str.size();i++)
    {
        char e=str[i];
        if(a[e-'a'].first==-1)
        {
            a[lastc].second=i-1;
            a[e-'a']={i, -1};
            lastc=e-'a',lasti=i;
        }
    }
    a[lastc]={lasti, str.size()-1};
    //for(auto e: a) cout<<e.first<<" "<<e.second<<endl;
    int cnt=0;
    vector<pair<int, int>> ans;
    for(auto e: a)
    {
        //end=a[e-'a'];
        if(e.first!=-1) cnt++, ans.push_back(e);
    }
    sort(ans. begin(), ans.end());
    //cout<<"log:"<<endl;
    //cout<<cnt<<" "<<k<<endl;
    //for(auto e: ans) cout<<e.first<<" "<<e.second<<endl;
    if(cnt>=k)
    {
        puts("YES");
        for(int i=0;i<k-1;i++)
                cout<<str.substr(ans[i].first, ans[i].second-ans[i].first+1)<<endl;
        cout<<str.substr(ans[k-1].first)<<endl;
        //for(auto e : ans) cout<<e<<endl;
    }
    else puts("NO");
    }
	return 0;
}
