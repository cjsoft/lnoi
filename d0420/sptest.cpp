#include <cstdio>
#include <cstring>
#include <algorithm>
#define isrson(x) (x->parent->child[1] == x)
using namespace std;
const int MAXN = 100005;
const int MAXM = 50005;
const int INF = 0x7FFFFFFF;
class SplayTree
{
public:
    SplayTree()
    {
        nil = &_nil;
        _nil.value = 0;
        _nil.size = 0;
        _nil.parent = nil;
        _nil.child[LEFT] = nil;
        _nil.child[RIGHT] = nil;
    }
    inline void clear()
    {
        nodeNumber = 0;
        root = nil;
        insert(-INF);
        insert(INF);
    }
    inline void insert(const int value)
    {
        if(root == nil)
        {
            root = newNode(nil, value);
            return;
        }
        Node *x = root;
        while(true)
        {
            int dir = x->value < value;
            if(x->child[dir] == nil)
            {
                x->child[dir] = newNode(x, value);
                update(x);
                splay(x->child[dir], nil);
                return;
            }
            else
            {
                x = x->child[dir];
            }
        }
    }
    inline void remove(const int value)
    {
        int k = find(value);
        find(k - 1, nil);
        find(k + 1, root);
        root->child[RIGHT]->child[LEFT] = nil;
        update(root->child[RIGHT]);
        update(root);
    }
    inline int getKth(const int k)
    {
        find(k + 1, nil);
        return root->value;
    }
    inline void print()
    {
        printf("Splay Tree: \n");
        print(root);
        printf("\n");
    }private:
    static const int LEFT = 0;
    static const int RIGHT = 1;
    struct Node
    {
        int value, size;
        Node *parent, *child[2];
    } _nil, node[MAXN];
    int nodeNumber;
    Node *root, *nil;
    inline Node *newNode(Node *parent, const int value)
    {
        node[nodeNumber].value = value;
        node[nodeNumber].size = 1;
        node[nodeNumber].parent = parent;
        node[nodeNumber].child[LEFT] = nil;
        node[nodeNumber].child[RIGHT] = nil;
        return &node[nodeNumber++];
    }
    inline void update(Node *x)
    {
        if(x == nil)
        {
            return;
        }
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;
    }
    /*void rotate(Node *x) {
        if (x == nil || x == root) return;
        Node *p = x->parent, *z = x->parent->parent;
        p->child[isrson(x)] = x->child[!isrson(x)];
        x->child[!isrson(x)]->parent = p;
        x->parent = p->parent;
        if (p == root) {
            root = x;
        } else {
            p->parent->child[isrson(p)] = x;
        }
        x->parent = p->parent;
        p->parent = x;
        update(p);
        update(x);

    }*/
    inline void rotate(Node *x) {
        Node *p = x->parent, *z = x->parent->parent;
        int k = isrson(x), fz = isrson(p);
        if (fz >= 0) z->child[fz] = x;
        else root = x;
        p->child[k] = x->child[!k];
        x->child[!k] = p;
        p->child[k]->parent = p;
        x->child[!k]->parent = x;
        x->parent = z;
        update(p);
        update(x);
    }
    /*void splay(Node *x, Node *y) {
        for (; x->parent != y; rotate(x)){
            if (x->parent->parent != y) {
                if (isrson(x) == isrson(x->parent)) rotate(x->parent);
                else rotate(x);
            }
        }
    }*/
    inline void splay(Node *x, Node *y) {
        for (; x->parent != y; rotate(x)) {
            if (x->parent->parent != y)
                if (isrson(x->parent) == isrson(x)) rotate(x->parent);
                else rotate(x);
        }
    }
    inline void find(int k, Node *y)
    {
        Node *x = root;
        while(k != x->child[LEFT]->size + 1)
        {
            if(k <= x->child[LEFT]->size)
            {
                x = x->child[LEFT];
            }
            else
            {
                k -= x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        splay(x, y);
    }
    inline int find(const int value)
    {
        Node *x = root;
        int count = 0;
        while(true)
        {
            if(x->value == value)
            {
                return count + x->size - x->child[RIGHT]->size;
            }
            else if(x->value > value)
            {
                x = x->child[LEFT];
            }
            else
            {
                count += x->size - x->child[RIGHT]->size;
                x = x->child[RIGHT];
            }
        }
    }
    inline void print(Node *x)
    {
        if(x == nil)
        {
            return;
        }
        printf("%d: %d %d %d\n", x->value, x->child[LEFT]->value, x->child[RIGHT]->value, x->size);
        print(x->child[LEFT]);
        print(x->child[RIGHT]);
    }
} splay;
struct Interval
{
    int a, b, k, index;
    bool operator < (const Interval &interval) const
    {
        return b < interval.b;
    }
} interval[MAXM];int pretty[MAXN];int ans[MAXM];
int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &pretty[i]);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &interval[i].a, &interval[i].b, &interval[i].k);
            interval[i].index = i;
        }
        sort(interval, interval + m);
        splay.clear();
        int a = 1, b = 0;
        for(int i=0;i<m;++i)
        {
            for(int j=a;j<interval[i].a && j<=b;++j)
            {
                splay.remove(pretty[j]);
            }
            for(int j=max(interval[i].a, b+1);j<=interval[i].b;++j)
            {
                splay.insert(pretty[j]);
            }
            a = interval[i].a;
            b = interval[i].b;
            ans[interval[i].index] = splay.getKth(interval[i].k);
        }
        for(int i=0;i<m;++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}