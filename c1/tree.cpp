#include <iostream>
#include <cstdio>
#include <cstring>
#define iterate(_a, _i) for (edge *_i = head[_a]; _i; _i = _i->prev)
#define CLEAR(x) memset(x, 0, sizeof(x))
using namespace std;
struct edge {
  int to;
  edge *prev;
} *head[200007], buf[400007], *cur;
struct iptcase {
  int u, v;
  int lu, lv;
  int iul, iur, ivl, ivr;
} ipt[200007];
int n;
int poss[11];
inline int getc() {
  char c;
  int rtn = 1;
  while ((c = getchar()) != '?');
  while ((c = getchar()) == '?') ++rtn;
  return rtn;
}

void addedge(int a, int b) {
  cur->to = b;
  cur->prev = head[a];
  head[a] = cur++;
}

void init() {
  CLEAR(head);
  CLEAR(buf);
  cur = buf;
}

int genIntervalLeft(int pcnt) {
  int rtn = 1;
  while ((pcnt--) - 1) {
    rtn *= 10;
  }
  return rtn;
}

int genIntervalRight(int pcnt) {
  int rtn = 9;
  while ((pcnt--) - 1) {
    rtn *= 10;
    rtn += 9;
  }
  return std::min(n, rtn);
}

int main() {
  // freopen("tree.in", "r", stdin);
  // freopen("tree.out", "w", stdout);
  puts("-1");
  scanf("%d", &n);
  int tmp = 1, tn;
  tn = n;
  while (tn) {
    poss[tmp] = tn % 10;
    tmp++;
  }
  tmp--;

  for (int i = 0; i < n; ++i) {
    ipt[i].lu = getc();
    ipt[i].lv = getc();
    ipt[i].iul = genIntervalLeft(ipt[i].lu);
    ipt[i].iul = genIntervalRight(ipt[i].lu);
    ipt[i].ivl = genIntervalLeft(ipt[i].lv);
    ipt[i].ivl = genIntervalRight(ipt[i].lv);

  }
  return 0;
}
