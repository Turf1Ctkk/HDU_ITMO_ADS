#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(i, t) for(int i = (0); i < (t); i++)

struct s
{
    int A, B; double R, C;
};

vector<s> p;
double cur[102];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N, M, S; double V;
    cin >> N >> M >> S >> V;
    cur[S] = V;
    Rep(i, M)
    {
        int A, B; double r1, c1, r2, c2;
        cin >> A >> B >> r1 >> c1 >> r2 >> c2;
        p.push_back({A, B, r1, c1}); p.push_back({B, A, r2, c2});
    }
    Rep(i, N-1) Rep(j, p.size()) cur[p[j].B] = max(cur[p[j].B],(cur[p[j].A]-p[j].C)*p[j].R);
    
    Rep(i, p.size()){
        if((cur[p[i].A]-p[i].C)*p[i].R > cur[p[i].B] + 0.0000001) {cout << "YES"; return 0;}
    }
    cout << "NO"; return 0;
}