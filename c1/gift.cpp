#include <iostream>
#include <cstdio>

using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  if (n == 1) {
    double tmp;
    double mmm = 0.0;
    for (int i = 1; i <= m; ++i) {
      scanf("%lf", &tmp);
      mmm = std::max(tmp, mmm);
    }
    printf("%.12lf\n", mmm / 1000);
  }
  if (m == 1) {
    printf("%d.000000000000\n", n);
  }
  return 0;
}
