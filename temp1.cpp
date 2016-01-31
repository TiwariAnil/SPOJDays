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
int m , n;
int da[189];
struct data
{
	int a, b, c;
};
vector <data> v;
bool comp(const data & x, const data & y)
{
	return x.a<y.a;
}
int ans=INF;
string s[33];
int visit[33][33], table[33][33];
int tx[4]={1, 0, -1, 0};
int ty[4]={0, -1, 0, 1};
int p=0;
void BFS(int x, int y)
{
	//return ;
	queue <PII> q;
	q.push(PII(x, y));
	visit[x][y]=1;
	while(!q.empty())
	{
		int gx=q.front().first, gy=q.front().second;
		q.pop();
		FOR(i,0,4)
		{
			int xx=gx+tx[i], yy=gy+ty[i];
			if(xx<n && xx>=0 && yy<m && yy>=0 )
			{
				if( s[xx][yy]!='X' && s[xx][yy]!='S' && visit[xx][yy]==0)
				{
					if(s[xx][yy]=='D' )
					{
						table[xx][yy]=table[gx][gy];
					}
					else
					{
						table[xx][yy]=table[gx][gy]+s[xx][yy]-'0';
						q.push(PII(xx,yy));
					}
					visit[xx][yy]=1;
				}
				if(s[xx][yy]=='D' && table[xx][yy] > table[gx][gy] )
				{
					table[xx][yy]=table[gx][gy];
				}
				else if(table[xx][yy] > table[gx][gy]+s[xx][yy]-'0')
				{
					table[xx][yy]=table[gx][gy]+s[xx][yy]-'0';
					q.push(PII(xx,yy));
				}
			}
		}
	}
	return ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
	//s(T);
	//int ans=0;
	//string s[29];
	while(1)
	{

		cin>>m>>n;
//			error(m);
		if(n==0 && m==0)
			break;
		FOR(i,0,n)
			cin>>s[i];
		ans=INF;
		int flag=0;
		memset(visit, 0, sizeof(visit));
		memset(table, 0, sizeof(table));
		int fx, fy;
		FOR(i,0,n)
		{
	//		error(i);
			FOR(j,0,m)
			{
				if(s[i][j]=='S')
				{
					BFS(i,j);
				}
				if(s[i][j]=='D')
				{
					fx=i, fy=j;
				}
			}
		}
		cout<<table[fx][fy]<<endl;
	}
	return 0;
}

/*
10 10
11111S1111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
11111D1111



*/
