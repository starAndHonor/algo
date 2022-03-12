#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
typedef unsigned long long ll;
ll fa[N];
array<ll, 1005> X, Y, Z;
inline void init(ll n) {
  for (ll i = 1; i <= n; i++)
    fa[i] = i;
}
ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(ll x, ll y) {
  ll i = find(x), j = find(y);
  fa[i] = j;
}
inline bool isEqual(ll x, ll y) { return find(x) == find(y); }
inline bool beside(ll a, ll b, ll c, ll x, ll y, ll z, ll r) {
  return (x - a) * (x - a) + (b - y) * (b - y) + (c - z) * (c - z) <= 4 * r * r;
}
int main(int argc, char const *argv[]) {
  ll n, h, r, T, x, y, z;

  cin >> T;
  while (T--) {
    memset(fa, 0, sizeof(fa));
    X.fill(0);
    Y.fill(0);
    Z.fill(0);
    cin >> n >> h >> r;
    init(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> x >> y >> z;
      X[i] = x;
      Y[i] = y;
      Z[i] = z;
    }
    for (int i = 1; i <= n; i++) {
      if (Z[i] + r >= h)
        merge(i, n + 2);
      if (Z[i] <= r)
        merge(i, n + 1);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (beside(X[i], Y[i], Z[i], X[j], Y[j], Z[j], r))
          merge(i, j);
      }
    }
    if (isEqual(n + 1, n + 2))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}