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

int main() {
    int n; int pt1=0; int pt2=0;
    scanf("%d",&n);
    int r[n+1],st[n+1]; //st simulate stack
    Rep(i,n) scanf("%d",r+i);
    For(i,1,n){ st[++pt1]=i;
        while(pt1&&st[pt1]==r[pt2]){pt1--;pt2++;}
    }
    if(!pt1) printf("Not a proof");
    else printf("Cheater");
    return 0;
}