#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define isrson(x) (x->parent->ch[0] == x)
#define LEFT 0
#define RIGHT 1
#define update(x) (x->sz = x->ch[0]->sz + x->ch[1]->sz)
#define INF 0x7ffffffe
using namespace std;
const int MXN = 100007;
inline int rnd() {
    return rand() * rand();
}
struct node {
    node *ch[2], *parent;
    int pri, data, sz;
} _root, _nil, *root, *nil, buf[MXN];
node *cur;

node *newnode(int value, node *par) {
    cur->ch[0] = cur->ch[1] = nil;
    cur->parent = par;
    cur->sz = 1;
    cur->pri = rnd();
    cur->data = value;
    return cur++;
}
void init() {
    cur = buf;
    nil = &_nil;
    nil->ch[0] = nil->ch[1] = nil->parent = nil;
    nil->pri = INF;
    nil->data = 0;
    nil->sz = 0;
    root = nil;
}
inline void rotate(node *x) {
    node *p = x->parent, *z = x->parent->parent;
    int k = isrson(x), fz = isrson(p);
    if (fz >= 0) z->ch[fz] = x;
    else root = x;
    p->ch[k] = x->ch[!k];
    x->ch[!k] = p;
    p->ch[k]->parent = p;
    x->ch[!k]->parent = x;
    x->parent = z;
    update(p);
    update(x);
}
// inline void rotate(node *x) {
    // // puts("1");
    // if (x == root) return;
    // node *p = x->parent;
    // p->ch[isrson(x)] = x->ch[!isrson(x)];
    // x->ch[!isrson(x)]->parent = p;
    // x->ch[!isrson(x)] = p;
    // if (p == root) {
        // root = x;
    // } else {
        // p->parent->ch[isrson(p)] = x;
    // }
    // x->parent = p->parent;
    // p->parent = x;
    // update(x);
    // puts("s");
// }

void swim(node *x) {
    while (x != root && x->pri > x->parent->pri) {
        printf("%d %d\n", (int)root, (int)x);
        rotate(x);
    }
}
void sink(node *x) {
    node *smallest;
RDO:;
    smallest = x;
    if (x->ch[LEFT]->pri < smallest->pri) {
        smallest = x->ch[LEFT];
    }
    if (x->ch[RIGHT]->pri < smallest->pri) {
        smallest = x->ch[RIGHT];
    }
    if (smallest != x) {
        rotate(smallest);
        goto RDO;
    }
}

void insert(int value) {
    if (root == nil) {
        root = newnode(value, nil);
        return;
    }
    node *currsor = root;
    int dir = value > currsor->data;
    while (currsor->ch[dir] != nil) {
        currsor = currsor->ch[dir];
        dir = value > currsor->data;
    }
    currsor->ch[dir] = newnode(value, currsor);
    update(currsor);
    // swim(currsor->ch[dir]);
}
void print(node *r) {
    if (r == nil) return;
    print(r->ch[LEFT]);
    printf("%d\n", r->data);
    print(r->ch[RIGHT]);
}
int main() {
    init();
    // cur = buf;
    srand((int)(time(0)));
    for (int i = 0; i < 10; i++) {
        int tmp = rnd();
        // printf(" %d\n", tmp);
        insert(tmp);
    }
    print(root);
    return 0;
}

