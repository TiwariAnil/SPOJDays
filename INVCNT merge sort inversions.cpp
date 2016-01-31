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
long long ans=0;
int a[200009];
void merge(int x, int y, int mid)
{
	int tmp[y-x+1];
	long long st=0, low=x, high=mid+1;
	while(low<=mid && high<=y)
	{
		if(a[low]<=a[high])
		{
			tmp[st++]=a[low];
			low++;
		}
		else
		{
			ans+=(mid-low+1);
			tmp[st++]=a[high];
				high++;
		}
	}
	if(low!=mid+1)
	{
		while(low<=mid)
			tmp[st++]=a[low++];
	}
	else if(high!=y+1)
	{
		while(high<=y)
			tmp[st++]=a[high++];
	}
	FOR(i,0,st)
	{
		a[x+i]=tmp[i];
	}
}

void mergesort(int x, int y)
{
	if(x<y)
	{
		int mid=(x+y)/2;
		mergesort(x, mid);
		mergesort(mid+1,y);
		merge(x, y, mid);
	}
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    s(T);
    while(T--)
	{
		s(n);FOR(i,0,n)s(a[i]);
		ans=0;
		mergesort(0,n-1);
//		FOR(i,0,n)
	//		cout<<a[i]<<" ";
		//cout<<endl;
		printf("%lld\n",ans);
	}

    return 0;
}
