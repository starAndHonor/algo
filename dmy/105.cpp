#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
#define mmst0(x) memset(x, 0, sizeof(x))
#define mmst3f(x) memset(x, 0x3f, sizeof(x))
#define si(x) scanf("%d", &x) // scanf("%lld",&x) // When define int ll
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
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)2e5 + 3;

inline char nc() { return getchar(); }
inline int read() {
  int s = 0, w = 1;
  char ch = nc();
  while (!isdigit(ch)) {
    if (ch == '-')
      w = -1;
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

int euler[MAXN << 2], pos[MAXN << 2], cnt, d[MAXN << 2], p[MAXN << 2][40], n, m,
    s;
int w[MAXN];

int a[MAXN], x, y;
vector<int> gr[MAXN << 1];
inline void add(int u, int v) {
  gr[u].push_back(v);
  gr[v].push_back(u);
}
inline void dfs(int u, int fa, int dd) {
  euler[++cnt] = u;
  w[u] = a[u] ^ w[fa];
  d[cnt] = dd;
  pos[u] = cnt;
  for (auto v : gr[u]) {
    if (fa != v)
      dfs(v, u, dd + 1);
    euler[++cnt] = u;
    d[cnt] = dd;
  }
}
inline int eva(int x, int y) { return d[x] < d[y] ? x : y; }
inline void pre(int rt) {
  cnt = 0;
  dfs(rt, 0, 1);
  for (int i = 1; i <= cnt; i++)
    p[i][0] = i;
  int ss = __lg(cnt);
  for (int i = 1; i <= ss; i++) {
    for (int j = 1; j + (1 << i) - 1 <= cnt; j++) {
      p[j][i] = eva(p[j][i - 1], p[j + (1 << (i - 1))][i - 1]);
    }
  }
}
inline int lca(int x, int y) {
  int l = pos[x], r = pos[y];
  if (l > r)
    swap(l, r);
  int k = __lg(r - l + 1);
  return euler[eva(p[l][k], p[r - (1 << k) + 1][k])];
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i < n; i++) {
    x = read();
    y = read();
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  pre(1);
  for (int i = 1; i <= m; i++) {
    x = read();
    y = read();
    printf("%d\n", (w[x] ^ w[y] ^ a[lca(x, y)]));
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1; //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) { //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}