#include <bits/stdc++.h>
typedef long long ll;
cosnt int N = 100005;
using namespace std;
int n, m;
int gr[N][N];
int p[N];
bool vis[N];
bool match(int i) {
  for (int j = 1; j <= n; j++) {
    if (gr[i][j] && !vis[j]) {
      vis[j] = true;
      if (!p[j] && match(p[j])) {
        p[j] = i;
        return true;
      }
    }
  }
  return false;
}
int Hungarian() {
  int cnt = 0;
  for (size_t i = 1; i <= M; i++) {
    memset(vis, 0, sizeof(vis));
    if (match(i))
      cnt++;
  }
  return cnt;
}
int main(int argc, char **argv) {
  int u, v;
  cin >> m >> n;
  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 1; j <= n; j++) {
      gr[i][j] = 0;
    }
  }
  while (1) {
    cin >> u >> v;
    if (u == -1 && v == -1)
      break;
    gr[u][v] = gr[v][u] = 1;
  }
  auto a = Hungarian();
  if (a) {
    cout << a << endl;
    for (size_t i = 1; i <= ; i++) {
      cout << p[j] << j << endl;
    }
  }
  return 0;
}