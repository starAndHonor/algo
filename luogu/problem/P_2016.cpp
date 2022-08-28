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
inline void add(int u, int v) {
  gr[u].push_back(v);
  gr[v].push_back(u);
}
int n, dp[MAXN][2], rt, in[MAXN];
void dfs(int u, int fa) {
  dp[u][1] = 1;
  for (auto v : gr[u]) {
    if (v == fa) continue;
    dfs(v, u);
    dp[u][1] += min(dp[v][0], dp[v][1]);
    dp[u][0] += dp[v][1];
  }
}

inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  rt = 1;
  for (int k, t, a, i = 1; i <= n; i++) {
    cin >> t;
    t++;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> a;
      a++;
      add(t, a);
    }
  }
  //   for (int i = 1; i <= n; i++)
  //     if (in[i] == 0) rt = i;
  dfs(rt, 0);
  //   for (int i = 1; i <= n; i++) cout << dp[i];
  //   cout << dp[rt];
  cout << min(dp[rt][0], dp[rt][1]);
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