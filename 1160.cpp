#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define For(i, s, t) for(int i = (s); i <= (t); i++)
// Kruskal
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
inline void writel(int x){ 
    if(x==0){putchar('0');return;}
    int len=0,k1=x,c[10005];
    if(k1<0)k1=-k1,putchar('-');
    while(k1)c[len++]=k1%10+'0',k1/=10;
    while(len--)putchar(c[len]);
    putchar(10);
}
struct node
{
    node* parent;
    int level;
    int id;
    node() : parent(this), level(0) { }
};

struct edge
{
    node* a, *b;
    int w;
    edge(node* a, node* b, int w) : a(a), b(b), w(w) {}
};
vector<node> Node;vector<edge> Edge;vector<edge*> res;
node* find(node* n)
{
    if(n != n->parent)
        n->parent = find(n->parent);
    return n->parent;
}

void Union(node* a, node* b) 
{
    node* p = find(a);
    node* q = find(b);
    if(p->level > q->level) q->parent = p;
    else{
        p->parent = q;
        if(p->level == q->level) q->level++;
    }
}

int main()
{
    int N=read(); int M =read();
    Node.reserve(N+1);Edge.reserve(M);res.reserve(M); 
    For(i,0,N)
    {
        Node.push_back(node());
        Node.back().parent = &Node.back();
        Node.back().id = i;
    }
    Rep(i,M)
    {
        int a = read(); int b = read(); int w = read();
        Edge.emplace_back(&Node[a], &Node[b], w);
    }
    sort(Edge.begin(), Edge.end(), [] (edge& a, edge& b) {
        return a.w < b.w; 
        });
    int m = 0;
    for(edge& edg : Edge)
    {
        if(find(edg.a) != find(edg.b))
        {
            Union(edg.a, edg.b);
            m = max(m, edg.w);
            res.push_back(&edg);
        }
    }
    writel(m);writel(res.size());
    for(edge* e : res){
        write(e->a->id);putchar(32);writel(e->b->id);}
    return 0;
}