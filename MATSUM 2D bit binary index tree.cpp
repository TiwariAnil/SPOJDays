// Data Structure includes
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
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}
inline long long haint()
{
    long long h;
    register char c=0;
    while (c<33) c=getchar();// getchar_unlocked();
    h=0;
    while (c>33)
    {
        h=h*10+c-'0';
        c=getchar();// getchar_unlocked();
    }
    return h;
}
using namespace std;

int n,  m, d;
int matrix[1025][1025], mat[1026][1026]; // LL is macro for long long
void update (int x , int y , int val)
{
//    val=val-matrix[x][y]; // This is the value that we must add while updating
    int origy=y;
    while(x<=n)
    {
        y=origy;
        while(y<=n)
        {
            matrix[x][y]+=val;
            y+=y & -y;
        }
        x+=  x & -x;
    }
}

int querry(int x, int y)
{
    int sum=0;
    int origy=y;
    while(x>0)
    {
        y=origy;
        while(y>0)
        {
            sum+=matrix[x][y];
            y-=y& -y;
        }
        x-= x & -x;
    }
    return sum;
}

int main()
{
    int t;
    s(t);       // macro for reading integer
    while(t--)
    {
        s(n);
        fill(matrix,0);
        char s[5]; int x1, y1,x2,y2;
        int val;
        fill(mat, 0);
        while(true)
        {
            scanf("%s",s);
            if(!strcmp(s,"SET"))
            {
                scanf("%d %d %d",&x1,&y1,&val);
                x1++; y1++;
                if (mat[x1][y1] != val)
                {
			 		update(x1,y1,val-mat[x1][y1]);
					mat[x1][y1] = val;
                }
            }
            else if(!strcmp(s,"SUM"))
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++; x2++; y1++; y2++;
                val=(querry(x2,y2)-querry(x1-1,y2)-querry(x2,y1-1)+querry(x1-1,y1-1));
                printf("%d\n",val);
            }
            else
            {
                printf("\n");
                break;
            }
        }
    }
}
/*
int main()
{
    int T;
    scanf("%d", &T);

    for (int cs = 1; cs <= T; cs++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tree[i][j] = mat[i][j] = 0;

        char cmd[10];
        while (scanf(" %s", cmd) == 1 && cmd[0] != 'E')
        {
            if (cmd[1] == 'E')
            {
                int x, y, num;
                scanf("%d %d %d", &x, &y, &num);
                if (mat[x][y] != num)
                {
                    add(x, y, num-mat[x][y]);
                    mat[x][y] = num;
                }
            }
            else
            {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int res = sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
                printf("%d\n", res);
            }
        }
    }
}
*/
