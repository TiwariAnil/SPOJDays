//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
//some common functionn
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define mP                      make_pair
#define pB                      push_back
#define error(x)                cout << #x << " : " << (x) << endl
#define all(c)                  (c).begin(),(c).end()
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Output macros
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

using namespace std;

void chekarre(int * arr,int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}


int n, m , flag=0;
int a[3][200009]={0};
int visit[3][200009];
int x, y;
int xx={0, 0, -1, 1};
int yy={1, -1,0, 0};

int BFS(int x, int y, int prev)
{
	if(visit[x][y]==0)
	{
		visit[x][y]=1;
		if(flag==1)
			return 1;
		if(x==n-1 && a[x][y]==1)
		{
			flag=1;
			return 1;
		}
		int xn, yn;
		FOR(i,0,4)
		{
			 xn=x+xx[i], yn=x+yy[i];
			 if(xn>=0 && yn>=0 && xn<3 && yn<n)
			 {
			 	if(a[x][y]==0)
			 	{
			 		return 1;
			 	}
			 	if(a[x][y]==1 && )
			 	{
			 		
			 	}
			 }
		}	
	}
	return 1;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	if(flag==1 || visit[x][y]==1)
	{
		return 1;
	}
	if(x==n-1 && a[x][y]==1)
	{
		flag=1;
		return 1;
	}
	if(x==n-1)
	{
		return 1;
	}
	if(visit[x][y]==0)
	{
		if(a[x][y]==0)
		{
			visit[x][y]=1;
		}
		if(a[x][y]==1)
		{
			visit[x][y]=1;
			BFS(x, y+1, 1);
		}
	}
	return 1;
	
	
}


int solve()
{
	flag=0;
	FOR(i,0,3)
	{
		if(a[i][0]!=0)
		{
			if(a[i][0]==1)
			{
				BFS(i,0, 1);
			}
			else
			{
				BFS(i,0,2);
			}
		
		}
		if(flag==1)
		{
			cout<<"yes"<<endl;
			return 1;
		}
	}
	cout<<"no"<<endl;
    return 1;
}

bool input()
{
	s(n);
	
	FOR(i,0,3)
		FOR(j,0,n)
		{
			visit[i][j]=0;
		}
	
	FOR(i,0,n)
	{
		FOR(j,0,3)
		{
			//s(x);s(y);s(z);
			s(a[j][i]);
		}
	}
	return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int T=1;
    s(T);
    for(int testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;

        solve();
        //printf("\n");

    }
//    system("pause");
    return 0;
}




