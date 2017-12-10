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
char s[40000];
int a[40000];
struct node
{
	int sum, tmin;
} t[90000];
node init(int val)
{
	node nd;
	nd.sum=nd.tmin=val;
	return nd;
}
node combine(node left, node right)
{
	node res;
	res.sum=left.sum+right.sum;
	res.tmin=miN(left.tmin, left.sum+right.tmin);
	return res;
}
void build(int index, int st, int en)
{
	if(st==en)
		t[index]=init(a[st]);
	else
	{
		int m=(st+en)/2;
		build(2*index, st, m);
		build(2*index+1, m+1, en);
		t[index]=combine(t[2*index], t[2*index+1]);
	}
}
void update(int index, int st, int en, int pos)
{
	if(st==pos && pos==en)
		t[index]=init(a[pos]);
	else
	{
		int mid=(st+en)/2;
		if(pos<=mid)
			update(index*2, st, mid, pos);
		else if(pos>mid)
			update(index*2+1, mid+1, en, pos);

		t[index]=combine(t[2*index], t[2*index+1]);
	}
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T, x;
    //s(T);
    FOR(r,0,10)
	{
		s(n);
		ss(s);
		FOR(i,0,n)
			if(s[i]=='(') a[i+1]=1; else a[i+1]=-1;
		a[n+1]=0; //gave WA
		build(1,1,n+1);
		s(m);
		cout<<"Test "<<r+1<<":\n";
		FOR(i,0,m)
		{
			s(x);
			if(x==0)
			{
				if(t[1].tmin==0 && t[1].sum==0)
					printf("YES\n");
				else printf("NO\n");
			}
			else
			{
				if(a[x]==1)
					a[x]=-1;
				else a[x]=1;
				update(1, 1, n+1, x);
			}
		}
	}
    return 0;
}
