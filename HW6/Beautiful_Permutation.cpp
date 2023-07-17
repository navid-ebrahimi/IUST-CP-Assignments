#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
long long dp[N];
long long dp2[N][N];

long long compute(int n) {
    if (n == 0) 
        return 1;
    if (n == 1) 
        return 0;
    if (n == 2) 
        return 1;
    if (dp[n] != -1) 
        return dp[n];
    return dp[n] = (n - 1) * (compute(n - 1) + compute(n - 2));
}

long long C(int n, int r) {
    if (n < r) 
        return 0;
    if (r == 0 or n == r) 
        return 1;
    if (dp2[n][r] != -1) 
        return dp2[n][r];
    return dp2[n][r] = C(n - 1, r - 1) + C(n - 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        ans += C(n, i) * compute(i);
    }
    cout << ans << endl;
}