#include <iostream>
#include <cstdio>
#include <cstring>
#define pick(a, b) ((a >> (b - 1)) & 1)
#define EPS 1e-7
using namespace std;
typedef long long ll;
int n;
struct trie {
    char e;
    trie *ch[2];
    trie() {
        e = 0;
        ch[0] = ch[1] = NULL;
    }
} buf[10000007], *cur;
void insert(ll number) {
    trie *cursor = buf;
    for (int i = 32; i > 0; i--) {
        if (cursor->ch[pick(number, i)]) {
            cursor = cursor->ch[pick(number, i)];
        } else {
            cursor->ch[pick(number, i)] = cur;
            cursor = cur++;
        }
    }
    cursor->e++;
}
ll solve() {
    ll rtn = 0;
    trie *lc = buf, *rc = buf;
    for (int i = 0; i < 32; i++, rtn <<= 1) {
        if (lc->ch[0] && rc->ch[1]) {
            lc = lc->ch[0];
            rc = rc->ch[1];
            rtn |= 1;
        } else if (rc->ch[0] && lc->ch[1]) {
            rc = rc->ch[0];
            lc = lc->ch[1];
            rtn |= 1;
        } else {
            if (lc->ch[0]) {
                lc = lc->ch[0];
            } else {
                lc = lc->ch[1];
            }
            if (rc->ch[0]) {
                rc = rc->ch[0];
            } else {
                rc = rc->ch[1];
            }
        }
    }
    return rtn >> 1;
}
int main() {
    while (~scanf("%d", &n)) {
        memset(buf, 0, sizeof(buf));

        cur = buf + 1;
        ll temp;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &temp);
            insert(temp);
        }
        printf("%lld\n", solve());
    }
    return 0;
}
