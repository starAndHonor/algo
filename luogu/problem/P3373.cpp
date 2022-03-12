#include <bits/stdc++.h>
const int INF = 0x3f3f3f;
using namespace std;
const int N = 10005;
int mod;
typedef long long ll;
inline ll read(ll x = 0) {
  scanf("%lld", &x);
  return x;
}
inline ll lf(ll i) { return i << 1; }
inline ll rt(ll i) { return i << 1 | 1; }

struct node {
  ll sum = 0, tagAdd = 0, tagMul = 1; // maxx = -INF, minn = INF,
} tr[N << 2];
ll nums[N];
ll n, m;
void pushup(ll p) {
  //	tr[p].maxx = max(tr[lf(p)].maxx,tr[rt(p)].maxx);
  //	tr[p].minn = min(tr[lf(p)].minn,tr[rt(p)].minn);
  tr[p].sum = (tr[lf(p)].sum + tr[rt(p)].sum) % mod;
}
void build(ll l = 1, ll r = n, ll p = 1) {
  if (l == r) {
    tr[p].sum = nums[l]; // tr[p].maxx = tr[p].minn =
  } else {
    ll mid = l + ((r - l) >> 1);
    build(l, mid, lf(p));
    build(mid + 1, r, rt(p));
    pushup(p);
  }
}
void pushdown(ll nowp, ll l, ll r) {
  ll mid = (l + r) >> 1;
  tr[lf(nowp)].sum =
      (tr[lf(nowp)].sum + ((mid - l) * tr[nowp].tagAdd) % mod) % mod;
  tr[rt(nowp)].sum =
      (tr[rt(nowp)].sum + ((r - mid - 1) * tr[nowp].tagAdd % mod)) % mod;
  tr[lf(nowp)].tagMul = tr[nowp].tagMul * tr[lf(nowp)].tagMul % mod;
  tr[rt(nowp)].tagMul = tr[nowp].tagMul * tr[rt(nowp)].tagMul % mod;
  tr[lf(nowp)].tagAdd =
      (tr[lf(nowp)].tagAdd * tr[nowp].tagMul + tr[nowp].tagAdd) % mod;
  tr[rt(nowp)].tagAdd =
      (tr[rt(nowp)].tagAdd * tr[nowp].tagMul + tr[nowp].tagAdd) % mod;
  //	tr[lf(nowp)].minn += tr[nowp].tagAdd;
  //	tr[rt(nowp)].minn += tr[nowp].tagAdd;
  //	tr[lf(nowp)].maxx += tr[nowp].tagAdd;
  //	tr[rt(nowp)].maxx += tr[nowp].tagAdd;
  tr[nowp].tagMul = 1;
  tr[nowp].tagAdd = 0;
}
void add(ll l, ll r, ll c, ll nowl = 1, ll nowr = n, ll nowp = 1) {
  if (r < nowl || l > nowr)
    return;
  else if (r >= nowr && l <= nowl) {
    tr[nowp].sum = (tr[nowp].sum + c * (nowr - nowl + 1)) % mod;
    //		tr[nowp].maxx+=c;
    //		tr[nowp].minn+=c;
    if (nowl != nowr)
      tr[nowp].tagAdd = (c + tr[nowp].tagAdd) % mod;
  } else {
    ll mid = nowl + ((nowr - nowl) >> 1);
    pushdown(nowp, l, r);
    add(l, r, c, nowl, mid, lf(nowp));
    add(l, r, c, mid + 1, nowr, rt(nowp));
    pushup(nowp);
  }
}
void mul(ll l, ll r, ll c, ll nowl = 1, ll nowr = n, ll nowp = 1) {
  if (r < nowl || l > nowr)
    return;
  else if (r >= nowr && l <= nowl) {
    tr[nowp].sum = c * tr[nowp].sum % mod;
    if (nowl != nowr)
      tr[nowp].tagAdd = c * tr[nowp].tagAdd % mod,
      tr[nowp].tagMul = c * tr[nowp].tagMul % mod;
    //		tr[nowp].maxx+=c;
    //		tr[nowp].minn+=c;
  } else {
    ll mid = nowl + ((nowr - nowl) >> 1);
    pushdown(nowp, l, r);
    mul(l, r, c, nowl, mid, lf(nowp));
    mul(l, r, c, mid + 1, nowr, rt(nowp));
    pushup(nowp);
  }
}
ll querySum(ll l, ll r, ll nowl = 1, ll nowr = n, ll nowp = 1) {
  if (l > nowr || r < nowl)
    return 0;
  else if (r >= nowr && l <= nowl) {
    return tr[nowp].sum;
  } else {
    ll mid = nowl + ((nowr - nowl) >> 1);
    pushdown(nowp, l, r);
    return querySum(l, r, nowl, mid, lf(nowp)) % mod +
           querySum(l, r, mid + 1, nowr, rt(nowp)) % mod;
  }
}
// ll queryMin(ll l,ll r,ll nowl=1,ll nowr=n,ll nowp=1) {
//	if(l>nowr||r<nowl)return 0;
//	else if(r>=nowr&&l<=nowl) {
//		return tr[nowp].minn;
//	} else {
//		ll mid = nowl+((nowr-nowl)>>1);
//		pushdown(nowp,nowr-nowl+1);
//		return
// min(queryMin(l,r,nowl,mid,lf(nowp)),queryMin(l,r,mid+1,nowr,rt(nowp)));
//	}
// }
// ll queryMax(ll l,ll r,ll nowl=1,ll nowr=n,ll nowp=1) {
//	if(l>nowr||r<nowl)return 0;
//	else if(r>=nowr&&l<=nowl) {
//		return tr[nowp].maxx;
//	} else {
//		ll mid = nowl+((nowr-nowl)>>1);
//		pushdown(nowp,nowr-nowl+1);
//		return
// max(queryMax(l,r,nowl,mid,lf(nowp)),queryMax(l,r,mid+1,nowr,rt(nowp)));
//	}
// }
int main() {

  n = read(), m = read(), mod = read();
  for (int i = 1; i <= n; i++)
    nums[i] = read();
  build();
  ll op, x, y, k;
  for (int i = 1; i <= m; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      mul(x, y, k);
    } else if (op == 2) {
      cin >> x >> y >> k;
      add(x, y, k);
    } else if (op == 3) {
      cin >> x >> y;
      cout << querySum(x, y) % mod << endl;
    }
  }

  return 0;
}
