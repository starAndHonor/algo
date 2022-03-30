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
vector<int> gr[MAXN];
int d[MAXN], p[MAXN][23];
inline void add(int u, int v) { gr[u].push_back(v), gr[v].push_back(u); }
inline void dfs(int u, int fa) {
  d[u] = d[fa] + 1;
  p[u][0] = fa;
  for (int i = 1; i <= __lg(d[u]); i++) {
    p[u][i] = p[p[u][i - 1]][i - 1];
  }
  for (auto v : gr[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}
int lca(int a, int b) {
  if (d[a] > d[b]) swap(a, b);
  while (d[a] != d[b]) b = p[b][__lg(d[b] - d[a])];
  if (a == b) return a;
  for (int i = __lg(d[a]); i >= 0; i--) {
    if (p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  }
  return p[a][0];
}
inline int dis(int x, int y) { return d[x] + d[y] - 2 * lca(x, y); }
inline int up(int x, int dis) {
  for (int i = __lg(dis); i >= 0; i--) {
    if (dis >> i & 1) x = p[x][i];
  }
  return x;
}
inline int n, m, k, x, y, z;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    add(x, y);
  }
  dfs(1, 0);
  int D;
  while (k--) {
    cin >> x >> y;
    z = lca(x, m);
    if (dis(m, x) <= y) {
      m = y;
      cout << y;
    } else {
      if (D = (dis(m, z) > y)) {
        up(m, y);
        cout << m;
      } else {
        m = up(x, dis(z, x) - (y - D));
        cout << m;
      }
      if (m == -1)
        puts("");
      else
        cout << " ";
    }
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}