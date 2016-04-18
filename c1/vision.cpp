/**
 * fucked up qwq
 */

#include <iostream>
#include <cstdio>
#define eiterate(_a, _i) for (edge *_i = head[_a]; _i; _i = _i->prev)
#define viterate(_a, _i) for (vls *_i = _a->hd; _i; _i = _i->prev)
#define iabs(x) ((x) > 0 ? (x) : -(x))
using namespace std;

const int MOD = 1000000007;

int n, m;
int global_resu[207];
char vis[207];
struct vls {
  int v;
  vls *prev;
} bufvls[20 * 787 + 7], *curvls;
struct edge {
  int to, c;
  char tag;
  edge *prev;
  vls *hd;
} *head[207], bufeg[787], *cureg;
void init() {
  curvls = bufvls;
  cureg = bufeg;
}
void addedge(int a, int b, int k) {
  int ta;
  cureg->c = k;
  cureg->tag = 0;
  while (k--) {
    scanf("%d", &ta);
    curvls->v = ta;
    curvls->prev = cureg->hd;
    cureg->hd = curvls++;
  }
  cureg->to = b;
  cureg->prev = head[a];
  head[a] = cureg++;
}
int nodesequence[207];
int visionsequence[207];
bool validate(int len) {
  // for (int i = 0; i <= len; ++i) {
  //   printf("%d ", nodesequence[i]);
  // }
  // putchar('\n');
  // for (int i = 0; i <= len; ++i) {
  //   printf("%d ", visionsequence[i]);
  // }
  // putchar('\n');
  // putchar('\n');
  for (int i = 0; i <= len; ++i) {
    if (nodesequence[i] != visionsequence[i]) return false;
  }
  global_resu[len]++;
  global_resu[len] %= MOD;
  return true;
}
void dfs(int root, int pos, int dep) {
  vis[root] = 1;
  nodesequence[dep] = root;
  // printf("!!%d %d\n", pos, dep);
  if (dep > 2 * n) return;
  if (pos == dep + 1 && dep)
    validate(dep);
      // global_resu = (global_resu + 1) % MOD;
  eiterate(root, i) {
    if (i->tag) continue;
    // i->tag = 1;
    int tpp = pos + i->c - 1;
    viterate(i, j) {
      visionsequence[tpp--] = j->v;
    }
    dfs(i->to, pos + i->c, dep + 1);
    // i->tag = 0;
  }
  vis[root] = 0;
}

int main() {
  freopen("vision.in", "r", stdin);
  freopen("vison.out", "w", stdout);
  init();
  scanf("%d %d", &n, &m);
  int u, v, k;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", &u, &v, &k);
    addedge(u, v, k);
  }
  for (int i = 1; i <= n; ++i) {
    dfs(i, 0, 0);
  }
  for (int i = 1; i <= 2 * n; ++i) {
    printf("%d\n", global_resu[i]);
  }
  return 0;
}
