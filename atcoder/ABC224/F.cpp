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
typedef  long long ll;
// typedef long double rld; // use double pls!
typedef long long ull;

const double eps = 1e-6;
const int INF = 0x3f3f3f3f;  // 0x3f3f3f3f3f3f3f3f; // LLINF
const int MAXN = (int)14 + 3;

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
int n,m,x,y,N;
vector<int> gr[MAXN];
int dis[1<<MAXN][MAXN];
inline void work(signed CASE = 1, bool FINAL_CASE = false) {
	n = read();m=read();
	N = 1<<n;
	mmst3f(dis);
	while(m--){
		gr[--(x = read())].push_back(--(y=read()));
		gr[y].push_back(x);
	}
	queue<pair<int,int> > q;
	for(int i =0;i<n;i++)
		dis[1<<i][i] = 1,q.push({1<<i,i});
	while(q.size()){
		int p = q.front().fi;
		int u = q.front().se;
		q.pop();
		for(auto v:gr[u]){
			int nx = p^(1<<v);
			if(dis[nx][v]<INF)continue;
			dis[nx][v] = dis[p][u]+1;
			q.push({nx,v});
		}
	}
	long long res = 0;
	for(int i = 1;i<N;i++){
		int minn = INF;
		for(int j= 0;j<n;j++)minn = min(minn,dis[i][j]);
		res += minn;
	}
	cout<<res;
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