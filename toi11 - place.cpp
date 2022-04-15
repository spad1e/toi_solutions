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
vector<pair<int, pii>> edges;
ll cnt = 0;
int rep[200020];
int f(int i) {return (i == rep[i] ? i : rep[i] = f(rep[i]));}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) rep[i] = i;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb({w, {u, v}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
    for (auto i : edges) {
        int w = i.st;
        int u = i.nd.st, v = i.nd.nd;
        if (f(u) != f(v)) {
            rep[f(u)] = rep[f(v)];
            cnt += w-1;
        }
    }
    cout << cnt  << '\n';
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
