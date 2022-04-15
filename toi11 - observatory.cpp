#include<bits/stdc++.h>
//#include <grader.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define INF INT_MAX
using namespace std;
int a[2020][2020];
int dp1[2020][2020];
int dp2[2020][2020];
int ans = INT_MIN;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp1[i][j] = a[i][j] + dp1[i-1][j] + dp1[i][j-1] - dp1[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp2[i][j] = dp2[i-1][j-1] + dp1[i][j] - dp1[i-1][j];
        }
    }
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            ans = max(ans, dp2[i][j] - dp2[i-k][j-k] - dp1[i][j-k] + dp1[i-k][j-k]);
        }
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
            dp1[i][j] = a[i][j] + dp1[i-1][j] + dp1[i][j+1] - dp1[i-1][j+1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j > 0; --j) {
            dp2[i][j] = dp2[i-1][j+1] + dp1[i][j] - dp1[i-1][j];
        }
    }
    for (int i = k; i <= n; ++i) {
        for (int j = m - k + 1; j > 0; --j) {
            ans = max(ans, dp2[i][j] - dp2[i-k][j+k] - dp1[i][j+k] + dp1[i-k][j+k]);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
