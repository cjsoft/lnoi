#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MXN = 1007;

struct UnionSet {
    int fa[MXN];
    int getfa(int n) {
        return fa[n] == n ? n : (fa[n] = getfa(fa[n]));
    }
    int unite(int a, int b) {
        fa[getfa(a)] = getfa(b);
    }
};

int main() {

    return 0;
}
