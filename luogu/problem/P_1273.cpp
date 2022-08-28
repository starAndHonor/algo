#include <bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long  //__int128
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
const int MAXN = (int)1e6 + 3;

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
// void dfs(int u,int fa){
//   for(auto v:)
// }
int n, m, vv[MAXN];
int x, y;
int sz[MAXN], dp[4000][4000];
struct node {
  int v, w;
};
vector<node> gr[MAXN];
inline void add(int u, int v, int w) {
  gr[u].push_back(node{v, w});
  gr[v].push_back(node{u, w});
}
void dfs(int u, int fa) {
  if (u > n - m) {
    dp[u][1] = vv[u];
    sz[u] = 1;
    return;
  }
  for (auto [v, w] : gr[u]) {
    if (v == fa) continue;
    dfs(v, u);
    sz[u] += sz[v];
    for (int i = sz[u]; i > 0; i--)
      for (int j = 1; j <= i; j++)
        dp[u][i] = max(dp[u][i - j] + dp[v][j] - w, dp[u][i]);
  }
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  memset(dp, -INF, sizeof(dp));
  cin >> n >> m;
  for (int sz, i = 1; i <= n - m; i++) {
    cin >> sz;
    for (int j = 1; j <= sz; j++) cin >> x >> y, add(i, x, y);
  }
  for (int i = n - m + 1; i <= n; i++) cin >> vv[i];
  for (int i = 1; i <= n; i++) dp[i][0] = 0;
  dfs(1, 0);
  for (int i = m; i >= 1; i--) {
    if (dp[1][i] >= 0) cout << i, exit(0);
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