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
int a[50009];
struct data
{
	int pref, suff, sum, ans;
};data T[500000];

data init(int val)
{
	data res;
	res.sum=val;
	res.pref=res.suff=res.ans=maX(-1000000, val);
	return res;
}
data combine (data left, data right) {
	data res;
	res.sum = left.sum + right.sum;
	res.pref = maX (left.pref, left.sum + right.pref);
	res.suff = maX (right.suff, right.sum + left.suff);
	res.ans = maX (maX (left.ans, right.ans), left.suff + right.pref);
	return res;
}

void build(int index, int st, int en)
{
	if(st==en)
		T[index]=init(a[st]);
	else
	{
		int mid=st+(en-st)/2;
		build(2*index, st, mid);
		build(2*index+1, mid+1, en);
		T[index]=combine(T[2*index], T[2*index+1]);
	}

}
void update(int index, int st, int en, int x, int val)
{
	if(st==x && en==x)
		T[index]=init(val);
	else
	{
		int mid = (st+en)/2;
		if(x<=mid)
			update(index*2, st, mid, x, val);
		else if(x>mid)
			update(index*2+1, mid+1, en, x, val);

		T[index]=combine(T[2*index], T[2*index+1]);
	}
}


data query(int index, int st, int en, int x, int y)
{     //1   "8   16"   20
	if (x == st && y == en)
		return T[index];
	int mid = (st + en) / 2;
	if (y <= mid)
		return query (index*2, st, mid, x, y);
	if (x > mid)
		return query (index*2+1, mid+1, en, x, y);
	return combine (
		query (index*2, st, mid, x, mid), // Take care here its x to mid
		query (index*2+1, mid+1, en, mid+1, y)
	);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int  p, q, r;
    //s(T);
	s(n);
	FOR(i,1,n+1)
		s(a[i]);
	build(1,1,n+1);

	s(m);
	FOR(i,0,m)
	{
		s(p); s(q); s(r);
		if(p==0)
			a[q]=r, update(1,1,n+1,q,r);
		else
			printf("%d\n",query(1,1,n+1,q,r).ans);
/*
	error("Prefix");
    FOR(i,0,17)
		cout<<T[i].pref<<",  ";
	cout<<endl;
	error("Suffix");
    FOR(i,0,17)
		cout<<T[i].suff<<",  ";
	cout<<endl;
	error("Sum");
    FOR(i,0,17)
		cout<<T[i].sum<<",  ";
	cout<<endl;
	error("Ans");
    FOR(i,0,17)
		cout<<T[i].ans<<",  ";
	cout<<endl;
*/
	}
    return 0;
}
/*
6
-1 -2 3 0 -1 9
99
0 1 0
1 1 1






1 1 1
1 2 2
1 1 2
1 3 3
1 1 5
1 1 6
1 2 4








*/



































