#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(a, i) for (edge *i = head[a]; i; i = i->prev)
using namespace std;
typedef long long ll;
int dep[50007];
int fa[50007][27];
int cost[50007][27];
int n, m;
struct edge {
    edge *prev;
    int to, weight;
} buf[150007], *head[50007], *cur;
void addedge(int a, int b, int wei) {
    cur->to = b;
    cur->weight = wei;
    cur->prev = head[a];
    head[a] = cur++;
}
void dfs(int root) {
    dep[root] = dep[fa[root][0]] + 1;
    iterate(root, i) {
        if (i->to != fa[root][0]) {
            fa[i->to][0] = root;
            cost[i->to][0] = i->weight;
            dfs(i->to);
        }
    }
}
void init() {
    for (int i = 1; i < 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
            cost[j][i] = cost[j][i - 1] + cost[fa[j][i - 1]][i - 1];
        }
    }
}
int lca(int a, int b) {
    if (dep[a] > dep[b]) {
        std::swap(a, b);
    }
    int delta = dep[b] - dep[a], cnt = 0;
    int resu = 0;
    for (cnt = 17; delta < (1 << cnt); cnt--);
    for (; delta > 0; cnt--) {
        if ((delta >> cnt) & 1) {
            resu += cost[b][cnt];
            b = fa[b][cnt];
            delta -= (1 << cnt);
        }
    }
    // printf("   %d %d\n", dep[a], dep[b]);
    if (a == b) return resu;
    for (int i = 18; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            resu += cost[a][i];
            resu += cost[b][i];
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    resu += cost[a][0] + cost[b][0];
    return resu;
    return fa[a][0];
    // printf("%d %d\n", dep[a], dep[b]);
    return 0;
}
int main() {
    cur = buf;
    memset(fa, 0, sizeof(fa));
    scanf("%d", &n);
    int u, v, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d", &u, &v, &c);
        addedge(u + 1, v + 1, c);
        addedge(v + 1, u + 1, c);
    }
    dfs(1);
    init();
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u + 1, v + 1));
    }
    // for (int i = 1; i <= n; ++i) {
    //     printf("%d\n", dep[i]);
    // }
    return 0;
}