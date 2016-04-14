#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(a, b, i) for (edge *i = head[b][a]; i; i = i->prev)
using namespace std;

int dep[2][100007];
char tag[100007];
int fa[2][100007]; 
int n, m;

struct edge {
    edge *prev;
    int to;
} buf[200007], *head[2][100007], *cur;

void addedge(int type, int a, int b) {
    cur->to = b;
    cur->prev = head[type][a];
    head[type][a] = cur++;
}

void dfs(int root, int type) {
    dep[type][root] = dep[type][fa[type][root]] + 1;
    iterate(root, type, i) {
        dfs(i->to, type);
    }
}

int solve(int p1, int p2) {
    memset(tag, 0, sizeof(tag));
    tag[p1] = 1;
    while (p1 >= 1) {
        tag[p1 = fa[0][p1]] =  1;
    }
    while (p2 >= 1) {
        if (tag[p2] == 1) return p2;
        p2 = fa[1][p2];
    }
}

int main() {
    freopen("ming.in", "r", stdin);
    freopen("ming.out", "w", stdout);
    cur = buf;
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[0][i]);
        addedge(0, fa[0][i], i);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[1][i]);
        addedge(1, fa[1][i], i);
    }
    memset(dep, 0, sizeof(dep));
    dep[0][1] = 1;
    dep[1][1] = 1;
    dfs(1, 0);
    dfs(1, 1);
    int p1, p2, p3 = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p1, &p2);
        p1 = (p1 + p3) % n + 1;
        p2 = (p2 + p3) % n + 1;
        p3 = solve(p1, p2);
        printf("%d %d %d\n", p3, dep[0][p1] - dep[0][p3] + 1, dep[1][p2] - dep[1][p3] + 1);
    }
    return 0;
}
