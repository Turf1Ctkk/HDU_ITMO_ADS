#include <bits/stdc++.h>
#include <cstdio>
#include <string>
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
struct c
{
    string name;
    LL money;
    c(string s, long long m):name(s),money(m) {}
    bool operator< (c c1)const{return this->money==c1.money?this->name<c1.name:this->money>c1.money;}
};
void update(set<c>& city, map<string, c*>& cityp, string s, long long money,bool b) {
	map<string, c*>::iterator p = cityp.find(s);
    if(b) {
        if(p == cityp.end()) {
            c* newcity = new c(s, money);
            city.insert(*newcity); cityp.insert({ newcity->name, newcity });
        }
        else {
            city.erase(*p->second);
            p->second->money+=money;
            city.insert(*p->second);
        }
    }
    else {
        c *tempCity = new c(s, p->second->money - money);
        city.erase(*p->second);
        delete p->second;
        p->second = tempCity;
        if (tempCity->money == 0) {
            cityp.erase(p);
            return;
        }
        city.insert(*tempCity);
    }
}
void resupdate(set<c>& city,map<string,int>& res,int dur){
    string s;set<c>::iterator p=city.begin();
    if(city.empty() || city.size()>=2 && p->money-(++p)->money==0) return;
    s=city.begin()->name;
    map<string,int>::iterator p1=res.find(s);
    if(p1==res.end()) res.insert({s,dur});
    else p1->second+=dur;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    map<string,pair<string,LL>> Billionaries;
    set<c>city;
    map<string,c*>cityp;
    int n,m,k;
    cin>>n;
    Rep(i,n) {
        string s1;string s2;LL m;
        cin>>s1>>s2>>m;
        Billionaries.insert({s1,make_pair(s2,m)});
        update(city,cityp,s2,m,true);
    }
    cin>>m>>k;
    map<string,int>res;
    int bef;int aft=0;
    Rep(i,k){
        string s1,s2;bef=aft;cin>>aft>>s1>>s2;
        resupdate(city,res,aft-bef);
        map<string,pair<string,LL>>::iterator p;
        p=Billionaries.find(s1);
        LL money=p->second.second;
        update(city,cityp,s2,money,true);
        string last=p->second.first;
        p->second.first=s2;
        update(city,cityp,last,money,false);
    }
    resupdate(city,res,m-aft);
    for (const auto& i : res) {
        if (i.second != 0) cout << i.first << " " << i.second <<'\n';
    }
    return 0;
}