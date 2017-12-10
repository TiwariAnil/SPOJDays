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
int n, m , goal;
int a[100010];
int fun(int gap)
{
	int now=a[0], cnt=1;
	FOR(i,0,n)
	{
		if(a[i]-now >=gap)
		{
			cnt++;
			now=a[i];
			if(cnt==goal)
				return 1;
		}
	}
	return 0;
}
int binary_srch()
{
	int st=0, en=a[n-1], mid;
	while(st<en)
	{
		mid=(st+en)/2;
		if(fun(mid))
			st=mid+1;
		else
			en=mid;
	}
	return st-1; // think abt it, why did I return st-1
	// COZ WHILE() 'L BREAK ONLY WHEN ST==EN ,
	// AS THE BOTTOM CONDITION.
	//BEFOR THAT ST,ST+1=EN, MID=ST, AND FUN(MID)==1, SO WE DID
	// ST= MID+1, NOW ST==EN SO BREAK, BUT ANS WAS MID, ie ST, BUT NOW
	// ST IS ST+1, SO RETURN ST-1; :D
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    s(T);
    while(T--)
	{
		s(n); s(goal);
		FOR(i,0,n)
			a[i]=haint();
		sort(a,a+n);
		printf("%d\n", binary_srch());
	}

    return 0;
}
