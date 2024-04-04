#include <bits/stdc++.h>
using namespace std;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define MAX 50001
#define HASH 1000003
// hash store + priority queue of Dijkstra
int N, cost[11], p[HASH], n[HASH], d[MAX], pre[MAX];
char tel[MAX][11], curtel[11];

struct Node {
    int id, dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

priority_queue<Node> pq;

int mulHash(char *s) {
    int x = 0;
    while (*s) x = x * 131 + *(s++);
    return (x & 0x7fffffff) % HASH;
}

int find(char *s) {
    int x = mulHash(s);int i;
    for (i = p[x]; i != -1; i = n[i]) if (strcmp(tel[i], s) == 0) break;
    return i;
}

void change(int t) {
    Rep(i, 10) {
        For(j, 48, 57) {
            if (j != curtel[i]) {
                curtel[i] = j;
                int y = find(curtel);
                if (y != -1 && d[t] + cost[i] < d[y]) {
                    d[y] = d[t] + cost[i];
                    pre[y] = t;
                    pq.push({y, d[y]});
                }
                curtel[i] = tel[t][i];
            }
        }
    }
}

void swap(int t) {
    Rep(i, 10) {
        For(j, i + 1, 9) {
            if (curtel[i] != curtel[j]) {
                char ch = curtel[i]; curtel[i] = curtel[j]; curtel[j] = ch;
                int y = find(curtel);
                if (y != -1 && d[t] + cost[i] < d[y]) {
                    d[y] = d[t] + cost[i];
                    pre[y] = t;
                    pq.push({y, d[y]});
                }
                ch = curtel[i]; curtel[i] = curtel[j]; curtel[j] = ch;
            }
        }
    }
}

void recursion(int c, int n) {
    if (c == 1) {
        cout << n << " " << c;
        return;
    }
    recursion(pre[c], n + 1);
    cout << " " << c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> N) {
        Rep(i, 10) cin >> cost[i];
        memset(p, -1, sizeof(p));
        For(i, 1, N) {
            cin >> tel[i];
            int j = mulHash(tel[i]);
            n[i] = p[j];
            p[j] = i;
        }

        memset(d, 0x3f, sizeof(d));
        d[1] = 0;
        pre[1] = 0;
        pq.push({1, 0});

        while (!pq.empty()) {
            Node node = pq.top(); pq.pop();
            int t = node.id;
            if (node.dist > d[t]) continue;
            strcpy(curtel, tel[t]);
            change(t);
            swap(t);
        }
        if (d[N] == 0x3f3f3f3f) cout << "-1";
        else {
            cout << d[N] << '\n';
            recursion(N, 1);
            cout << '\n';
        }
    }
    return 0;
}
