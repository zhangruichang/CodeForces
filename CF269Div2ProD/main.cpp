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
int a[maxn], b[maxn], N[maxn];
int KMP(int n, int w)
{
    int i=0, j=0, cnt=0, base=a[0];
    while(i<n)
    {
        if(j==-1 || a[i]-base==b[j])
        {
            i++, j++;
        }
        else
		{
			if(j==0)
			{
				base=a[i];
			}
			else
				j=N[j];
		}
        if(j==w)
        {
            cnt++; j=0;
        }
    }
    return cnt;
}

void GetNext(int w)
{
    N[0]=-1;
    for(int j=0;j<=w-2;j++)
    {
        int k=N[j];
        while(k!=-1 && b[k]!=b[j])
            k=N[k];
        N[j+1]=k+1;
    }
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, w;
    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<w;i++) cin>>b[i];
	int tmp=b[0];
    for(int i=0;i<w;i++) b[i]-=tmp;
    GetNext(w);
    cout<<KMP(n, w)<<endl;
	return 0;
}
