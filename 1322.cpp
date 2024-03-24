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

char str[100000];
int N;

struct Letter{
	char ch;
	int id;
};

bool cmp(Letter l1, Letter l2) {
    return l1.ch == l2.ch && l1.id<l2.id || l1.ch < l2.ch;
}
 
int main()
{
    scanf("%d",&N);
    int index = N - 1;
    scanf("%s",str);
    int length = 0;
    while(str[++length]);

    Letter letters[length];

    Rep(i,length) {
        letters[i].ch=str[i];
        letters[i].id=i;
    }
    sort(letters, letters+length, cmp);

    Rep(i, length){
        index=letters[index].id, printf("%c",str[index]);
    }
    return 0;
}