#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const int N = 2005;
int gr[N][N];
int w[N][N];
struct edge {
  int flag;
  int i, j;
  bool operator<(edge a) const {
    if (a.flag != flag)
      return a.flag < flag;
    else {
      if (w[a.i][a.j] != w[i][j])
        return w[a.i][a.j] < w[i][j];
      else {
        if (a.i + a.j != i + j)
          return a.i + a.j > i + j;
        else
          return a.i > i;
      }
    }
  }
};
set<edge> a;
int main(int argc, char **argv) {
  int n, m;
  int t;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> t;
      if ((i == 1 && j == 1) || (i == n && j == 1) || (i == n && j == m) ||
          (i == 1 && j == m))
        a.insert(edge{t, i, j}), w[i][j] = 2;
      else {
        if (i == 1)
          a.insert(edge{t, i, j}), w[i][j] = 1;
        else if (j == 1)
          a.insert(edge{t, i, j}), w[i][j] = 1;
        else
          a.insert(edge{t, i, j}), w[i][j] = 0;
      }
    }
  int cnt = 1;
  for (size_t i = 0; i < n * m; i++) {
    cin >> t;
    auto ans = a.lower_bound(edge{t, 0, 0});
    gr[ans->i][ans->j] = cnt;
    a.erase(ans);
    cnt++;
    for (size_t i = 1; i <= n; i++) {
      for (size_t j = 1; j <= m; j++) {
        cout << gr[i][j] << " ";
      }
      puts("");
    }
    puts("");
  }

  return 0;
}