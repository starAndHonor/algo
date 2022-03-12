#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[int(1e6)];
ll ans;
int main(int argc, char const *argv[]) {
  ll N, t;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  ans = v[0];
  for (int i = 1; i < N; i++)
    if (v[i] > v[i - 1])
      ans += v[i] - v[i - 1];
  cout << ans;
  return 0;
}