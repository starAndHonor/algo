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
const int MAXN = (int)2e5 + 3;

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
mt19937 rnd(233);
struct node {
  int l, r, val, key, size;
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
inline void split(int p, int v, int &x, int &y) {
  if (!p)
    return x = y = 0, void();
  if (tr[p].val <= v) {
    x = p;
    split(tr[x].r, v, tr[x].r, y);
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
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}

inline void insert(int v) {
  int x, y, z;
  split(rt, v, x, y);
  z = newnode(v);
  rt = merge(merge(x, z), y);
}
inline void del(int v) {
  int x, y, z;
  split(rt, v, x, z);
  split(x, v - 1, x, y);
  y = merge(tr[y].l, tr[y].r);
  rt = merge(merge(x, y), z);
}

inline int kth(int p, int k) {
  if (k <= tr[tr[p].l].size)
    return kth(tr[p].l, k);
  if (k == tr[tr[p].l].size + 1)
    return p;
  return kth(tr[p].r, k - tr[tr[p].l].size - 1);
}
inline int pre(int v) {
  int x, y;
  split(rt, v - 1, x, y);
  int p = kth(x, tr[x].size);
  rt = merge(x, y);
  return tr[p].val;
}
inline int suf(int v) {
  int x, y;
  split(rt, v, x, y);
  int p = kth(y, 1);
  rt = merge(x, y);
  return tr[p].val;
}
inline int rk(int v) {
  int x, y;
  split(rt, v - 1, x, y);
  int res = tr[x].size + 1;
  rt = merge(x, y);
  return res;
}
inline int val(int k) {
  int p = kth(rt, k);
  return tr[p].val;
}
int n, opt, x, last, m, ans;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  cin >> n >> m;
  srand(time(nullptr));
  for (int i = 1; i <= n; i++) {
    insert(read());
  }
  for (int i = 1; i <= m; i++) {
    opt = read(), x = read();
    x ^= last;
    // cout << opt << ": ";
    switch (opt) {
    case 1:
      insert(x);
      break;
    case 2:
      del(x);
      break;
    case 3:
      ans ^= (last = rk(x));
      break;
    case 4:
      ans ^= (last = val(x));
      break;
    case 5:
      ans ^= (last = pre(x));
      break;
    case 6:
      ans ^= (last = suf(x));
      break;
    }
    // cout << endl;
  }
  cout << ans;
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