#include <bits/stdc++.h>
// #include<bits/extc++.h>
#define int long long //__int128
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
struct trie {
  int tr[MAXN][2];
  int tot = 0;
  int dp[MAXN * 30];
  int sz[MAXN * 30];
  inline void clear() {
    mmst0(tr);
    mmst0(dp);
    mmst0(sz);
    tot = 0;
  }
  inline void insert(int u) {
    int p = 0;
    for (int k, i = 30; i >= 0; i--) {
      k = (u >> i) & 1;
      if (!tr[p][k])
        tr[p][k] = ++tot;
      p = tr[p][k];
    }
  }
  inline void dfs(int p = 1) {
    int l = tr[p][0], r = tr[p][1];
    if (!l && !r)
      return dp[p] = sz[p] = 1, void();
    if (l)
      dfs(l);
    if (r)
      dfs(r);
    if (sz[l] <= 1 && sz[r] <= 1)
      dp[p] = dp[l] + dp[r];
    else
      dp[p] = max(dp[l], dp[r]) + min(min(dp[l], dp[r]), 1ll);
    sz[p] = sz[l] + sz[r];
  }
} trie;
int n;
int b[MAXN];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  trie.clear();
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    trie.insert(b[i]);
  }
  trie.dfs();
  cout << n - trie.dp[1] << endl;
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