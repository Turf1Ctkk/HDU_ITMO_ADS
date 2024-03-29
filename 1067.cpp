#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <sstream>
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

vector<string> sep(string p) {
    stringstream s(p);
    vector<string> res;
    string r;
    while (getline(s,r,'\\')) res.push_back(r);
    return res;
}

class DirMap{
    map<string, DirMap> subdir;
public:
    void add(vector<string> p){
        if(p.empty()) return;
        string parent=p[0];
        vector<string> child(p.begin()+1, p.end());
        subdir[parent].add(child);
    }
    void list(int h=0)const{
        for(const auto& dir:subdir){
            printf("%*s%s\n", h, "", dir.first.c_str());
            dir.second.list(h+1);
        }
    }
};

int main() {
    int N;
    DirMap directory;
    scanf("%d\n",&N);
    string p;
    Rep(i,N) {
        getline(cin, p);
        vector<string> res=sep(p);
        directory.add(res);
    }
    directory.list();
    return 0;
}