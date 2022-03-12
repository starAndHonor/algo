#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long w[N], v[N], n, m, c, d, a, dp[N];
namespace UF {
long long fa[N];
inline void init(long long n) {
  for (long long i = 1; i <= n; i++)
    fa[i] = i;
}
long long find(long long x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(long long x, long long y) {
  long long i = find(x), j = find(y);
  fa[i] = j;
}
inline bool connected(long long x, long long y) { return find(x) == find(y); }
} // namespace UF

int main(int argc, char **argv) {
  cin >> n >> m >> a;
  for (long long i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  UF::init(n);
  for (long long i = 1; i <= m; i++) {
    cin >> c >> d;
    if (!UF::connected(c, d))
      UF::merge(c, d);
  }
  for (long long i = 1; i <= n; i++) {
    if (UF::fa[i] != i) {
      w[UF::find(i)] += w[i];
      w[i] = 0;
      v[UF::find(i)] += v[i];
      v[i] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (UF::fa[i] == i && w[i] != 0 && v[i] != 0)
      for (long long j = a; j >= w[i]; j--) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
  }
  cout << dp[a];
  return 0;
}