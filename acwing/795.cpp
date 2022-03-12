#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
#define fori(a, b, c) for (int i = (a); i <= (b); i += (c))
int a[N];
int s[N];
int l, r, n, m;
int main(int argc, char **argv) {
  cin >> n >> m;
  fori(1, n, 1) { cin >> a[i]; }
  fori(1, n, 1) { s[i] = s[i - 1] + a[i]; }
  fori(1, m, 1) {
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
  return 0;
}