// Time complexity: O(N log N)
// Space complexity: O(log N)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)
struct Point
{
    int x, y, id;
};

int Mdistance(const Point &p1, const Point &p2){
    return (abs(p1.x -p2.x)+abs(p1.y-p2.y));
}
double Angle(const Point &p1, const Point &p2){ //?
    double angle = atan2(p2.y-p1.y,p2.x-p1.x);
    return angle;
}

int main() {
    int N;
    scanf("%d", &N);
    Point points[N];
    scanf("%d %d", &points[0].x, &points[0].y);
    points[0].id=1;
    Point O = points[0];
    For(i, 1, N-1) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].id=i+1;
    }
    sort(points+1, points+N, [O](const Point &p1, const Point &p2) {
        double angle1 = Angle(O, p1);
        double angle2 = Angle(O, p2);
        if (angle1 != angle2) {
            return angle1 < angle2;
        }
        return Mdistance(O, p1) < Mdistance(O, p2);
    });
    printf("%d\n", N);
    printf("%d\n", 1);
    int spl=0;
    For(i, 1, N-2) {
        Point v1 ={points[i].x-O.x, points[i].y-O.y};
        Point v2 ={points[i+1].x-O.x, points[i+1].y-O.y};
        if((v1.x* v2.y - v2.x* v1.y) < 0 || (v1.x* v2.y - v2.x* v1.y) == 0 && (v1.x* v2.x + v1.y* v2.y) < 0){spl=i;}
    }
    For(i, 0, N-2) {
        printf("%d\n", points[(spl+i)%(N-1)+1].id);
    }
    // Rep(i, N){
    //     cout << points[i].x << " " << points[i].y << " " << points[i].id << endl;
    // }
    return 0;
}
