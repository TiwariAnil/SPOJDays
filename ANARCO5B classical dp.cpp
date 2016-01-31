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
int n, m, n1, n2 ;
long long a1[10009], a2[10009];
bool ck[10009], ckneg[10009];
vector <long long> v1, v2, vec;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    //s(T);
	while(s(n1)==1)
	{

		if(n1==0)
			break;
		vec.clear(); v1.clear(); v2.clear();
		memset(ck, false, sizeof(ck));
		memset(ckneg, false, sizeof(ckneg));
		FOR(i,0,n1)
		{

			sl(a1[i]);
			if(a1[i]>=0)
				ck[a1[i]]=true;
			else
				ckneg[abs(a1[i])]=true;
		}
		s(n2);
		FOR(i,0,n2)
		{
			sl(a2[i]);
			if(ck[a2[i]]==true || ckneg[abs(a2[i])]==true)
				vec.push_back(a2[i]);
		}
//		error(vec.size());
		int t1=0, t2=0;
		long long sum;
		FOR(i,0,vec.size())
		{
//			error(vec[i]);
			sum=0;
			while(a1[t1]<=vec[i] && t1<n1)
				sum+=a1[t1++];
			v1.push_back(sum);
//			error(sum);
			sum=0;
			while(a2[t2]<=vec[i] && t2<n2)
				sum+=a2[t2++];
			v2.push_back(sum);
//			error(sum);
		}
		sum=0;
		FOR(i,t1,n1)
			sum+=a1[i];
		v1.push_back(sum);

//		error(v2.size());
		sum=0;
		FOR(i,t2,n2)
			sum+=a2[i];
		v2.push_back(sum);
//		error(v2.size());
/*
		FOR(i,0,v1.size())
			cout<<v1[i]<<" -- ";
		cout<<endl;
		FOR(i,0,v2.size())
			cout<<v2[i]<<" --- ";
*/
		sum=0;
		FOR(i,0,v1.size())
		{
			sum+=maX(v1[i], v2[i]);
		}
		pl(sum);
		printf("\n");

	}
    return 0;
}
