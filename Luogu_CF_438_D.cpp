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
int n, m;
struct node {
  int maxx, sum;
  node() : maxx(0), sum(0) {}
  node(int _maxx, int _sum) : maxx(_maxx), sum(_sum) {}
  friend node operator+(const node &a, const node &b) {
    return node(max(a.maxx, b.maxx), a.sum + b.sum);
  }
  friend node operator%(const node &a, int b) {
    return node(a.maxx % b, a.sum % b);
  }
} tr[MAXN << 2];
int a[MAXN];
inline void build(int p, int cl, int cr) {
  if (cl == cr)
    return tr[p] = node(a[cl], a[cl]), void();
  int cmid = cl + cr >> 1;
  build(p << 1, cl, cmid);
  build(p << 1 | 1, cmid + 1, cr);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
inline void work1(int l, int r, int mod, int p, int cl, int cr) {
  if (cl == cr)
    return tr[p] = tr[p] % mod, void();
  int cmid = cl + cr >> 1;
  if (l <= cmid && tr[p << 1].maxx >= mod)
    work1(l, r, mod, p << 1, cl, cmid);
  if (r > cmid && tr[p << 1 | 1].maxx >= mod)
    work1(l, r, mod, p << 1 | 1, cmid + 1, cr);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
inline void work2(int pos, int val, int p, int cl, int cr) {
  if (cl == cr) {
    return tr[p] = node(val, val), void();
  }
  int cmid = cl + cr >> 1;
  if (pos <= cmid)
    work2(pos, val, p << 1, cl, cmid);
  else
    work2(pos, val, p << 1 | 1, cmid + 1, cr);
  tr[p] = tr[p << 1] + tr[p << 1 | 1];
}
inline node query(int l, int r, int p, int cl, int cr) {
  if (l <= cl && r >= cr) {
    return tr[p];
  }
  int cmid = cl + cr >> 1;
  if (l > cmid)
    return query(l, r, p << 1 | 1, cmid + 1, cr);
  else if (r <= cmid)
    return query(l, r, p << 1, cl, cmid);
  else
    return query(l, r, p << 1 | 1, cmid + 1, cr) +
           query(l, r, p << 1, cl, cmid);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  int opt, l, r, x;
  while (m--) {
    cin >> opt;
    if (opt == 1) {
      cin >> l >> r;
      cout << query(l, r, 1, 1, n).sum << endl;
    } else if (opt == 2) {
      cin >> l >> r >> x;
      work1(l, r, x, 1, 1, n);
    } else {
      cin >> l >> x;
      work2(l, x, 1, 1, n);
    }
  }
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