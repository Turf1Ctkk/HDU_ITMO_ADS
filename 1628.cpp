#include<bits/stdc++.h>
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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)
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
int res=0;

int main() {
    int m=read(),n=read(),k=read();
    vector<pair<int,int>> points;vector<pair<int,int>> single;
    points.push_back({1,0});
    Rep(i,k){
        int a=read(), b=read();
        points.push_back({a,b});
    }
    points.push_back({m,n+1});
    sort(points.begin(),points.end());
    rep(i,1,points.size()){
        int dr=points[i].first-points[i-1].first;int dc=points[i].second-points[i-1].second;
        if(dr==0){  //same row
            if(dc==2) single.push_back({points[i-1].first,points[i-1].second+1});
            else if(dc>2) res++;
        }
        else{
            if(n>1) res+=dr-1;
            else if(dr==2) single.push_back({points[i-1].first+1,1}); //must 1 since point (1,0)
            if(points[i].second==2) single.push_back({points[i].first,1});
            else if(points[i].second>2) res++;
            if(points[i-1].second==n-1) single.push_back({points[i-1].first,n});
            else if(points[i-1].second<n-1) res++;
        }
    }
    points.push_back({0,1});points.push_back({m+1,n});
    sort(points.begin(),points.end(),[](pair<int,int>a,pair<int,int>b){return a.second==b.second?a.first<b.first:a.second<b.second;});
    rep(i,2,points.size()-1){
        int dr=points[i].first-points[i-1].first;int dc=points[i].second-points[i-1].second;
        if(dc==0){  //same column
            if(dr==2) single.push_back({points[i-1].first+1,points[i-1].second});
            else if(dr>2) res++;
        }
        else{
            if(m>1) res+=dc-1;
            else if(dc==2) single.push_back({1,points[i-1].second+1});
            if(points[i].first==2) single.push_back({1,points[i].second});
            else if(points[i].first>2) res++;
            if(points[i-1].first==m-1) single.push_back({m,points[i-1].second});
            else if(points[i-1].first<m-1) res++;
        }
    }
    sort(single.begin(),single.end());
    res+=single.end()-unique(single.begin(),single.end());
    write(res);
    return 0;
}