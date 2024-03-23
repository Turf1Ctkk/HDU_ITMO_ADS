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


struct Point {
    LL x, y;
    int id;
};
vector<Point> points;
//theta p1 < p2 ?
bool cross(Point p1, Point p2){
    return ((p1.x-points[0].x)*(p2.y-points[0].y)-(p2.x-points[0].x)*(p1.y-points[0].y)) >= 0;
}


int main() {
    LL X_MAX=1000001;LL Y_MAX=1000001;

    int N, leftlowID;
    scanf("%d", &N);
    points.resize(N);
    Rep(i, N) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i+1;
        if(points[i].x < X_MAX || (points[i].x == X_MAX && points[i].y < Y_MAX))
        {
            leftlowID=points[i].id;
            X_MAX=points[i].x;
            Y_MAX=points[i].y;
        }
        
    }

    swap(points[leftlowID-1], points[0]);

    sort(points.begin()+1, points.end(), cross);


    printf("%d %d",leftlowID, points[N/2].id);

    return 0;
}