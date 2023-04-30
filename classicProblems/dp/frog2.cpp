#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector <int> height(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> height[i];

    const int INF = 1e9;
    vector <int> dp(n+1, INF);
    dp[1] = 0;

    for(int i=2; i<= n; i++) {
        for(int j = i-1; j >= 0 && i-j <= k; j--){
            dp[i] = min(dp[i], dp[j] + abs(height[i] - height[j]));
        }
    }

    cout << dp[n];
    return 0;
}
