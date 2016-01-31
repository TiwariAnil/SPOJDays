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
inline int haint()
{
    int h;
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

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const int N = 500005;

int str[N]; // input
int rank[N], pos[N]; // output
int cnt[N], next[N]; // internal
bool bh[N], b2h[N];  // buckets
string s;

bool smaller_first_char(int a, int b)
{
    return str[a] < str[b];
}

void SuffixSort(int n)
{
    // sort suffixes according to their first character
    for (int i=0; i<n; ++i)
    {
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    // {pos contains the list of suffixes sorted by their first character}

    for (int i=0; i<n; ++i)
    {
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]]; // not equal then false
        b2h[i] = false;
    }


//	h=1,2,4,8... chars
    for (int h = 1; h < n; h <<= 1) // log n
    {
// bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]
        int buckets = 0;
        // BUCKETS CREATION
        for (int i=0, j; i < n; i = j)
        {
            j = i + 1;
            while (j < n && !bh[j])
				j++;                //we search for pos[j-1]!=pos[j] (h chars at a time)
            next[i] = j;            //Hence, a new bucket is made.
            buckets++;
        }
        if (buckets == n) break; //  We are done! Lucky bastards!

//suffixes are separted in buckets containing strings starting with the same h characters}
        for (int i = 0; i < n; i = next[i]) //For all buckets
        {
            cnt[i] = 0;                     //cnt[bucket]=0
            for (int j = i; j < next[i]; ++j) // All substring in same bucket have same rank
            {                                 // i.e rank = i
                rank[pos[j]] = i;             //pos[i] = k <==> rank[k] = i
            } // Actually j or k is the suffix postions, ^^^^see
        }

        cnt[rank[n - h]]++;                 //h chars are considered for now
        b2h[rank[n - h]] = true;
        for (int i = 0; i < n; i = next[i]) // for each bucket
        {
            for (int j = i; j < next[i]; ++j) // elements in each bucket
            {
                int s = pos[j] - h;
                if (s >= 0)
                {
                    int head = rank[s];     // rank of suffix str[s..n-1]
                    rank[s] = head + cnt[head]++; // rank of suffix str[s..n-1] is incrementd to new postion
                    b2h[rank[s]] = true; // rank was updated in
                }
            }
            for (int j = i; j < next[i]; ++j)
            {
                int s = pos[j] - h;
                if (s >= 0 && b2h[rank[s]])// if still there is diff ranks of 2 suffix
                {
                    for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) // for all next with same
						b2h[k] = false;               // rank in one bucket
                }
            }
        }
		// For each h chars once only
        for (int i=0; i<n; ++i)
        { // bh -> buckets of h length, b2h -> buckets of 2*h length
            pos[rank[i]] = i; // update rank
            bh[i] |= b2h[i]; // update buckets
        }

    }
    //Finally pos[] is the Suffix array ! and rank[] is inverse !
    for (int i=0; i<n; ++i)
    {
        rank[pos[i]] = i; //
    }
}

void solve()
{
    int n = s.size();
    for (int i=0; i<n; ++i)
        str[i] = s[i];
    SuffixSort(n);
	FOR(i,0,n)
	{
		printf("%d\n",pos[i]);
	}
}

int main()
{
    int t;
   // cin >> t;
   // while (t--)
    //{
        cin >> s;
        //s+=s;
     //   error(s);
        solve();
    //}

    return 0;
}
