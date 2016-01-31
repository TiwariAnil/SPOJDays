
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define s(n)                        scanf("%d",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d",n)
using namespace std;
int n, m ;
string B;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int modx(string B, int d)
{
	int x=0;
	FOR(i,0,B.length())
	{
		x=(x*10+(B[i]-'0')) % d;
	}
	return x;
}

int main()
{
	int T;
    s(T);
    int a;
	while(T--)
	{
		s(a); cin>>B;
		if(a==0)
		{
			cout<<B<<endl;
		}
		else
			cout<<gcd(a, modx(B, a))<<endl;
		//cout<<modx(B, a);//);
	}
    return 0;
}
