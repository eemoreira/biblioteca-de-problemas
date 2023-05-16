#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll; 

vector<vector<int>> solve(int x, int y, vector<int>& a, vector<vector<int>>& p) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                ans[i][j] = 1;
                continue;
            }
            ll pi = 0, pj = 0; 
            for (int k = i; k != j; k = (k+1)%n) {
                pi += a[k]; 
                pi += p[x][k]; 
            } 

            for (int k = j; k != i; k = (k+1)%n) {
                pj += p[y][k]; 
                if (pi < pj) {
                    ans[i][j] = 1;
                    break;
                } 

                pi += a[k]; 
                pi += p[x][k]; 

                pj += a[k]; 
            } 
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &u : a) cin >> u;
    vector<vector<int>> p(3, vector<int>(n));
    for (int i = 0; i < 3; i++) {
        for (auto &u : p[i]) {
            cin >> u;
        }
    }
    vector<vector<int>> ij;
    vector<vector<int>> ik;
    vector<vector<int>> jk;
    vector<vector<int>> ji;
    vector<vector<int>> ki;
    vector<vector<int>> kj;
    ij = solve(0, 1, a, p);
    ik = solve(0, 2, a, p);
    jk = solve(1, 2, a, p);
    ji = solve(1, 0, a, p);
    ki = solve(2, 0, a, p);
    kj = solve(2, 1, a, p);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                bool ans = false;
                ans |= ij[i][j] || ji[j][i];
                ans |= ik[i][k] || ki[k][i];
                ans |= jk[j][k] || kj[k][j];
                if (ans) continue;
                cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
                return;
            }
        }
    }
    cout << "impossible\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    solve();
}

