#include <bits/stdc++.h>
#define endl '\n'
 
using namespace std;
typedef long long ll;
 
 
 
void solve(){
    int n,m; cin >> n >> m;
    vector<vector<char>> grid(n+2,vector<char>(m+2));
    for(int i = 0; i <= n+1; i++){
        for(int k = 0; k <= m+1; k++){
            if(i == 0 || k == 0 || i == n+1 || k == m+1) grid[i][k] = '.';
            else cin >> grid[i][k];
        }
    }
    int ok = 1;
    int cont=0,keep=0;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(grid[i][k] == '*'){
                int c=0;keep++;
                for(int linha = i-1 ; linha <= i+1 ; linha++){
                    for(int col = k-1; col <=k+1; col++){
                        if(grid[linha][col] == '*'){
                            c++;
                        }
                    }
                }
                int s = 0;
                if(grid[i+1][k] == '*')s++;
                if(grid[i-1][k] == '*')s++;
                if(grid[i][k+1] == '*')s++;
                if(grid[i][k-1] == '*')s++;
                if(s>=2) cont++;
                ok &= (c == 3);
            }
        }
    }
    ok &= cont >= keep/3;
    cout << (ok ? "YES" : "NO") << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}
 
