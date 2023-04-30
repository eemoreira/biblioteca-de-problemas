#include <bits/stdc++.h>

const int MAX = 1e3;
int pos[MAX][MAX];

using namespace std;

int dpp(int h,int c){
    if(pos[h][c] != -1) return pos[h][c];
    if(h==1 && c==1) return 1;
    if(h==0 || c==0) return 0;
    pos[h][c] = dpp(h-1,c) + dpp(h,c-1);
    return pos[h][c];
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++){
            pos[i][k] = -1;
        }
    }
    cout << dpp(n,m) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}
