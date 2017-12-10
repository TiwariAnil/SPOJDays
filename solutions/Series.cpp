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
int n, m ;
long long a[10000009]={0};
int p[10000008];

int prime()
{
	int n=10000000;
	
	FOR(i,0,n+6)
       p[i]=1;
	      
	 p[0]=p[1]=0;    //shit happend ;-)
	 a[0]=a[1]=0;	 
	 for(int i=2;i<=sqrt(n+6)+1;i++)
	 {	 
	     if(p[i]==1)
		 {
		 	//error(i);
		 	p[i]=i;
		 	 for(int j=2;(i*j)<=n+6 ;j++)
	         {
	         	//error(i*j);
	         //	error(p[i*j]); cout<<endl;
	      		if(p[i*j]==1)
				  	p[i*j]=i;
	      	 }
		 }    
	}
	FOR(i,2,n+6)
	{
		if(p[i]==1)
			a[i]=a[i-1]+i;
		else
			a[i]=a[i-1]+p[i];
	}
	return 1;
}

int solve()
{
	/*
	FOR(i,0,20)
		error(p[i]);
	*/
	//FOR(i,0,30)
	//	cout<<i<<" : "<<p[i]<<endl;
	cout<<a[n]<<endl<<endl;
    return 1;
}

bool input()
{
	s(n);
	return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	prime();
    a[0]=a[1]=0;
	int T=1;
    s(T);
    for(int testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;

        solve();
    }
//    system("pause");
    return 0;
}




