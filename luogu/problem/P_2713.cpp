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
const int MAXN = (int)1500000;

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
struct node {
  int l, r, fa, val, dis, die;
} tr[MAXN << 2];

inline int& ls(int x) { return tr[x].l; }
inline int& rs(int x) { return tr[x].r; }
inline int& val(int x) { return tr[x].val; }
inline int& fa(int x) { return tr[x].fa; }
inline int& dis(int x) { return tr[x].dis; }
inline int& die(int x) { return tr[x].die; }
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (val(x) > val(y) || (val(y) == val(x) && x > y)) swap(x, y);
  rs(x) = merge(rs(x), y);
  fa(rs(x)) = x;
  if (dis(ls(x)) < dis(rs(x))) swap(ls(x), rs(x));
  dis(x) = dis(rs(x)) + 1;
  return x;
}
void pop(int x) {
  val(x) = -1;
  dis(x) = 0;
  fa(rs(x)) = rs(x);
  fa(ls(x)) = ls(x);
  fa(x) = merge(ls(x), rs(x));
}
int find(int x) { return fa(x) == x ? x : fa(x) = find(fa(x)); }
int n, m;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  dis(0) = -1;
  for (int i = 1; i <= n; i++) {
    cin >> val(i);
    fa(i) = i;
    ls(i) = 0;
    rs(i) = 0;
    dis(i) = 0;
  }
  cin >> m;
  int x, y;
  string opt;
  for (int i = 1; i <= m; i++) {
    cin >> opt;
    // cout << opt << endl;
    cin >> x;
    if (opt == "M") {
      cin >> y;
      if (die(x) || die(y)) {
        continue;
      }
      auto fx = find(x);
      auto fy = find(y);
      if (fx == fy) {
        continue;
      }
      fa(fx) = fa(fy) = merge(fx, fy);
    } else if (opt == "K") {
      auto fx = find(x);
      if (die(x)) {
        cout << 0 << endl;
        continue;
      }
      cout << val(fx) << endl;
      die(fx) = 1;
      pop(fx);
    }
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