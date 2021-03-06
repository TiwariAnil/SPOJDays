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
int visit[1111][1111];
string s[1111];
int tmpx, tmpy;
int ans=0;
int xr[4]={1, -1, 0, 0};
int yr[4]={0, 0, 1, -1};

void DFS(int x, int y, int cnt)
{
	visit[x][y]=1;
	if(cnt>ans)
		ans=cnt, tmpx=x, tmpy=y;
	FOR(i,0,4)
	{
		int xx=x+xr[i], yy=y+yr[i];

		if(xx>=0 && yy>=0 && xx<n && yy<m && visit[xx][yy]==0 && s[xx][yy]=='.')
		{
			DFS(xx, yy, cnt+1);
		}
	}
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T, x,y;
    s(T);
    while(T--)
	{
		memset(visit, 0, sizeof(visit));
		s(m); s(n);
		FOR(i,0,n)
			cin>>s[i];
		ans=0;
		int	res=0;
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				if(s[i][j]!='#' && visit[i][j]==0)
				{

					DFS(i,j,0);
					memset(visit, 0, sizeof(visit));
					DFS(tmpx, tmpy,0);
					if(res<ans)
						res=ans;
				}
			}
		}
		cout<<"Maximum rope length is "<<res<<".\n";
	}
    return 0;
}
/*
33
7 6
#######
#...###
#.#####
#.#####
#######
#######
3 3
###
#.#
###
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######
7 6
#######
#.#.###
#.#.###
#####.#
#.....#
#######
*/
