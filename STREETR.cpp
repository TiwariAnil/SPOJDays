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
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int a[1000009],b[1000009],c[1000009];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T, gd;
    T=0;
	while(1)
	{
		T++;
		s(n);
		if(n==0)break;
		FOR(i,0,n)
		{
			s(a[i]);s(b[i]);s(c[i]);
		}

		//	a[0]=
		//	b[0]=
		c[0]+=b[0];

		a[1]+=b[0];
		b[1]+=miN(c[0], miN(a[1], b[0]));
		c[1]+=miN(b[1], miN(b[0], c[0]));
		FOR(i,2,n)
		{
			a[i]+=miN(a[i-1], b[i-1]);
			b[i]+=miN(a[i], miN(a[i-1], miN(b[i-1], c[i-1])));
			c[i]+=miN(b[i], miN(b[i-1], c[i-1]));
		}
		cout<<T<<". "<<b[n-1]<<endl;
	}
    return 0;
}













