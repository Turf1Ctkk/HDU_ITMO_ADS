#include <cstdio>
#include <cmath>

using namespace std;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)
int p=3;
int matrix[512][512];

void Recursion(int n, int x0, int y0, int dx, int dy){
    if(n==2){
        Rep(i,2){Rep(j,2){
            if(x0+i!=dx || y0+j!=dy){matrix[x0+i][y0+j]=p++/3;}
        }}return;
    }
    Rep(i,2){Rep(j,2){
        if(dx<x0+i*n/2 || dx>=x0+n*(i+1)/2 || dy<y0+j*n/2 || dy>=y0+n*(j+1)/2){
            matrix[x0+n/2+i-1][y0+n/2+j-1]=p++/3;
        }
    }}
    Rep(i,2){Rep(j,2){
        if(x0+i*n/2<=dx && dx<x0+(i+1)*n/2 && y0+j*n/2<=dy && dy<y0+(j+1)*n/2){
        Recursion(n/2, x0+i*n/2, y0+j*n/2, dx, dy);}
        else{
            Recursion(n/2, x0+i*n/2, y0+j*n/2, x0+n/2+i-1, y0+n/2+j-1);
        }
    }}
}

int main() {
    int n, dx, dy;
    scanf("%d %d %d",&n,&dx,&dy);
    int size=pow(2,n);
    Recursion(size, 0, 0, dx-1, dy-1);
    Rep(i,size){Rep(j,size){
        printf("%d ",matrix[i][j]);
        
    }printf("\n");}

    return 0;
}