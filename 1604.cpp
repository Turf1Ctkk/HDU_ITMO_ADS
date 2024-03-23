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
//
struct sign{
    int quant;
    int id;
};
bool cmp(sign a, sign b){
    return a.quant > b.quant;
}

int main() {
    int n;
    int index, sum=0;
    scanf("%d", &n);
    sign a[n];
    Rep(i, n){
        cin >> a[i].quant;
        a[i].id=i+1;
        sum += a[i].quant;
    }

    int res[sum];
    sort(a,a+n,cmp);
    int factor=a[0].quant;

    Rep(i, n){
        Rep(j, a[i].quant){
            res[index++]=a[i].id;
        }
    }
    Rep(i, factor)
    {
        for (int j = i; j < index; j+=factor){
           cout << res[j] << " ";
        }
    }
    return 0;
}