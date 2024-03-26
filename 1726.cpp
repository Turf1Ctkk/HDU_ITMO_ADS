#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
using namespace std;
typedef long long LL;
typedef double DB;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)

int main()
{
    int n;
    LL res=0;
    scanf("%d", &n);
    int x[n], y[n];
    Rep(i,n) scanf("%d %d", &x[i],&y[i]);
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