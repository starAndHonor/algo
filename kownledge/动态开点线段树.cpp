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
int n, m, cnt;
struct node {
  int ls, rs;
  ll sum;
  int tag;
} tr[MAXN];
inline void pushup(int p) { tr[p].sum = tr[p].ls + tr[p].rs; }
inline void down(int &p, int cl, int cr, int add) {
  if (!p) {
    p = ++cnt;
  }
  tr[p].sum += (cr - cl + 1) * add;
  tr[p].tag += add;
}
inline void pushdown(int p, int cl, int cr) {
  if (tr[p].tag) {
    int cmid = cl + cr >> 1;
    down(tr[p].ls, cl, cmid, tr[p].tag);
    down(tr[p].rs, cmid + 1, cr, tr[p].tag);
    tr[p].tag = 0;
  }
}
inline void update(int l, int r, int d, int &p, int cl = 1, int cr = n) {
  if (!p) {
    p = ++cnt;
  }
  if (l <= cl && r >= cr) {
    tr[p].sum += (cr - cl + 1) * add;
    tr[p].tag += add;
    return;
  }
  pushdown(p, cl, cr);
  int cmid = cl + cr >> 1;
  if (l <= cmid) update(l, r, d, tr[p].ls, cl, cmid);
  if (r > cmid) update(l, r, d, tr[p].ls, cmid + 1, cr);
  pushup(p);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {}

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