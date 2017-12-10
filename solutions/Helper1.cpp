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

//#include<bits/stc++.h>
#define sd(n) scanf("%d",&n)
typedef long long LL;
typedef struct ll
{
    int leftc;
    int rightc;
    struct ll * left;
    struct ll * right;
}node;

node * insert(node * root, unsigned int n, int level)
{
    if(level==-1)return root;
    unsigned int x=((n>>level)&1);
    //error(x);
    if(x)
    {
        root->rightc++;
        if(root->right==NULL)
        {
            root->right=(node *)malloc(sizeof(node));
						root->right->left=root->right->right=NULL;
            root->right->leftc=root->right->rightc=0;
        }
        root->right=insert(root->right,n,level-1);
    }
    else
    {
        root->leftc++;
        if(root->left==NULL)
        {
            root->left=(node *)malloc(sizeof(node));
						root->left->left=root->left->right=NULL;
            root->left->leftc=root->left->rightc=0;
        }
        root->left=insert(root->left,n,level-1);
    }
    return root;
}
unsigned int query( node * root, unsigned int n, int level, unsigned int k)
{
    if(level==-1 || root==NULL)return 0;
    unsigned int p=((n>>level)&1);
    unsigned int q=((k>>level)&1);
    if(q)
    {
        if(p==0)return root->leftc+query(root->right,n,level-1,k);
        else return root->rightc+query(root->left,n,level-1,k);
    }
    else
    {
        if(p==0)
            return query(root->left,n,level-1,k);
        else
            return query(root->right,n,level-1,k);
    }
}
int main()
{
    int t;
    sd(t);
    cout<<t<<endl;
    while(t--)
    {
        node * root;
        root=(node *)malloc(sizeof(node));
        root->left=root->right=NULL;
        root->leftc=root->rightc=0;
        root=insert(root,0,20);
        unsigned int n,i,j,p=0,x,q,k;
        long long int ans=0;
        scanf("%u%u",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf("%u",&x);
            q=p^x;
            ans+=(LL)(query(root,q,20,k));
            root=insert(root,q,20);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
int n, m;

typedef struct node
{
	int leftc, rightc;
	node *left, *right;
};

node * newnode()
{
	node * tmp;
	tmp=new node;
	tmp->left=tmp->right=NULL;
	tmp->leftc=tmp->rightc=0;
	return tmp;
}

node* insert(node * root,int val, int level)
{
	if(level==-1)return root ;
	int tmp=((val>>level)&1);
	//error(tmp);
	if(tmp)
	{
		root->rightc+=1;
		if(!root->right)
		{
			root->right=newnode();
		}
		root->right=insert(root->right, val, level-1);
	}
	else
	{
		root->leftc+=1;
		if(!root->left)
		{
			root->left=newnode();
		}
		root->left=insert(root->left, val, level-1);
	}
	return root;
}
int query(node *root, int q, int k, int level)
{
	if(level==-1 || root==NULL)return 0;
	int a=((q>>level)&1);
	int b=((k>>level)&1);
	if(b==1)
	{
		if(a==1)
			return root->rightc+query(root->right, q, k, level-1);
		else
			return root->leftc+query(root->left, q, k, level-1);
	}
	else
	{
		if(a==1)
			return query(root->right, q, k, level-1);
		else
			return query(root->left, q, k, level-1);
	}
}
int main()
{
    int t;
    s(t);
    while(t--)
    {
        node * root;
        root=(node *)malloc(sizeof(node));
        root->left=root->right=NULL;
        root->leftc=root->rightc=0;
        root=insert(root,0,20);
        unsigned int n,i,j,p=0,x,q,k;
        long long int ans=0;
        scanf("%u%u",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf("%u",&x);
            q=p^x;
            ans+=(LL)(query(root,q,20,k));
            root=insert(root,q,20);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T,k,x, q;
	s(T);
	while(T--)
	{
		s(n); s(k);
		long long ans=0;
		node* root=newnode();
		root=insert(root, 0, 20);
		int p=0;
		FOR(i,0,n)
		{
			s(x);
			q=p^x;
			ans+=(long long)(query(root,q,k,20));
			root = insert(root, q,20);
			p=q;
		}
		cout<<ans<<endl;
	}
	return 0;
}
*/
/*

*/
