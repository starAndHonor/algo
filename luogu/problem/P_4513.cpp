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
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
typedef long long ll;
// typedef long double rld; // use double pls!
typedef unsigned long long ull;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f3f3f3f3f;  // LLINF
const int MAXN = (int)1e5 + 3;

inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
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
int a[MAXN], n, m;
struct node {
  int lmax, rmax, maxx, sum;
  node() : lmax(-INF), rmax(-INF), maxx(-INF), sum(-INF) {}
} tr[MAXN << 4];
inline const int ls(int p) { return p << 1; }
inline const int rs(int p) { return p << 1 | 1; }
inline int &lmax(int p) { return tr[p].lmax; }
inline int &rmax(int p) { return tr[p].rmax; }
inline int &sum(int p) { return tr[p].sum; }
inline int &maxx(int p) { return tr[p].maxx; }
inline void pushup(int p) {
  sum(p) = sum(ls(p)) + sum(rs(p));
  lmax(p) = max(lmax(ls(p)), sum(ls(p)) + lmax(rs(p)));
  rmax(p) = max(rmax(rs(p)), rmax(ls(p)) + sum(rs(p)));
  maxx(p) = max(max(maxx(ls(p)), maxx(rs(p))), rmax(ls(p)) + lmax(rs(p)));
}
inline void build(int p, int cl, int cr) {
  if (cl == cr) {
    lmax(p) = rmax(p) = sum(p) = maxx(p) = a[cl];
    return;
  }
  int cmid = cl + cr >> 1;
  build(ls(p), cl, cmid);
  build(rs(p), cmid + 1, cr);
  pushup(p);
}
inline void update(int d, int x, int p, int cl, int cr) {
  if (cl == cr) {
    lmax(p) = rmax(p) = sum(p) = maxx(p) = x;
    return;
  }
  int cmid = cl + cr >> 1;
  if (d <= cmid)
    update(d, x, ls(p), cl, cmid);
  else
    update(d, x, rs(p), cmid + 1, cr);
  pushup(p);
}
inline node query(int l, int r, int p, int cl, int cr) {
  if (l <= cl && r >= cr) {
    return tr[p];
  }
  int cmid = cl + cr >> 1;
  node a, b, ans;
  if (l <= cmid) a = query(l, r, ls(p), cl, cmid);
  if (r > cmid) b = query(l, r, rs(p), cmid + 1, cr);
  ans.lmax = max(a.lmax, a.sum + b.lmax);
  ans.rmax = max(b.rmax, b.sum + a.rmax);
  ans.maxx = max(max(a.maxx, b.maxx), a.rmax + b.lmax);
  // sum(ans) = sum(a) + sum(b);
  return ans;
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  int opt, a, b;
  while (m--) {
    cin >> opt >> a >> b;
    if (opt == 1) {
      if (a > b) swap(a, b);
      cout << query(a, b, 1, 1, n).maxx << endl;
    } else {
      update(a, b, 1, 1, n);
    }
  }
  return;
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