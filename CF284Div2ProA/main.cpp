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
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))

struct Node
{
    int l, r;
};
Node data[maxn];

int main()
{
    int n, x;
    while(cin>>n>>x)
    {
        for(int i=0;i<n;i++) cin>>data[i].l>>data[i].r;
        int sum=0;
        for(int i=1;i<n;i++) sum+=(data[i].l-data[i-1].r-1)%x;
        sum+=(data[0].l-1)%x;
        for(int i=0;i<n;i++) sum+=(data[i].r-data[i].l+1);
        cout<<sum<<endl;
    }
	return 0;
}
