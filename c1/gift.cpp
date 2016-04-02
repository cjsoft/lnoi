#include <iostream>
#include <cstdio>

using namespace std;
int n, m;
int main() {
  freopen("gift.in", "r", stdin);
  freopen("gift.out", "w", stdout);
  scanf("%d %d", &n, &m);
  if (n == 1) {
    double tmp;
    double mmm = 0.0;
    for (int i = 1; i <= m; ++i) {
      scanf("%lf", &tmp);
      mmm = std::max(tmp, mmm);
    }
    printf("%.12lf\n", mmm / 1000);
    return 0;
  }
  if (m == 1) {
    printf("%d.000000000000\n", n);
    return 0;
  }
  double tmp, resu = 0.0;
  for (int i = 1; i <= n; ++i) {
    double mmmm = 0.0;
    for (int j = 1; j <= m; ++j) {
      scanf("%lf", &tmp);
      mmmm = std::max(mmmm, tmp);
    }
    resu += mmmm;
  }
  printf("%.12lf\n", resu / 1000);
  return 0;
}
