#include <cstdio>
#include <vector>
#include <cctype>
#pragma GCC optimize(2)
using namespace std;
#define Rep(i, t) for(int i = (0); i < (t); i++)

int Color[100];
vector<int> adj[100];

bool dfs(int v, int c){
    Color[v]=c;
    for(int i:adj[v]) {
        if(Color[i]==c) return false;
        if(Color[i]==-1 && !dfs(i,1-c)) return false;
    }
    return true;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
inline void write(int x){ 
    if(x==0){putchar('0');return;}
    int len=0,k1=x,c[10005];
    if(k1<0)k1=-k1,putchar('-');
    while(k1)c[len++]=k1%10+'0',k1/=10;
    while(len--)putchar(c[len]);
}
int main() {
    bool flag=true; int a; int N=read();
    Rep(i,N) {
        Color[i]=-1;
        while(1) {
            a=read();
            if(a==0) break;
            adj[i].push_back(--a);
            adj[a].push_back(i);
        }
    }
    for(int i=0;i<N&&flag;++i) if(Color[i]==-1) flag &= dfs(i,0);
    if(!flag) write(-1);
    else Rep(i,N){write(Color[i]);}
    return 0;
}