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
int a[4003],b[4003],c[4003],d[4003];
int v1[17000000], v2[17000000];
int pos1, pos2;

int binarysrch(int data)
{
	int st=0, en=pos1, mid, cnt, i;
	while(st<=en)
	{
		mid=(st+en)/2;
		//error(mid);
		if(data==v2[mid])
		{
			//error(data);
			cnt=0;i=mid;
			while(data==v2[i] && i<pos1)
				cnt++, i++;
			i=mid-1;
			while(data==v2[i] && i>=0)
				i--, cnt++;
			return cnt;
		}
		else if (data < v2[mid])
			en=mid-1;
		else
			st=mid+1;
	}
	return 0;
}
/*
int binarysrch(int val)
{
    int size=0,temp=0,low=0,high=pos1,mid;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(v2[mid]==val)
        {
            temp=mid-1;
            while(mid<pos1&&v2[mid]==val)
            {
                size++;
                mid++;
            }
            while(temp>=0&&v2[temp]==val)
            {
                size++;
                temp--;
            }
            return size;
        }
        else if(v2[mid]>val)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
*/
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    s(T);
	FOR(i,0,T)
	{
		s(a[i]);s(b[i]);s(c[i]);s(d[i]);
	}
	pos1=0, pos2=0;
	FOR(i,0,T)
	{
		FOR(j,0,T)
		{
			m=a[i]+b[j];
			v1[pos1++]=m;
			m=(c[i]+d[j])*-1;
			v2[pos2++]=m;
		}
	}// 56 -2 -10 -72 -86
	sort(v1,v1+pos1);sort(v2,v2+pos2);
	int tmp,cnt1,cnt2,ans=0;
	/*
	FOR(i,0,pos1)
		cout<<v1[i]<<", ";
	cout<<endl<<endl;
	FOR(i,0,pos1)
		cout<<v2[i]<<", ";
	*/
	for(int i=0; i<pos1;)
	{
		tmp=v1[i];
		cnt1=0;
		while(v1[i]==tmp && i<pos1)
			i++, cnt1++;
		cnt2=binarysrch(tmp);
		//error(tmp);		error(cnt1);		error(cnt2);cout<<endl;
		//if(cnt1>0 && cnt2>0)
			//error(tmp);
		ans+=(cnt1*cnt2);
	}
	cout<<ans;
    return 0;
}
