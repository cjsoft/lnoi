#include <iostream>
#include <cstdio>
#include <cstring>
#define update(x) (x->sz = x->ch[0]->)
#define isrson(x) (x->parent->ch[1] == x)
#define LEFT 0
#define RIGHT 1
const int MXN = 1000007;
using namespace std;
typedef long long ll;
typedef int var;
struct node {
    int sz;
    node *ch[2];
    node *parent;
    var data;
};
struct splaytree {
    node buf[MXN], _nil, *root, *nil, *cur;
    splaytree() {
        nil = &_nil;
        root = nil;
        nil->sz = 0;
        nil->ch[0] = nil->ch[1] = nil->parent = 0;
        cur->data = 0;
        cur = buf;
    }
    node *newnode(var value, node *p) {
        cur->data = value;
        cur->parent = p;
        cur->sz = 1;
        cur->ch[0] = cur->ch[1] = nil;
        return cur++;
    }
    void rotate(node *x) {
        if (x == nil || x == root) return;
        node *p = x->parent, *z = x->parent->parent;
        int fx = isrson(x), fp = isrson(p);
        p->ch[fx] = x->ch[!fx];
        p->ch[fx]->parent = p;
        x->ch[!fx] = p;
        if (p == root) {
            root = x;
            x->parent = nil;
        } else {
            z->ch[fp] = x;
            x->parent = z;
        }
        p->parent = x;
        update(p);
        update(x);
    }
    void splay(node *x, node *y) {
        for (; x->parent != y; rotate(x))
            if (x->parent->parent != y) {
                if (isrson(x) == isrson(x->parent)) rotate(x->parent);
                else rotate(x);
            }
    }
};

int main() {

    return 0;
}