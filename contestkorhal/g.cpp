#include <bits/stdc++.h>

using namespace std;
const int MAX = 550;
int a[MAX][MAX], p[2][MAX][MAX];
int n,P;

int find(int i, int j, int l, int r, int me) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        assert(i + mid <= n && j + mid <= n);
        int v = p[me][i + mid][j + mid] - p[me][i + mid][j-1] - p[me][i-1][j + mid] + p[me][i-1][j-1];
        int u = p[!me][i + mid][j + mid] - p[!me][i + mid][j-1] - p[!me][i-1][j + mid] + p[!me][i-1][j-1];
        if (!u) {
            if (v) {
                ans = mid + 1;
            }
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}
int last(int i, int j, int l, int r, int me) {
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        assert(i + mid <= n && j + mid <= n);
        int v = p[me][i + mid][j + mid] - p[me][i + mid][j-1] - p[me][i-1][j + mid] + p[me][i-1][j-1];
        if (!v) {
            ans = mid + 1;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> P;
    for (int i = 0; i < P; i++) {
        int x,y;
        cin >> x >> y;
        --x;--y;
        a[x][y] = 1;
    }
    for (int i = 0; i < P; i++) {
        int x,y;
        cin >> x >> y;
        --x;--y;
        a[x][y] = 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) a[i][j] = -1;
            p[0][i][j] = p[0][i-1][j] + p[0][i][j-1] - p[0][i-1][j-1] + (a[i-1][j-1] == 1);
            p[1][i][j] = p[1][i-1][j] + p[1][i][j-1] - p[1][i-1][j-1] + (a[i-1][j-1] == 2);
        }
    }
    vector<long long> ans(2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                int l = 0, r = n - max(i, j);
                int y = last(i,j,l,r,k);
                int x = find(i,j,l,r,k);
                if (x > y) {
                    ans[k] += x - y;
                }
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}





