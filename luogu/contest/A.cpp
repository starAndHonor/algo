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
ll n, k, v[20], cnt;
map<int, bool> mp;
bool ans = false;
void dfs(int all) {
  //   cout << all << endl;
  if (ans) return;
  if (all == 0) {
    ans = true;
    return;
  }
  for (int i = 1; i <= cnt; i++) {
    if (all - v[i] < 0) break;
    dfs(all - v[i]);
  }
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> k >> n;
  if (n % 9 != 0)
    ans = false;
  else {
    mmst0(v);
    cnt = 0;
    for (ll i = 1; i * k <= 20; i++) {
      v[++cnt] = pow(10, i * k) - 1;
      if (v[cnt] > n) {
        v[cnt--] = 0;
        break;
      }
    }
    sort(v + 1, v + 1 + cnt, greater<int>());
    ans = false;
    dfs(n);
  }
  if (ans)
    cout << "aya";
  else
    cout << "baka";
  puts("");
}

signed main() {
  int T;
  cin >> T;
  while (T--) {
    work();
  }
}