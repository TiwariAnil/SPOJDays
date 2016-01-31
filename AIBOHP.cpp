//Data Structure includes
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
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}
inline int haint()
{
	int h;
	 register char c=0;
	 while (c<33) c=getchar();//getchar_unlocked();
	 h=0;
	 while (c>33)
	 {
	     h=h*10+c-'0';
	     c=getchar();//getchar_unlocked();
	 }
	 return h;
}
int n, m ;
//string s, s1, s2;
char s1[6200], s2[6200];
int dp[2][6200];//[6200];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    s(T);
	while(T--)
	{
		ss(s1);
		n=strlen(s1);
		memset(dp,0,sizeof(dp));
		FOR(i,0,n)
			s2[i]=s1[n-i-1];
		if(s1[0]==s2[0])
			dp[0][0]=1;

		FOR(i,1,n)
		{
			if(s1[0]==s2[i])
				dp[0][i]=1;
			else
				dp[0][i]=dp[0][i-1];
		}
		FOR(i,1,n)
		{
			if(s1[i]==s2[0])
				dp[i%2][0]=1;
			FOR(j,1,n)
			{
				if(s1[i]==s2[j])
				{
					dp[i%2][j]=1+dp[(i-1)%2][(j-1)];
				}
				else
				{
					dp[i%2][j]=maX(dp[(i-1)%2][j], maX(dp[i%2][(j-1)], dp[(i-1)%2][(j-1)]));
				}
			}
		}
		p(n-maX(dp[0][n-1], dp[1][n-1]));printf("\n");//<<endl;
	}
    return 0;
}
