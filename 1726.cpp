// Time complexity: O(N log N)
// Space complexity: O(log N)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)

inline int read(){
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main()
{
    LL res=0;
    int n=read();
    int x[n], y[n];
    Rep(i,n) x[i]=read(),y[i]=read();
    sort(x,x+n);sort(y,y+n);
    Rep(i,n){
        LL dis=x[i+1]+y[i+1]-x[i]-y[i];
        dis*=(i+1);dis*=(n-i-1);              //multiply together will WA #10 :(
        res+=dis;
    }
    res*=2;res/=n;res/=(n-1);
    printf("%lld", res);
    return 0;
}
