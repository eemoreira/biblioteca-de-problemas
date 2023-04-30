#include <bits/stdc++.h>

using namespace std;

void solve(){
    int pos, n, t; cin >> pos >> n >> t;
    vector<string> a(n);
    map<char,int> vis;
    for(auto& u : a) cin >> u;
    int cont=0;
    vis[pos-1]=1;
    for(auto u : a){
        if(u[pos-1] == '1'){ 
            for(int i = 0; i < t; i++){
                if(u[i] == '1' && !vis[i]){
                    vis[i] = 1;
                    cont++;
                }
            }
        }
    }
    cout << cont << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

