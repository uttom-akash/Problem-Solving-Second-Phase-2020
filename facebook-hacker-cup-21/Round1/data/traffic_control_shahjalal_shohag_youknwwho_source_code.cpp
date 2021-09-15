#include<bits/stdc++.h>
using namespace std;

int a[55][55];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0; cin >> t;
  while (t--) {
    int n, m, x, y; cin >> n >> m >> x >> y;
    cout << "Case #" << ++cs << ": ";
    if (x < n + m - 1 or y < n + m - 1) {
      cout << "Impossible\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = 1000;
      }
    }
    for (int i = 1; i <= m; i++) {
      a[n][i] = 1; --x; --y;
    }
    for (int i = 1; i < n; i++) {
      a[i][m] = 1; --y;
      a[i][1] = 1; --x;
    }
    a[1][1] += x;
    a[1][m] += y;
    cout << "Possible\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (j > 1) cout << ' ';
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}