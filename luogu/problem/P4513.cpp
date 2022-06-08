#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, opt, x, y;
struct node {
  int maxx;
  int maxl;
  int maxr;
  int maxs;
  //   int l, r;
  node *ls = nullptr, *rs = nullptr;
  node(int _l, int _r, int _m, int _s) {
    maxx = _m, maxl = _l, maxr = _r, maxs = _s;
  }
  node() {}
} * tr;
int a[MAXN];
inline void pushup(node *p) {
  //   auto t = new node;
  //   if (p->ls->maxr < 0 && p->ls->maxl < 0) {
  //   }
  p->maxx = p->ls->maxx + p->rs->maxx;
}
inline void build(node *p, int l, int r) {
  //   p->l = l;
  //   p->r = r;
  if (l == r) {
    p->maxl = p->maxr = p->maxx = p->maxs = a[l];
    return;
  }
  cout << l << " " << r << endl;
  int mid = l + r >> 1;
  p->ls = new node;
  p->rs = new node;
  build(p->ls, l, mid);
  build(p->rs, mid + 1, r);
  pushup(p);
}
inline void update(int d, int x, node *p, int cl, int cr) {
  if (cl == cr) {
    p->maxl = p->maxr = p->maxx = p->maxs = x;
    return;
  }
  int cmid = cl + cr >> 1;
  if (d <= cmid)
    update(d, x, p->ls, cl, cmid);
  else
    update(d, x, p->rs, cmid + 1, cr);
  pushup(p);
}
inline int query(int l, int r, node *p, int cl, int cr) {
  if (cl >= l && cr <= r) {
    return p->maxx;
  }
  int cmid = cl + cr >> 1, maxx = -INF;
  if (l <= cmid) maxx = max(maxx, query(l, r, p->ls, cl, cmid));
  if (r > cmid) maxx = max(maxx, query(l, r, p->rs, cmid + 1, cr));
  return maxx;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(tr, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> opt >> x >> y;
    if (opt == 1) {
      if (y < x) swap(x, y);
      //   cout << query(x, y, tr, 1, n) << endl;
    } else {
      //   update(x, y, tr, 1, n);
    }
  }
  cout << 1;
  return 0;
}