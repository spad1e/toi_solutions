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
int t[1000000];
void solve() {
    ll n, m; cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
    }
    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l + r)/2;
        ll cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += mid/t[i];
        }
        if (cnt >= n) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
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
