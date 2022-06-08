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
#define fori(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define ford(a, b, c, d) for (int a = (b); a >= (c); a -= (d))
using namespace std;
// using namespace __gnu_pbds; // If using pbds don't using std!
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)5e5 + 3;

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
struct data {
  int l, r, v, sz, rnd, w;
} tr[MAXN];
int n, sz, rt, ans, opt, x;

inline void update(int &k) {
  tr[k].sz = tr[tr[k].l].sz + tr[tr[k].r].sz + tr[k].w;
}
inline void rturn(int &k) {
  int t = tr[k].l;
  tr[k].l = tr[t].r;
  tr[t].r = k;
  tr[t].sz = tr[k].sz;
  update(k);
  k = t;
}
inline void lturn(int &k) {
  int t = tr[k].r;
  tr[k].r = tr[t].l;
  tr[t].l = k;
  tr[t].sz = tr[k].sz;
  update(k);
  k = t;
}
inline void insert(int &k, int x) {
  if (!k) {
    k = ++sz;
    tr[k].sz = tr[k].w = 1, tr[k].v = x, tr[k].rnd = rand();
    return;
  }
  tr[k].sz++;
  if (tr[k].v == x)
    tr[k].w++;
  else if (x > tr[k].v) {
    insert(tr[k].r, x);
    if (tr[tr[k].r].rnd < tr[k].rnd) lturn(k);
  } else {
    insert(tr[k].l, x);
    if (tr[tr[k].l].rnd < tr[k].rnd) rturn(k);
  }
}
inline void del(int &k, int x) {
  if (!k) return;
  if (tr[k].v == x) {
    if (tr[k].w > 1) {
      --tr[k].w;
      --tr[k].sz;
      return;
    }
    if (tr[k].l * tr[k].r == 0)
      k = tr[k].l + tr[k].r;
    else if (tr[tr[k].l].rnd < tr[tr[k].r].rnd)
      rturn(k), del(k, x);
    else
      lturn(k), del(k, x);
  } else if (x > tr[k].v)
    tr[k].sz--, del(tr[k].r, x);
  else
    tr[k].sz--, del(tr[k].l, x);
}
inline int kth(int k, int x) {
  if (k == 0) return 0;
  if (x <= tr[tr[k].l].sz)
    return kth(tr[k].l, x);
  else if (x > tr[tr[k].l].sz + tr[k].w) {
    return kth(tr[k].r, x - (tr[tr[k].l].sz + tr[k].w));
  } else
    return tr[k].v;
}
inline void queryPre(int &ans, int k, int x) {
  if (k == 0) return;
  if (x > tr[k].v) {
    ans = k;
    queryPre(ans, tr[k].r, x);
  } else
    queryPre(ans, tr[k].l, x);
}
inline void querySub(int &ans, int k, int x) {
  if (k == 0) return;
  if (x < tr[k].v) {
    ans = k;
    querySub(ans, tr[k].l, x);
  } else
    querySub(ans, tr[k].r, x);
}
inline int rk(int k, int x) {
  if (k == 0) return 0;
  if (tr[k].v == x)
    return tr[tr[k].l].sz + 1;
  else if (x > tr[k].v)
    return tr[tr[k].l].sz + tr[k].w + rk(tr[k].r, x);
  else
    return rk(tr[k].l, x);
}
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n;
  srand(time(nullptr));
  for (int i = 1; i <= n; i++) {
    opt = read(), x = read();

    // cout << opt << ": ";
    switch (opt) {
      case 1:
        insert(rt, x);
        break;
      case 2:
        del(rt, x);
        break;
      case 3:
        printf("%lld\n", rk(rt, x));
        break;
      case 4:
        printf("%lld\n", kth(rt, x));
        break;
      case 5:
        queryPre(ans = 0, rt, x);
        printf("%lld\n", tr[ans].v);
        break;
      case 6:
        querySub(ans = 0, rt, x);
        printf("%lld\n", tr[ans].v);
        break;
    }
    // cout << "end" << endl;
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