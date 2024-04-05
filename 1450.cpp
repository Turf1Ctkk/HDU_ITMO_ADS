#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define MAXN 501
#define INF INT_MIN

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

struct edge {
  int v, w;
};

int n, m;
vector<edge> e[MAXN];
vector<int> L;
int max_dis[MAXN], in[MAXN];

void toposort() {
  queue<int> S;
  memset(in, 0, sizeof(in));
  For(i,1,n){
    Rep(j,e[i].size()) in[e[i][j].v]++;
  }
  For(i,1,n) if (in[i] == 0) S.push(i);
  while (!S.empty()) {
    int u = S.front();
    S.pop();
    L.push_back(u);
    Rep(i, e[u].size()) if (--in[e[u][i].v] == 0) S.push(e[u][i].v);
    }
}

void dp(int s) {
  toposort();
  fill(max_dis, max_dis + n + 1, INF);
  max_dis[s] = 0;
  Rep(i, L.size()){
    int u = L[i];
    Rep(j, e[u].size()){
        if(max_dis[u] > INF)
            max_dis[e[u][j].v] = max(max_dis[e[u][j].v], max_dis[u] + e[u][j].w);
    }
  }
}

int main() {
    n=read(),m=read();
    Rep(i,m) {
        int u=read();int v=read();int w=read();
        e[u].push_back({v, w});
    }
    int start = read(); int end=read();
    if(e[start].empty()){
        printf("No solution");
        return 0;
    }
    dp(start);
    if (max_dis[end] == INF) {
        printf("No solution");
    } else {
        write(max_dis[end]);
    }
    return 0;
}