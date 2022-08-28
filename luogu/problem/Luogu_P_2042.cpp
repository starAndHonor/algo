#include <bits/stdc++.h>
// #include<bits/extc++.h>
// #define int long long//__int128
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
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)4e6 + 3;

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
const int nil = 1e6 + 3;
struct node {
  int l, r, sz, val, key, sum, cover, reverse, lmax, rmax, maxx;
} tr[MAXN];
mt19937 rnd(233);
int idx;
inline int newnode(int v) {
  idx++;
  tr[idx].sum = tr[idx].maxx = tr[idx].val = v;
  tr[idx].lmax = tr[idx].rmax = max(v, 0);
  tr[idx].sz = 1;
  tr[idx].key = rnd();
  tr[idx].cover = nil;
  tr[idx].reverse = 0;
  return idx;
}
inline void pushup(int p) {
  if (!p)
    return;
  tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + 1;
  tr[p].sum = tr[tr[p].l].sum + tr[tr[p].r].sum + tr[p].val;
  tr[p].lmax = max(
      max(tr[tr[p].l].lmax, tr[tr[p].l].sum + tr[p].val + tr[tr[p].r].lmax), 0);
  tr[p].rmax = max(
      max(tr[tr[p].r].rmax, tr[tr[p].r].sum + tr[p].val + tr[tr[p].l].rmax), 0);
  tr[p].maxx = max(tr[tr[p].r].lmax + tr[tr[p].l].rmax, 0) + tr[p].val;
  if (tr[p].l)
    tr[p].maxx = max(tr[p].maxx, tr[tr[p].l].maxx);
  if (tr[p].r)
    tr[p].maxx = max(tr[p].maxx, tr[tr[p].r].maxx);
}
inline void reverse(int p) {
  if (!p)
    return;
  swap(tr[p].l, tr[p].r);
  swap(tr[p].lmax, tr[p].rmax);
  tr[p].reverse ^= 1;
}
inline void cover(int p, int c) {
  if (!p)
    return;
  tr[p].val = c;
  tr[p].sum = c * tr[p].sz;
  tr[p].lmax = tr[p].rmax = max(0, tr[p].sum);
  tr[p].maxx = max(c, tr[p].sum);
  tr[p].cover = c;
}
inline void pushdown(int p) {
  if (!p)
    return;
  if (tr[p].reverse) {
    reverse(tr[p].l);
    reverse(tr[p].r);
    tr[p].reverse = 0;
  }
  if (tr[p].cover != nil) {
    cover(tr[p].l, tr[p].cover);
    cover(tr[p].r, tr[p].cover);
    tr[p].cover = nil;
  }
}
inline void split(int p, int v, int &x, int &y) {
  if (!p)
    return x = y = 0, void();
  pushdown(p);
  if (tr[tr[p].l].sz < v) {
    x = p;
    split(tr[x].r, v - 1 - tr[tr[x].l].sz, tr[x].r, y);
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
int ls[MAXN];
inline int add(int cl, int cr) {
  if (cl != cr) {
    int cmid = cl + cr >> 1;
    return merge(add(cl, cmid), add(cmid + 1, cr));
  }
  return newnode(ls[cl]);
}
int n, m;
int rt;
string opt;
int tot, pos, c;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> ls[i];
  rt = merge(rt, add(1, n));
  while (m--) {
    cin >> opt;
    if (opt == "INSERT") {
      cin >> pos >> tot;
      for (int i = 1; i <= tot; i++) {
        cin >> ls[i];
      }
      int x, y;
      split(rt, pos, x, y);
      rt = merge(merge(x, add(1, tot)), y);
    } else if (opt == "DELETE") {
      cin >> pos >> tot;
      int x, y, z;
      split(rt, pos - 1, x, y);
      split(y, tot, y, z);
      rt = merge(x, z);
    } else if (opt == "MAKE-SAME") {
      int x, y, z;
      cin >> pos >> tot >> c;
      split(rt, pos - 1, x, y);
      split(y, tot, y, z);
      cover(y, c);
      rt = merge(merge(x, y), z);
    } else if (opt == "REVERSE") {
      int x, y, z;
      cin >> pos >> tot;
      split(rt, pos - 1, x, y);
      split(y, tot, y, z);
      reverse(y);
      rt = merge(merge(x, y), z);
    } else if (opt == "GET-SUM") {
      int x, y, z;
      cin >> pos >> tot;
      split(rt, pos - 1, x, y);
      split(y, tot, y, z);
      cout << tr[y].sum << endl;
      rt = merge(merge(x, y), z);
    } else if (opt == "MAX-SUM") {
      cout << tr[rt].maxx << endl;
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