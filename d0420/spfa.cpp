#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define iterate(a, i) for (edge *i = head[a]; i; i = i->prev)
using namespace std;
typedef long long ll;

struct edge {
    edge *prev;
    int to;
    int weight;
} buf[2007], *head[207], *cur;

void addedge(int a,int b, int weight) {
    cur->to = b;
    cur->prev = head[a];
    cur->weight = weight;
    head[a] = cur++;
}
int dist[207];
char instack[207];
void spfa(int from) {
    memset(instack, 0, sizeof(instack));
    for (int i = 0; i < 207; ++i) {
        dist[i] = INT_MAX >> 1;
    }
    queue<int> Q;
    dist[from] = 0;
    instack[from] = 1;
    Q.push(from);
    int temp;
    while (!Q.empty()) {
        temp = Q.front();
        iterate(temp, i) {
            if (dist[i->to] > dist[temp] + i->weight) {
                dist[i->to] = dist[temp] + i->weight;
                if (!instack[i->to]) {
                    Q.push(i->to);
                    instack[i->to] = 1;
                }
            }
        }
        instack[temp] = 0;
        Q.pop();
    }
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        cur = buf;
        memset(head, 0, sizeof(head));
        memset(buf, 0, sizeof(buf));
        int a, b, x;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &x);
            addedge(a, b, x);
            addedge(b, a, x);
        }
        int s, t;
        scanf("%d %d", &s, &t);
        spfa(s);
        printf("%d\n", dist[t] == INT_MAX >> 1 ? -1 : dist[t]);
    }
}