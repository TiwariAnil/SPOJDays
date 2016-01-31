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


int n, m , a, b;
vector <int> vec[2003];//, b[20003]
int clne[2009];
int flag=0;

void BFS(int x)
{
	PII nd;
	int color;
	queue <PII>q;
	q.push(PII(x,1));
	//error(x);
	while(!q.empty())
	{
		nd=q.front();
		q.pop();
		x=nd.first;
		color=nd.second;
		//error(x);
		FOR(i,0,vec[x].size())
		{
	//		error(color);
	//		error(vec[x][i]);
	//		error(clone[vec[x][i]]);
			if(clne[vec[x][i]]==0)
			{
				if(color==1)
				{
					clne[vec[x][i]]=2;
					q.push(PII(vec[x][i],2));
				}
				else
				{
					clne[vec[x][i]]=1;
					q.push(PII(vec[x][i],1));
				}
			}
			else
			{
				if(clne[vec[x][i]]==color)
				{
	//				error("hell");
					flag=1;
					return ;
				}
			}
			
		}
	}
	//error("goooo");
}

int solve()
{
	FOR(i,1,n+1)
	{
		if(vec[i].size()>0 && clne[i]==0 && flag!=1)
		{
			BFS(i);
	//		cout<<"next\n";
		}
	}
    return 1;
}

bool input()
{
	s(n);s(m);
	FOR(i,0,n+1)
	{
		clne[i]=0;
		vec[i].clear();
	}
	FOR(i,0,m)
	{
		s(a);s(b);
		vec[a].push_back(b);
		vec[b].push_back(a);
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
		cout<<"Scenario #"<<testnum<<":\n";
		if(flag==1)
			cout<<"Suspicious bugs found!\n";
		else
			cout<<"No suspicious bugs found!\n";
        flag=0;
        //printf("\n");

    }
//    system("pause");
    return 0;
}




