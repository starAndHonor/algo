#include <bits/stdc++.h>
#include <iterator>
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
const int MAXN = (int)1e7 + 3;

inline char nc() { return getchar(); }
// inline int read() {
//   int s = 0, w = 1;
//   char ch = nc();
//   while (!isdigit(ch)) {
//     if (ch == '-')
//       w = -1;
//     ch = nc();
//   }
//   while (isdigit(ch)) {
//     s = (s << 3) + (s << 1) + (ch ^ 48);
//     ch = nc();
//   }
//   return s * w;
// }
// inline int read() {int x;si(x);return x;} // FAKE QUICK READ,JUST FOR DEBUG
//  inline void read(int &x){char ch=nc();x=0;while (!(ch>='0'&&ch<='9'))
//  ch=nc();while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=nc();} //
//  根据参数个数自动选择 void prt(int
//  x){if(x<0){putchar('-');x=-x;}if(x>9)prt(x/10);putchar((char)(x%10+'0'));}
int p[MAXN], ls[MAXN], rs[MAXN], stk[MAXN], top, n, rt;
inline void build(int n) {
  for (int i = 1; i <= n; i++) {
    int cur = top;
    while (cur && p[stk[cur]] <= p[i])
      cur--;
    if (cur)
      rs[stk[cur]] = i;
    if (cur < top)
      ls[i] = stk[cur + 1];
    stk[++cur] = i;
    top = cur;
  }
  rt = stk[1];
}

inline int query(int l, int r) {
  int u = rt;
  while (1) {
    if (l <= u && u <= r)
      return p[u];
    u = r < u ? ls[u] : rs[u];
  }
}

ull ans;
namespace GenHelper {
unsigned z1, z2, z3, z4, b;
unsigned rand_() {
  b = ((z1 << 6) ^ z1) >> 13;
  z1 = ((z1 & 4294967294U) << 18) ^ b;
  b = ((z2 << 2) ^ z2) >> 27;
  z2 = ((z2 & 4294967288U) << 2) ^ b;
  b = ((z3 << 13) ^ z3) >> 21;
  z3 = ((z3 & 4294967280U) << 7) ^ b;
  b = ((z4 << 3) ^ z4) >> 12;
  z4 = ((z4 & 4294967168U) << 13) ^ b;
  return (z1 ^ z2 ^ z3 ^ z4);
}
} // namespace GenHelper
void srand(unsigned x) {
  using namespace GenHelper;
  z1 = x;
  z2 = (~x) ^ 0x233333333U;
  z3 = x ^ 0x1234598766U;
  z4 = (~x) + 51;
}
int read() {
  using namespace GenHelper;
  int a = rand_() & 32767;
  int b = rand_() & 32767;
  return a * 32768 + b;
}

int m, s;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m >> s;
  srand(s);
  for (int i = 1; i <= n; i++)
    p[i] = read();
  build(n);
  for (int l, r, i = 1; i <= m; i++) {
    l = read() % n + 1;
    r = read() % n + 1;
    if (l > r)
      swap(l, r);
    ans += query(l, r);
  }
  printf("%llu", ans);
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