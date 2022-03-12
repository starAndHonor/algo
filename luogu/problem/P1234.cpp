#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
char v[N][N];
int main(int argc, char **argv) {
  int a, b, cnt = 0;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++)
      cin >> v[i][j];
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      if (v[i][j] == 'h') {
        if (v[i][j + 1] == 'e' && v[i][j + 2] == 'h' && v[i][j + 3] == 'e')
          cnt++;
        if (v[i][j - 1] == 'e' && v[i][j - 2] == 'h' && v[i][j - 3] == 'e')
          cnt++;
        if (v[i - 1][j] == 'e' && v[i - 2][j] == 'h' && v[i - 3][j] == 'e')
          cnt++;
        if (v[i + 1][j] == 'e' && v[i + 2][j] == 'h' && v[i + 3][j] == 'e')
          cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}