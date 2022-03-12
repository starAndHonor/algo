#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int stdA[N][N];
bool vis[N][N];
int dirx[] = {0, 0, -1, 1};
int diry[] = {-1, 1, 0, 0};
map<pair<int, int>, int> ans;
vector<pair<int, int>> order;
int main() {
  int n, m, a, b, x, y;
  cin >> n >> m >> a >> b;
  queue<tuple<int, int, int>> q;
  for (int i = 1; i <= a; i++) {
    cin >> x >> y;
    vis[x][y] = true;
    q.push({x, y, 0});
  }
  for (int i = 1; i <= b; i++) {
    cin >> x >> y;
    stdA[x][y] = true;
    order.push_back({x, y});
  }
  while (!q.empty()) {
    auto [nx, ny, time] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int dx = nx + dirx[i];
      int dy = ny + diry[i];
      if (vis[dx][dy] || dx < 1 || dy < 1 || dy > m || dx > n)
        continue;
      vis[dx][dy] = true;
      q.push({dx, dy, time + 1});
      if (stdA[dx][dy]) {
        ans[{dx, dy}] = time + 1;
      }
    }
  }
  for (auto i : order)
    cout << ans[i] << endl;
  return 0;
}