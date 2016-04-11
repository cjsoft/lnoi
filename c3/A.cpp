// tvt
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#define EPS 0.0000005

using namespace std;

int n;
double w, h;
double xx[67], yy[67];
int istate[67];
double resu = 0.0;
// int gcnt = 0;
inline bool validator(double x1, double y1, int state1, double x2, double y2, int state2, double l) {
    if ((state1 - state2) % 2 == 0) {
        if (state1 == state2) {
            if (state1 & 1 == 0) {
                if (fabs(x1 - x2) >= l) return true;
                else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
                return false;
            } else {
                if (fabs(y1 - y2) >= l) return true;
                else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
                return false;

            }
        }
        if (state1 - state2 > 0) {
            if (state1 & 1) {
                if (y2 <= y1) return true;
                else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            } else {
                if (x1 <= x2) return true;
                else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;

            }
            return false;
        } else {
            if (state1 & 1){
                if (y2 >= y1) return true;
                else if (fabs(fabs(x1 - x2) + fabs(y1 - y2) - 2 * l) < EPS) return true;
            } else {
                   if (x1 >= x2) return true; 
                   else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            }
            return false;
        }
    } else {
        if (state2 & 1 == 1) {
            std::swap(x1, x2);
            std::swap(y1, y2);
            std::swap(state1, state2);
        }
        if (state1 == 1 && state2 == 2) {
            if (x2 - x1 >= l) return true;
            else if (y2 - y1 >= l) return true;
            else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            return false;
        } else if (state1 == 1 && state2 == 4) {
            if (x1 - x2 >= l) return true;
            else if (y2 - y1 >= l) return true;
            else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            return false;
        } else if (state1 == 3 && state2 == 2) {
            if (y1 - y2 >= l) return true;
            else if (x2 - x1 >= l) return true;
            else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            return false;
        } else if (state1 == 3 && state2 == 4) {
            if (y1 - y2 >= l) return true;
            else if (x1 - x2 >= l) return true;
            else if (2 * l - fabs(fabs(x1 - x2) + fabs(y1 - y2)) < EPS) return true;
            return false;
        } else {
            puts("case uncatched here");
            // std::cout << x1 << ' ' << y1 << ' '<< state1 << ' ' << x2 << ' ' << y2 << ' ' << state2 << ' ' << l << std::endl;
        }
    }
    // if (fabs(fabs(x1 - x2) - l) < EPS && fabs(fabs(y1 - y2) - l) < EPS) {
        // return true;
    // } else if (fabs(fabs(x1 - x2) + fabs(y1 - y2) - 2 * l) < EPS) {
        // return true;
    // }
    // return false;
}

double solve() {
    double rr = 99999999999.0;
    double ll = EPS / 10;
    for (int i = 1; i <= n; i++) {
        switch (istate[i]) {
            case 1:
                rr = std::min(rr,
                        std::min(
                            std::min(
                                fabs(xx[i]),
                                fabs(w - xx[i])
                                ),
                            fabs(yy[i])
                            )
                        );
                break;
            case 2:
                rr = std::min(rr,
                        std::min(
                            std::min(
                                fabs(w - xx[i]),
                                fabs(yy[i])
                                ),
                            fabs(h - yy[i])
                            )
                        );
                break;
            case 3:
                rr = std::min(rr,
                        std::min(
                            std::min(
                                fabs(h - yy[i]),
                                fabs(xx[i])
                                ),
                            fabs(w - xx[i])
                            )
                        );
                break;
            case 4:
                rr = std::min(rr,
                        std::min(
                            std::min(
                                fabs(xx[i]),
                                fabs(yy[i])
                                ),
                            fabs(h - yy[i])
                            )
                        );
        }
    }
    double bak = rr;
    // rr *= 2;
    // printf("%lf\n", rr);
    // gcnt++;
    double mid = rr - ll;
    mid /= 2;
    while (fabs(rr - ll) >= EPS) {
        // printf("%lf %lf\n", ll, rr);
        mid = (ll + rr) / 2;
        for (int j = 1; j < n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (validator(xx[j], yy[j], istate[j], xx[k], yy[k], istate[k], mid)) {
                    ll = mid;
                } else {
                    rr = mid;
                }
            }
        }
    }
    // if (mid < EPS) return bak;
    return mid;
}

void dfs(int id) {
    for (int i = 1; i < 5; i++) {
        double rr = 999999999999999999999.0;
        istate[id] = i;
        // switch (i) {
            // case 1:
                // rr = std::min(rr,
                        // std::min(
                            // std::min(
                                // fabs(xx[i]),
                                // fabs(w - xx[i])
                                // ),
                            // fabs(yy[i])
                            // )
                        // );
                // break;
            // case 2:
                // rr = std::min(rr,
                        // std::min(
                            // std::min(
                                // fabs(w - xx[i]),
                                // fabs(yy[i])
                                // ),
                            // fabs(h - yy[i])
                            // )
                        // );
                // break;
            // case 3:
                // rr = std::min(rr,
                        // std::min(
                            // std::min(
                                // fabs(h - yy[i]),
                                // fabs(xx[i])
                                // ),
                            // fabs(w - xx[i])
                            // )
                        // );
                // break;
            // case 4:
                // rr = std::min(rr,
                        // std::min(
                            // std::min(
                                // fabs(xx[i]),
                                // fabs(yy[i])
                                // ),
                            // fabs(h - yy[i])
                            // )
                        // );
        // }
        // if (rr < resu) continue;
        if (id < n) {
            dfs(id + 1);
        } else {
            resu = std::max(resu, solve());
        }
    }
}
int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &n);
    scanf("%lf %lf", &w, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", xx + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lf", yy + i);
    }
    dfs(1);
    // printf("%d\n", gcnt);
    // printf("%.2lf\n", resu * 2);
    // std::cout.unsetf(std::ios::floatfield);
    // std::cout.precision(6);
    std::cout << resu * 2.0 << std::endl;
    return 0;
}
