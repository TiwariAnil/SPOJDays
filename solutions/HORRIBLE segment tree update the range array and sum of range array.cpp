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
struct node
{
	long long sum, nodes_value;
}t[500000];

void clear()
{
	FOR(i,0,4*n)
		t[i].sum=t[i].nodes_value=0;
}

void update(int index, int st, int en, int x, int y, long long val)
{
	if(st>y || en<x)
		return ;
	if(x<=st && en<=y)
	{
		long long dc=en-st+1;
		t[index].sum+=dc*val;
		t[index].nodes_value+=val;
	}
	else
	{
		int mid=(st+en)/2;
		update(2*index, st, mid, x, y, val);
		update(2*index+1, mid+1, en, x, y, val);
		t[index].sum=t[2*index].sum+t[2*index+1].sum+t[index].nodes_value*(en-st+1);
	}
}

long long query(int index, int st, int en, int x, int y, long long cumulative_values)
{
	if(st>y || en<y)
		return 0;
	if(x<=st && en<=y)
	{
		long long d=en-st+1;
		return t[index].sum+d*cumulative_values;
	}
	else
	{
		int mid=(st+en)/2;
		cumulative_values+=t[index].nodes_value;
		long long a=query(2*index, st, mid, x, y, cumulative_values);
		long long b=query(2*index+1, mid+1, en, x, y, cumulative_values);
		return a+b;
	}
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cout<<"hels";
    int T, a, b,x;
    long long c;
    s(T);

	while(T--)
	{

		s(n);
		s(m);
		clear();
		FOR(i,0,m)
		{
			s(x);
			if(x==0)
			{
				s(a); s(b); sl(c);
				update(1, 0, n-1, a-1, b-1, c);
			}
			else
			{
				s(a); s(b);
				cout<<query(1,0,n-1,a-1,b-1,0)<<endl;
			}
		}
	}
    return 0;
}
