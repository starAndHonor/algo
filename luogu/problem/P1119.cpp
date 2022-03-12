#include <bits/stdc++.h>
using namespace std;
const int N = 500;
const int inf = 0x3f3f3f3f;
int gr[N][N], n, m, x, y, t, times[N], q, lt = -1;
bool vis[N];
inline void init(int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        gr[i][j] = 1;
      else
        gr[i][j] = inf;
}
inline void floydOnPoint(int t) {
  for (int k = 1; k <= n; k++) {
    if (times[k] <= t && !vis[k]) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (gr[i][j] >= gr[i][k] + gr[k][j])
            gr[i][j] = gr[i][k] + gr[k][j];
        }
      }
      vis[k] = true;
    }
  }
}
int main() {
  cin >> n >> m;
  init(n);
  for (int i = 1; i <= n; i++)
    scanf("%d", times + i);
  for (int i = 1; i <= m; i++)
    cin >> x >> y >> t, gr[x + 1][y + 1] = gr[y + 1][x + 1] = t;
  cin >> q;
  while (q--) {
    cin >> x >> y >> t;
    if (lt == t) {
      if (gr[x + 1][y + 1] != inf && times[x + 1] <= t && times[y + 1] <= t)
        cout << gr[x + 1][y + 1] << endl;
      else
        cout << -1 << endl;
    }
    // cout << gr[x][y] << endl;
    else {
      floydOnPoint(t);
      if (gr[x + 1][y + 1] != inf && times[x + 1] <= t && times[y + 1] <= t)
        cout << gr[x + 1][y + 1] << endl;
      else
        cout << -1 << endl;
      lt = t;
    }
  }
  return 0;
}