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
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR
// DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
// x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
bool f = false;
int n, m, d, s, t;

int a[MAXN];
struct node {
  int minn;
  int tag;
} tr[MAXN << 2];
inline void pushup(int p) {
  tr[p].minn = min(tr[p << 1].minn, tr[p << 1 | 1].minn);
}
inline void pushdown(int p) {
  tr[p << 1].tag += tr[p].tag, tr[p << 1 | 1].tag += tr[p].tag;
  tr[p << 1].minn -= tr[p].tag, tr[p << 1 | 1].minn -= tr[p].tag;
  tr[p].tag = 0;
}
inline void build(int p, int cl, int cr) {
  tr[p].minn = INF;
  if (cl == cr) {
    cin >> tr[p].minn;
    return;
  }
  int cmid = cl + cr >> 1;
  build(p << 1, cl, cmid);
  build(p << 1 | 1, cmid + 1, cr);
  pushup(p);
}
inline void update(int l, int r, int val, int p, int cl, int cr) {
  if (cl >= l && cr <= r) {
    if (tr[p].minn < val) {
      f = true;
      return;
    }
    tr[p].tag += val;
    tr[p].minn -= val;
    return;
  }
  pushdown(p);
  int cmid = cl + cr >> 1;
  if (l <= cmid) update(l, r, val, p << 1, cl, cmid);
  if (r > cmid) update(l, r, val, p << 1 | 1, cmid + 1, cr);
  pushup(p);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  //   mmst3f(a);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> d >> s >> t;
    f = false;
    update(s, t, d, 1, 1, n);
    if (f) {
      cout << -1 << "\n" << i << endl;
      return;
    }
  }
  cout << 0;
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
