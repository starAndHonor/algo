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
mt19937 rnd(233);
struct node {
  int l, r, val, key, size, tag;
} tr[MAXN];
int idx, rt;
inline int newnode(int v) {
  tr[++idx].val = v;
  tr[idx].key = rnd();
  tr[idx].size = 1;
  return idx;
}
inline void pushup(int p) {
  tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}
inline void pushdown(int p) {
  if (!tr[p].tag || !p)
    return;
  swap(tr[p].l, tr[p].r);
  tr[tr[p].l].tag ^= 1;
  tr[tr[p].r].tag ^= 1;
  tr[p].tag = 0;
}
inline void split(int p, int v, int &x, int &y) {
  if (!p)
    return x = y = 0, void();
  pushdown(p);
  if (tr[tr[p].l].size < v) {
    x = p;
    split(tr[x].r, v - tr[tr[p].l].size - 1, tr[x].r, y);
  } else {
    y = p;
    split(tr[y].l, v, x, tr[y].l);
  }
  pushup(p);
}
inline int merge(int x, int y) {
  if (!x || !y)
    return x + y;
  if (tr[x].key < tr[y].key) {
    pushdown(x);
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    pushdown(y);
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}
inline void reverse(int l, int r) {
  int x, y, z;
  split(rt, r, x, z);
  split(x, l - 1, x, y);
  tr[y].tag ^= 1;
  rt = merge(merge(x, y), z);
}
inline void insert(int v) {
  int x, y, z;
  split(rt, v, x, y);
  z = newnode(v);
  rt = merge(merge(x, z), y);
}
inline void ptr(int rt) {
  if (!rt)
    return;
  pushdown(rt);
  ptr(tr[rt].l);
  cout << tr[rt].val << " ";
  ptr(tr[rt].r);
}
int n, opt, x, m, l, r;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  n = read();
  m = read();
  srand(time(nullptr));
  for (int i = 1; i <= n; i++)
    rt = merge(rt, newnode(i));
  for (int i = 1; i <= m; i++) {
    l = read();
    r = read();
    reverse(l, r);
  }
  ptr(rt);
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