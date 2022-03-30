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
bool tag[MAXN << 2];
int n, m, op, x, y;

inline void pushdown(int p) {
  if (tag[p]) {
    tag[p << 1] ^= 1;
    tag[p << 1 | 1] ^= 1;
    tag[p] = 0;
  }
}
inline void update(int l, int r, int p = 1, int cl = 1, int cr = n) {
  if (cl >= l && cr <= r) {
    tag[p] ^= 1;
    return;
  }
  pushdown(p);
  int cmid = cl + cr >> 1;
  if (l <= cmid) update(l, r, p << 1, cl, cmid);
  if (r > cmid) update(l, r, p << 1 | 1, cmid + 1, cr);
}
inline int query(int x, int p = 1, int cl = 1, int cr = n) {
  if (cl == cr) return tag[p];
  pushdown(p);

  int cmid = cl + cr >> 1;
  if (x <= cmid)
    return query(x, p << 1, cl, cmid);
  else
    return query(x, p << 1 | 1, cmid + 1, cr);
}

inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  while (m--) {
    cin >> op;
    if (op == 1)
      cin >> x >> y, update(x, y);
    else
      cin >> x, cout << query(x) << endl;
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