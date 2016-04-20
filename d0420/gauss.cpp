#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define EPS 1e-7
using namespace std;
const int MXN = 57;
int solve(int n, int mat[][MXN], bool l[MXN], int resu[MXN]) {
    int res = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = r; j < n; ++j) {
            if (fabs(mat[j][i]) > EPS) {
                for (int k = i; k <= n; ++k) std::swap(mat[r][k], mat[j][k]);
                break;
            }
        }
        if (fabs(mat[r][i] <= EPS)) {
            ++res;
            continue;
        }
        double kk;
        for (int j = 0; j < n; ++j) {
            if (j == r || fabs(mat[j][i] <= EPS)) continue;
            kk = mat[j][i] / mat[r][i];
            for (int k = 0; k <= n; ++k) {
                mat[j][k] -= mat[r][k] * kk;
            }
        }
        l[i] = true;
        ++r;
    }
    for (int i = 0; i < n; ++i) {
        if (l[i]) {
            for (int j = 0; j < n; ++j) {
                if (fabs(mat[j][i]) > EPS) {
                    ans = mat[j][n] / mat[j][i];
                }
            }
        }
    }
    return res;
}

int main() {

    return 0;
}
