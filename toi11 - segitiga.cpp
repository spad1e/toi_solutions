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
bool dp[300][300][3];
void solve() {
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        dp[i][i][s[i] - '0'] = 1;
    }
    for (int m = 1; m < n; ++m) {
        for (int i = 0; i < n - m; ++i) {
            int j = i + m;
            for (int k = i; k < j; ++k) {
                if (dp[i][k][0] && dp[k+1][j][0]) dp[i][j][2] = 1;
                if (dp[i][k][0] && dp[k+1][j][1]) dp[i][j][1] = 1;
                if (dp[i][k][0] && dp[k+1][j][2]) dp[i][j][0] = 1;
                if (dp[i][k][1] && dp[k+1][j][0]) dp[i][j][2] = 1;
                if (dp[i][k][1] && dp[k+1][j][1]) dp[i][j][1] = 1;
                if (dp[i][k][1] && dp[k+1][j][2]) dp[i][j][1] = 1;
                if (dp[i][k][2] && dp[k+1][j][0]) dp[i][j][1] = 1;
                if (dp[i][k][2] && dp[k+1][j][1]) dp[i][j][2] = 1;
                if (dp[i][k][2] && dp[k+1][j][2]) dp[i][j][1] = 1;
            }
        }
    }
    cout << (dp[0][n-1][0] ? "yes" : "no") << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t = 20;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
