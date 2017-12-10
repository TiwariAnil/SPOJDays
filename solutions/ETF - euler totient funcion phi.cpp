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
int n, m , pos;
int a[1000009], pm[1000000];
void prime()
{
	int n=1000001;
	memset(a,0,sizeof(a));
	a[0]=a[1]=1;
	FOR(i,2,sqrt(n)+1)
		if(a[i]==0)
			for(int j=2; j*i<n+2; j++)
				a[i*j]=1;

	pos=0;
	FOR(i,2,n)
	{
		if(a[i]==0)
			pm[pos++]=i;
	}
	//error(pos);
}
//1000000
//  79000
int power(int base,int pow)
{
    if(base==0)
        return 0;
    if(base==1 || pow==0)
        return 1;
    int ans=1;
    while(pow)
    {
        if(pow%2==1)
        {
            ans*=base;
       //     ans%=MOD;
        }
        base*=base;
       // base%=MOD;
        pow>>=1;
    }
    return ans;
}
int calc(int n)
{
	int cnt, ans=1;
	for(int i=0; i<pos; i++)
	{
		cnt=0;
		if(n%pm[i]==0)
		{
		//	error(pm[i]);
			while(n%pm[i]==0)
				n/=pm[i], cnt++;
		//	error(cnt);
	//		error(power(pm[i],cnt-1));

			ans*=(power(pm[i],cnt-1)*(pm[i]-1));
		//	error(ans);
			if(n==1)
				break;
		}
		if (a[n]==0)
		{
			ans*=(n-1);
			break;
		}
	}
	return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    prime();
 //   FOR(i,0,20)
	//	cout<<a[i]<<" ,";
    int T;
    s(T);
	while(T--)
	{
		n=haint();
		//s(n);
		if(a[n]==0)
			printf("%d\n", n-1);
		else
			printf("%d\n", calc(n));
	}
    return 0;
}
/*
48
3 2 2 2 2
2 * 2pow 3
*/
