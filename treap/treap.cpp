#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define isrson(x) (x->parent->ch[0] == x)
#define LEFT 0
#define RIGHT 1
#define update(x) x->sz = x->ch[0]->sz + x->ch[1]->sz
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
void init() {
    cur = buf;
    nil = &_nil;
    // root =  &_root;
    nil->ch[0] = nil->ch[1] = nil->parent = nil;
    nil->parent = -1;
    nil->data = 0;
    nil->sz = 0;
}

node *newnode(int value, node *par) {
    cur->ch[0] = cur->ch[1] = nil;
    cur->parent = par;
    cur->sz = 1;
    cur->pri = rnd();
    cur->data = value;
    return cur++;
}

inline void rotate(node *x) {
    if (x == root) return;
    node *p = x->parent;
    p->ch[isrson(x)] = x->ch[!isrson(x)];
    x->ch[!isrson(x)]->parent = p;
    x->ch[!isrson(x)] = p;
    if (p == x) {
        root = x;
    } else {
        p->parent->ch[isrson(p)] = x;
    }
    p->parent = x;
    update(x);
}

void swim(node *x) {
    while (x->pri > x->p->pri) {
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

int main() {
    srand((int)(time(0)));
    printf("%d\n", rnd());
    return 0;
}

