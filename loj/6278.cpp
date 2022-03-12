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
using ll = long long;
// typedef long double rld; // use double pls!
using ull = unsigned long long;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f; // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)5e5 + 3;

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
int n, block, belong[MAXN], num, l[MAXN], r[MAXN], a[MAXN], b[MAXN], tag[MAXN];
inline void build() {
  block = sqrt(n);
  num = n / block;
  if (n % block != 0)
    num++;
  for (int i = 1; i <= num; i++) {
    l[i] = (i - 1) * block + 1;
    r[i] = i * block;
  }
  r[num] = n;
  for (int i = 1; i <= n; i++)
    belong[i] = (i - 1) / block + 1;
  for (int i = 1; i <= num; i++)
    sort(b + l[i], b + r[i] + 1);
}
inline void update(int l, int r, int c) {
  if (belong[l] == belong[r]) {
    for (int i = l; i <= r; i++)
      a[i] += c;
    for (int i = ::l[belong[l]]; i <= ::r[belong[l]]; i++)
      b[i] = a[i];
    sort(b + ::l[belong[l]], b + ::r[belong[l]] + 1);
    return;
  }
  for (int i = l; i <= ::r[belong[l]]; i++)
    a[i] += c;

  for (int i = ::l[belong[l]]; i <= ::r[belong[l]]; i++)
    b[i] = a[i];
  sort(b + ::l[belong[l]], b + ::r[belong[l]] + 1);
  for (int i = belong[l] + 1; i < belong[r]; i++)
    tag[i] += c;
  for (int i = ::l[belong[r]]; i <= r; i++)
    a[i] += c;
  for (int i = ::l[belong[r]]; i <= ::r[belong[r]]; i++)
    b[i] = a[i];
  sort(b + ::l[belong[r]], b + ::r[belong[r]] + 1);
}

inline int query(int l, int r, int x) {
  int cnt = 0;
  if (belong[r] == belong[l]) {
    for (int i = l; i <= r; i++)
      if (a[i] + tag[belong[l]] < x)
        cnt++;
    return cnt;
  }
  for (int i = l; i <= ::r[belong[l]]; i++)
    if (a[i] + tag[belong[l]] < x)
      cnt++;
  for (int i = ::l[belong[r]]; i <= r; i++)
    if (a[i] + tag[belong[r]] < x)
      cnt++;
  for (int i = belong[l] + 1; i < belong[r]; i++)
    cnt += lower_bound(b + ::l[i], b + ::r[i] + 1, x - tag[i]) - (b + ::l[i]);
  return cnt;
}
int op;
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read(), b[i] = a[i];
  build();
  for (int l, r, c, i = 1; i <= n; i++) {
    op = read();
    l = read();
    r = read();
    c = read();
    if (op) {
      cout << query(l, r, c * c) << endl;
    } else {
      update(l, r, c);
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