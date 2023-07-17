#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1023;
const int M = 12;
const int MOD = 1e9+7;

int dp1[M][N];
int dp2[M][N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        dp1[1][i] = dp2[1][i] = 1;
    }
    for (int x = 1; x <= n; ++x) {
        for (int i = 2; i <= m; ++i) {
            for (int j = 1; j <= x; ++j) {
                dp1[i][x] += dp1[i-1][j];
                dp1[i][x] %= MOD;
            }
        }
    }
    for (int x = n; x >= 1; --x) {
        for (int i = 2; i <= m; ++i) {
            int sum = 0;
            for (int j = n; j >= x; --j) {
                sum = (sum + dp2[i-1][j]) % MOD;
            }
            dp2[i][x] = sum;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = (ans + dp1[m][i]*dp2[m][j]) % MOD;
        }
    }
    cout << ans;
    return 0;
}