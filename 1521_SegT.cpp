#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)
int Tree[400000];
int cur;

void update(int i) {
    Tree[i]=Tree[i*2]+Tree[i*2+1];
}

void generate(int l, int r, int i) {
    Tree[i]=r-l+1;
    if(l==r) return;
    int m=(l+r)/2;
    generate(l,m,i*2);
    generate(m+1,r,i*2+1);
}

int sumInArea(int left, int right, int l, int r, int i) {
    if(left<=l&&right>=r) return Tree[i];
    int m=(l+r)/2;int res=0;
    if(left<=m) res+=sumInArea(left,right,l,m,i*2);
    if(right>m) res+=sumInArea(left,right,m+1,r,i*2+1);
    return res;
}

void remove(int p, int l, int r, int i) {
    if(l==r) {Tree[i]=0;cur=l;return;}
    int m=(l+r)/2;
    if(p<=Tree[i*2]) remove(p,l,m,i*2); //judge first half
    else remove(p-Tree[i*2],m+1,r,i*2+1);
    update(i);
}

int main() {
    int n,k; scanf("%d%d",&n,&k);
    generate(1,n,1);
    Rep(i,n) {
        int p;
        if(cur==0) p=k;//1<=K<=N
        else {
            int temp=sumInArea(1,cur,1,n,1);
            p=(temp+k)%Tree[1];
        }
        if(p==0) p=Tree[1];
        remove(p,1,n,1);
        printf("%d ",cur);
    }
    return 0;
}
