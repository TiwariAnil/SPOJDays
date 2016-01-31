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
    for(int i=0; i<n; i++)
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
using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

template <class T> string toStr(const T &x)
{
    stringstream s;
    s << x;
    return s.str();
}
template <class T> int toInt(const T &x)
{
    stringstream s;
    s << x;
    int r;
    s >> r;
    return r;
}

#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const int N = 50005;
// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// rank = The inverse of the suffix array. rank[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> rank[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if rank[i] < rank[j]

int str[N]; //input
int rank[N], pos[N]; //output
int cnt[N], next[N]; //internal
bool bh[N], b2h[N];

bool smaller_first_char(int a, int b)
{
    return str[a] < str[b];
}

void SuffixSort(int n)
{
    //sort suffixes according to their first character
    for (int i=0; i<n; ++i)
    {
        pos[i] = i;
    }
    sort(pos, pos + n, smaller_first_char);
    //{pos contains the list of suffixes sorted by their first character}

    for (int i=0; i<n; ++i)
    {
        bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1)
    {
        //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
        int buckets = 0;
        for (int i=0, j; i < n; i = j)
        {
            j = i + 1;
            while (j < n && !bh[j]) j++;
            next[i] = j;
            buckets++;
        }
        if (buckets == n) break; // We are done! Lucky bastards!
        //{suffixes are separted in buckets containing strings starting with the same h characters}

        for (int i = 0; i < n; i = next[i])
        {
            cnt[i] = 0;
            for (int j = i; j < next[i]; ++j)
            {
                rank[pos[j]] = i;
            }
        }

        cnt[rank[n - h]]++;
        b2h[rank[n - h]] = true;
        for (int i = 0; i < n; i = next[i])
        {
            for (int j = i; j < next[i]; ++j)
            {
                int s = pos[j] - h;
                if (s >= 0)
                {
                    int head = rank[s];
                    rank[s] = head + cnt[head]++;
                    b2h[rank[s]] = true;
                }
            }
            for (int j = i; j < next[i]; ++j)
            {
                int s = pos[j] - h;
                if (s >= 0 && b2h[rank[s]])
                {
                    for (int k = rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                }
            }
        }
        for (int i=0; i<n; ++i)
        {
            pos[rank[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n; ++i)
    {
        rank[pos[i]] = i;
    }
}
// End of suffix array algorithm

// Algorithm GetHeight
// input: A text A and its suffix array Pos
//    1 for i:=1 to n do
//    2     Rank[Pos[i]] := i
//    3 od
//    4 h:=0
//    5 for i:=1 to n do
//    6     if Rank[i] > 1 then
//    7        k := Pos[Rank[i]-1]
//    8        while A[i+h] = A[j+h] do
//    9           h := h+1
//    10       od
//    11       Height[Rank[i]] := h
//    12       if h > 0 then h := h-1 fi
//    13    fi
//    14 od
int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n)
{
    for (int i=0; i<n; ++i) rank[pos[i]] = i;
    height[0] = 0;
    for (int i=0, h=0; i<n; ++i)
    {
        if (rank[i] > 0)
        {
            int j = pos[rank[i]-1];
            while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
            height[rank[i]] = h;
            if (h > 0) h--;
        }
    }
}


string s;

void solve()
{
    int n = s.size();
    for (int i=0; i<n; ++i)
        str[i] = s[i];

    SuffixSort(n);
    getHeight(n);
    long long ans = 0;
    for (int i=0; i<n; ++i)
    {
        ans += n - pos[i] - height[i];
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;

        solve();
        error("pos[]");
        FOR(i,0, 8)
        {
            cout<<pos[i]<<", ";
        }
        cout<<endl;
        error("rank[]");
        FOR(i,0, 8)
        {
            cout<<rank[i]<<", ";
        }
        cout<<endl;
        error("pos[]");
        FOR(i,0, 8)
        {
            cout<<height[i]<<", ";
        }
    }

    return 0;
}
