#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int n, m, k, cnt;
int fa[N], su[N], sv[N], rk[N];
inline void init(int n) {
  for (int i = 1; i <= n; i++)
    fa[i] = i, rk[i] = 1;
}
int find(int x) { return (fa[x]) == x ? x : fa[x] = find(fa[x]); }
inline void merge(int i, int j) {
  int x = find(i);
  int y = find(j);
  if (rk[x] <= rk[y])
    fa[x] = y;
  else
    fa[y] = x;
  if (rk[x] == rk[y] && i != j)
    rk[y]++;
}
bool equal(int x, int y) { return find(x) == find(y); }
int main() {
  cin >> n >> m >> k;
  init(n);
  for (int i = 0; i < m; i++) {
    cin >> su[i] >> sv[i];
    if (su[i] > k && sv[i] > k)
      merge(su[i], sv[i]);
  }
  for (int i = 0; i < m; i++) {
    if (su[i] <= k || sv[i] <= k) {
      if (equal(su[i], sv[i]))
        cnt++;
      else
        merge(su[i], sv[i]);
    }
  }
  cout << cnt;
  return 0;
}