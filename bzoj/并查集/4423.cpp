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
const int MAXN = (int)2e3 + 3;

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
int n, k;
int fa[MAXN * MAXN];
inline void build(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int i = find(x);
  int j = find(y);
  fa[i] = j;
}
inline bool query(int x, int y) { return find(x) == find(y); }
bool last = true;
char op1, op2;
int a1, b1, a2, b2;
inline int get(int x, int y) {
  if (x <= 0 || y <= 0) return 0;
  if (x >= n || y >= n) return 0;
  return (x - 1) * n + y;
}
inline void cul(int x, int y, char op) {
  int a, b;
  if (op == 'N')
    a = find(get(x - 1, y)), b = find(get(x, y));
  else
    a = find(get(x, y - 1)), b = find(get(x, y));
  if (a == b)
    return (void)printf("NIE\n"), (void)(last = false);
  else
    return (void)merge(a, b), (void)printf("TAK\n"), (void)(last = true);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> k;
  build(n * n);
  for (int i = 1; i <= k; i++) {
    cin >> a1 >> b1 >> op1;
    cin >> a2 >> b2 >> op2;
    if (last)
      cul(a1, b1, op1);
    else
      cul(a2, b2, op2);
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