#include <bits/stdc++.h>
using namespace std;
const int N = 10000005;
struct st {
  int i;
  int j;
  int e;
};
st sts[N];
int v[N * 2];
int fa[N * 2]; // rk[N],
inline void init(int n) {
  for (int i = 1; i <= n * 2; i++)
    fa[i] = i; //, rk[i] = 1
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int i = find(x), j = find(y);
  fa[i] = j;
  // if (rk[i] <= rk[j])
  // fa[i] = j;
  // else
  // fa[j] = i;
  // if (rk[i] == rk[j] && i != j) rk[j]++;
}
inline bool equal(int x, int y) { return find(x) == find(y); }
int main(int argc, char const *argv[]) {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    int j = 0;
    memset(fa, 0, sizeof(fa));
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++) {
      cin >> sts[i].i >> sts[i].j >> sts[i].e;
      v[j] = sts[i].i;
      j++;
      v[j] = sts[i].j;
      j++;
    }
    sort(v, v + j);
    auto t = unique(v, v + j);
    for (int i = 0; i < n; i++) {
      sts[i].i = lower_bound(v, t, sts[i].i) - v + 1;
      sts[i].j = lower_bound(v, t, sts[i].j) - v + 1;
    }

    sort(sts, sts + n, [](st a, st b) { return a.e > b.e; });
    // for (int i = 0; i < n; i++)
    // cout << sts[i].i << " " << sts[i].j << " " << sts[i].e << "\n";
    init(n);
    bool f = true;
    for (int i = 0; i < n; i++) {
      if (sts[i].e)
        merge(sts[i].i, sts[i].j);
      else if (sts[i].e == 0) {
        if (equal(sts[i].i, sts[i].j)) {
          cout << "NO" << endl;
          f = false;
          break;
        }
      }
    }
    if (f)
      cout << "YES\n";
  }
  return 0;
}