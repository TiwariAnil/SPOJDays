// Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<list>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define mP                      make_pair
#define pB                      push_back
#define error(x)                cout << #x << " : " << (x) << endl
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pl(n)                       printf("%lld",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

void chekarre(int * arr,int n)
{
    cout<<"[";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}
inline long long haint()
{
    long long h;
    register char c=0;
    while (c<33) c=getchar();// getchar_unlocked();
    h=0;
    while (c>33)
    {
        h=h*10+c-'0';
        c=getchar();// getchar_unlocked();
    }
    return h;
}

int n, m;
int dp[1003][1003];
int a[1003];
int calc(int st, int en)
{
	if(st>=en) return 0;

	if(dp[st][en]!=-1)
		return dp[st][en];

	int one, two;
	if(a[st+1]>=a[en])
		one=a[st]-a[st+1]+calc(st+2, en );
	else
		one=a[st]-a[en]+ calc(st+1, en-1);

	if(a[en-1]>a[st])
		two=a[en]-a[en-1]+calc(st, en-2);
	else
		two=a[en]-a[st]+calc(st+1, en-1);

	return dp[st][en]=maX(one, two);
}

int main()
{
	//freopen("output.txt","w",stdout);
	int T, g=1;

	while(cin>>n)
	{
		if(n==0)break;
		fill(dp, -1);
		FOR(i,0,n)
			s(a[i]);
		cout<<"In game "<<g<<", the greedy strategy might lose by as many as "<<calc(0,n-1)<<" points.\n";
		g++;


	}

}





