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
int arr[20];
struct node
{
	int count;
	node *next[10];
} *root;
node* newnode()
{
	node *nd;
	nd=new node;
	nd->count=0;
	FOR(i,0,10)nd->next[i]=NULL;
	return nd;
}
void ins(string inp)
{
	if(root==NULL)
	{
		root=newnode();
	}
	node *rot=root;
	int flag=0;
	FOR(i,0,inp.length())
	{
		int curr=inp[i]-'0';
		if(rot->next[curr]==NULL)
		{
			flag=1;
			rot->next[curr]=newnode();
			rot=rot->next[curr];
		}
		else
		{
			rot=rot->next[curr];
		}
	}
	rot->count++;
}
bool chek(string inp)
{
	node *rot=root;
	FOR(i,0,inp.length())
	{
		int curr=inp[i]-'0';
		if(rot->next[curr]->count!=0)
		{
			if(i!=inp.length()-1)
				return false;
			else if(rot->count>1)
				return false;

		}
		rot=rot->next[curr];
	}
		return true;
}
/*
void output(int p)
{
	FOR(i,0,p+1)
		cout<<arr[i];
	cout<<endl;
}
void disp(node *root, int p)
{

	FOR(i,0,10)
		if(root->next[i]!=NULL)
		{
			//error(i);
			arr[p]=i;
			if(root->next[i]->tell)
			{
				//error(p);
				output(p);
			}
			disp(root->next[i], p+1);
		}

}*/
string a[10009];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T, flag=0;
    //s(T);

	cin>>T;
	while(T--)
	{
		s(n);flag=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			ins(a[i]);
		}
		FOR(i,0,n)
		{
			if(chek(a[i])==false){
				flag=1; break;
			}
		}
		if(flag==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		root=NULL;
		//delete root;
	}
	//disp(root, 0);
	//delete root;
    return 0;
}
