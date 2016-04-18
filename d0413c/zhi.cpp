#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#define iterate(a, i) for (edge *i = head[a]; i; i = i->prev)
using namespace std;
std::stack<int> stk;
int n, m;
int circur = 0;
int locator[1000007];
int cnter[1000007];
char instack[1000007];
int dfseq;
int dfn[1000007];
int low[1000007];
struct edge {
    edge *prev;
    int to;
} buf[10000007], *cur, *head[1000007];

void addedge(int a, int b) {
    cur->to = b;
    cur->prev = head[a];
    head[a] = cur++;
}
void init() {
    memset(buf, 0, sizeof(buf));
    memset(head, 0, sizeof(head));
    memset(locator, 0, sizeof(locator));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(instack, 0, sizeof(instack));
    memset(cnter, 0, sizeof(cnter));
    cur = buf;
    circur = 0;
    dfseq = 0;
}
void dfs(int root) {
    dfn[root] = low[root] = ++dfseq;
    instack[root] = 1;
    stk.push(root);
    iterate(root, i) {
        if (instack[i->to] == 0) {
            dfs(i->to);
            low[root] = std::min(low[root], low[i->to]);
        } else if (instack[i->to] == 1) {
            low[root] = std::min(low[root], dfn[i->to]);
        }
    }
    if (low[root] == dfn[root]) {
        circur++;
        while (!stk.empty() && stk.top() != root) {
            locator[stk.top()] = circur;
            instack[stk.top()] = 2;
            stk.pop();
        }
        if (!stk.empty()) {
            locator[stk.top()] = circur;
            instack[stk.top()] = 2;
            stk.pop();
        }
    }
}
void tarjan() {
    for (int i = 1; i <= n; i++) {
        if (instack[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cnter[locator[i]]++;
    }
}
int main() {
    freopen("zhi.in", "r", stdin);
    freopen("zhi.out", "w", stdout);
    init();
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        addedge(a, b);
    }
    tarjan();
    for (int i = 1; i <= n; i++) {
        printf("%d\n", cnter[locator[i]]);
    }
    return 0;
}
