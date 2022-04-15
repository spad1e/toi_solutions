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
const int N = 1e7 + 10;
int c[N];
void solve() {
    int n, m, k, L; cin >> n >> m >> k >> L;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        c[a + 1]++;
    }
    for (int i = 1; i < N; ++i) {
        c[i] += c[i-1];
    }
    while (k--) {
        int cnt = 0, cur_r = 0;
        for (int i = 1; i <= m; ++i) {
            int cur; cin >> cur;
            cur++;
            int l = cur - L;
            int r = min(cur + L, (int)1e7-1);
            cnt += c[r] - c[max(l - 1, cur_r)];
            cur_r = r;
        }
        cout << cnt << '\n';
    }
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
