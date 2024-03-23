#include <cstdio>
using namespace std;
#define Rep(i, t) for(int i = (0); i < (t); i++)
int o[10];

int main() {
    int T;
    scanf("%d",&T);
    Rep(i,T){
        int n, k;
        scanf("%d %d",&n,&k);
        if(n%k==0){
            o[i]=n*n*(k-1)/2/k;
        }else{
            int n_div_k = n / k;
            int n_mod_k = n % k;
            int k_minus_n_mod_k = k - n_mod_k;
            o[i] = n_div_k * n_mod_k * (n_div_k + 1) * k_minus_n_mod_k + n_div_k * n_div_k * (k_minus_n_mod_k - 1) * k_minus_n_mod_k / 2 + n_mod_k * (n_mod_k - 1) * (n_div_k + 1) * (n_div_k + 1) / 2;        }
    }
    Rep(i,T){printf("%d\n",o[i]);}
    return 0;
}
//((n/k)*(n%k)*(n/k+1)*(k-n%k)+0.5*(n/k)*(n/k)*(k-n%k-1)*(k-n%k)+0.5*(n%k)*(n%k-1)*(n/k+1)*(n/k+1))