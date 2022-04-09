#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x, 0, sizeof(x))
#define mmst3f(x) memset(x, 0x3f, sizeof(x))
#define si(x) scanf("%d", &x)  // scanf("%lld",&x) // When define int ll
#define pb(x) emplace_back(x)
#define mkp(x, y) make_pair(x, y)
#define fi first
#define se second
#define YESS printf("Yes\n")
#define NOO printf("No\n")
#define fori(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define ford(a, b, c, d) for (int a = (b); a >= (c); a -= (d))
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e5 + 3;

inline char nc() { return getchar(); }
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = nc();
  }
  return s * w;
}
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int rt = 0;
int sz[MAXN], w[MAXN];
int n, m, sum;
int q[int(1e7 + 5)];
bool ans[MAXN];
bool vis[MAXN];
bool judge[MAXN];
int dis[MAXN];
int cnt, tmp[MAXN];
struct node {
  int v, w;
};
vector<node> gr[MAXN];
inline void add(int u, int v, int w) {
  gr[u].push_back({v, w});
  gr[v].push_back({u, w});
}
void dfs1(int u, int fa) {
  sz[u] = 1;
  w[u] = 0;
  for (auto [v, w] : gr[u]) {
    if (v == fa || vis[v]) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    ::w[u] = max(sz[v], ::w[u]);
  }
  w[u] = max(w[u], sum - sz[u]);
  if (w[u] < w[rt]) rt = u;
}
inline void getdis(int u, int fa) {
  tmp[cnt++] = dis[u];
  for (auto [v, w] : gr[u]) {
    if (v == fa || vis[v]) continue;
    dis[v] = dis[u] + w;
    getdis(v, u);
  }
}
inline void solve(int u) {
  static queue<int> que;
  for (auto [v, w] : gr[u]) {
    if (vis[v]) continue;
    cnt = 0;
    dis[v] = w;
    getdis(v, u);
    for (int j = 0; j < cnt; j++) {
      for (int k = 0; k < m; k++) {
        if (q[k] >= tmp[j]) {
          ans[k] |= judge[q[k] - tmp[j]];
        }
      }
    }
    for (int j = 0; j < cnt; j++) {
      que.push(tmp[j]);
      judge[tmp[j]] = true;
    }
  }
  while (!que.empty()) {
    judge[que.front()] = false;
    que.pop();
  }
}
inline void devide(int u) {
  vis[u] = judge[0] = true;
  solve(u);
  for (auto [v, w] : gr[u]) {
    if (vis[v]) continue;
    ::w[rt = 0] = sum = sz[v];
    dfs1(v, 0);
    dfs1(rt, 0);
    devide(rt);
  }
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  int aa, bb, cc;
  for (int i = 2; i <= n; i++)
    cin >> aa >> bb >> cc, add(aa, bb, cc), add(bb, aa, cc);
  for (int i = 0; i < m; i++) {
    cin >> q[i];
  }
  w[0] = sum = n;
  dfs1(1, 0);
  dfs1(rt, 0);
  devide(rt);
  for (int i = 0; i < m; i++) {
    if (ans[i])
      puts("AYE");
    else
      puts("NAY");
  }
}

signed main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}