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
#define p(n)                        printf("%d",n)

using namespace std;
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d",n)

int n, m , k;
double best=0.0;
struct STORE
{
	int v, w;
} data[504];
bool comp(STORE const &a, STORE const &b)
{
	double d1=a.v, d2=a.w, d3=b.v, d4=b.w;
	d1=a.v/a.w; d2=b.v/b.w;
	return d1 < d2;
}
double Upperbound(int m, int k)
{
	double mx=0;
	FORs(i,m,0)
	{
		if(k > data[i].w)
		{
			mx+=data[i].v;
			k-=data[i].w;
		}
		else
		{
			mx+=((k*data[i].v/data[i].w));
			break;
		}
	}
	return mx;
}
int cnt=0;
void knap(int i, double val, int size)
{
	//cnt++;
	if(val > best)
		best=val;
	if(i<0 || size==0 )
		return ;
	//error(cnt);error(val+Upperbound(i,size));
	if(size-data[i].w>=0)
		if(val+Upperbound(i, size) > (double)best)
			knap(i-1, val+(double)data[i].v, size-data[i].w);
	if(val+Upperbound(i-1, size) > (double)best)
		knap(i-1, val, size);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
	s(k); s(n);
	int a, b;
	FOR(i,0,n)
	{
		s(a); s(b);
		//if(b<=k && a!=0)
		data[i].v=a, data[i].w=b;//, pos++;
	}
	sort(data, data+n, comp);
/*
	cout<<endl;
	FOR(i,0,pos)
		cout<<(data[i].w)<<" "<<(data[i].v)<<endl;
*/
	knap(n-1, 0, k);
	int bst=(int)best;
	p(bst);
	//error(cnt);
	return 0;
}
/*
16 4
30 5
10 5
45 9
45 3
*/
