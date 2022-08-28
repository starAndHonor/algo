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
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)1e5 + 3;

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
int fa[MAXN << 1], ee, need;
struct e {
  int u, v, w;
  bool c;
} e[MAXN << 1];
int v;

inline void build(int n) {
  for (int i = 1; i <= n; i++)
    fa[i] = i;
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int i = find(x), j = find(y);
  fa[i] = j;
}
int ans;
inline int kruskal() {
  int res = 0;
  build(v);
  sort(e + 1, e + 1 + ee,
       [](auto a, auto b) { return a.w == b.w ? (a.c < b.c) : (a.w < b.w); });
  ans = 0;
  for (int i = 1; i <= ee; i++) {
    if (find(e[i].u) == find(e[i].v))
      continue;
    else
      merge(e[i].u, e[i].v), ans += e[i].w, res += (e[i].c == 0);
  }
  return res;
}
inline bool check(int mid) {
  for (int i = 1; i <= ee; i++)
    if (e[i].c == 0)
      e[i].w += mid;
  int ans = kruskal();
  for (int i = 1; i <= ee; i++)
    if (e[i].c == 0)
      e[i].w -= mid;
  return ans >= need;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> v >> ee >> need;
  for (int i = 1; i <= ee; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w >> e[i].c;
    e[i].u++;
    e[i].v++;
  }
  int re = 0;
  int l = -100, r = 100, mid;
  while (l <= r) {
    if (check(mid = l + r >> 1))
      l = mid + 1, re = mid;
    else
      r = mid - 1;
  }
  check(re);
  cout << ans - need * re << endl;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  // //freopen(".in", "r", stdin);//freopen(".out", "w", stdout);
  signed T = 1; //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) { //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}