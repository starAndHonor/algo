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
//  鏍规嵁鍙傛暟涓暟鑷姩閫夋嫨 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int n;
#define ls p << 1
#define rs p << 1 | 1
struct node {
  int l, r;
  int sum;
} tr[MAXN << 2];
int a[MAXN];
inline void pushup(int p) { tr[p].sum = tr[ls].sum + tr[rs].sum; }
inline void build(int p = 1, int cl = 1, int cr = n) {
  tr[p].l = cl, tr[p].r = cr;
  if (cl == cr) return void(tr[p].sum = a[cl]);
  int cmid = cl + cr >> 1;
  build(ls, cl, cmid);
  build(rs, cmid + 1, cr);
  pushup(p);
}
inline void update(int pos, int d, int p = 1) {
  if (tr[p].l == tr[p].r) {
    return void(tr[p].sum += d);
  }
  int cmid = tr[p].l + tr[p].r >> 1;
  if (pos <= cmid)
    update(pos, d, ls);
  else
    update(pos, d, rs);
  pushup(p);
}
inline int query(int l, int r, int p = 1) {
  if (tr[p].r < l || tr[p].l > r) return 0;
  if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
  return query(l, r, ls) + query(l, r, rs);
}
inline int kth(int k, int p = 1) {
  if (tr[p].l == tr[p].r) return tr[p].l;
  if (tr[ls].sum >= k)
    return kth(k, ls);
  else
    return kth(k - tr[ls].sum, rs);
}
inline void ins(int x) { update(x, 1); }
inline void del(int x) { update(x, -1); }
inline int rk(int k) { return query(1, k - 1) + 1; }
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  build(1, 1, 10000);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ins(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i - rk(a[i]);
  }
  cout << ans;
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  //	 freopen("P1168_1.in", "r", stdin);
  //	 freopen("P1168_1.out", "w", stdout);
  signed T = 1;  //(signed)read();//scanf("%d",&T);//cin>>T;
  for (signed CASE = 1; CASE <= T; CASE++) {  //
    // printf("Case #%d: ",CASE); //printf("Case %d: ",CASE); //printf("Case
    // #%d: \n",CASE); //printf("Case %d: \n",CASE); while(cin>>n) work(n);
    work(CASE, CASE == T);
  }
  return 0;
}