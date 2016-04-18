#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define iterate(a, i) for (edge *i = head[a]; i; i = i->prev)
#define red(a) (buf + ((a - buf) ^ 1))
using namespace std;
int dis[207], gap[207];
int n, m;
struct edge {
    int to, weight;
    edge *prev;
} buf[407], *head[207], *cur;

void addedge(int a, int b, int w) {
    cur->to = b;
    cur->weight = w;
    cur->prev = head[a];
    head[a] = cur++;
}

int dfs(int root, int FLOW) {
    if (root == m) return FLOW;
    int flow = 0, min_dis = m - 1;
    int temp;
    iterate(root, i) {
        if (i->weight) {
            if (dis[root] == dis[i->to] + 1) {
                temp = dfs(i->to, std::min(FLOW - flow, i->weight));
                i->weight -= temp;
                red(i)->weight += temp;
                flow += temp;
                if (dis[1] >= m) return flow;
                if (flow >= FLOW) break;
            }
            min_dis = std::min(min_dis, dis[i->to]);
        }
    }
    if (!flow) {
        --gap[dis[root]];
        if (!gap[dis[root]]) dis[1] = m;
        ++gap[dis[root] = min_dis + 1];
    }
    return flow;
}

int main() {
    cur = buf;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        addedge(s, e, c);
        addedge(e, s, 0);
    }
    gap[0] = m;
    int tt = 0;
    while (dis[1] < m) {
        // printf("%d\n", tt);
        tt += dfs(1, INT_MAX);
    }
    printf("%d\n", tt);
}
