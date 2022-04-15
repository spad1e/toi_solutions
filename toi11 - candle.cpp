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
int n, m, cnt = 0;
char ye[2020][2020];
bool mark[2020][2020];
queue<pii> q;
void bfs(int x, int y) {
    mark[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        int i = q.front().st;
        int j = q.front().nd;
        q.pop();
        for (int xx = -1; xx <= 1; ++xx) {
            for (int yy = -1; yy <= 1; ++yy) {
                if (xx == 0 && yy == 0) continue;
                if (ye[i + xx][j + yy] == '0') continue;
                if (i + xx < 1 || i + xx > n) continue;
                if (j + yy < 1 || j + yy > m) continue;
                if (!mark[i + xx][j + yy]) {
                    mark[i + xx][j + yy] = 1;
                    q.push({i + xx, j + yy});
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> ye[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ye[i][j] == '1' && !mark[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
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
