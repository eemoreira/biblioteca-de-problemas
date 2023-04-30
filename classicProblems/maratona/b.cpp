#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> v(n);
    for(int i =0; i < m; i++){
        int a, b; cin >> a >> b;
        v[i] = {a,b};
    }
    vector<vector<pair<int,int>>> allp;
    int count = 0;
    for(int i= 0; i < n; i++){
        for(int k = 0; k < n && k != i; k++){
            for(auto [u,w] : v){
            if((u == i && w == k) || (u==k && w==i)) continue;
            else{
                for(auto [u,w] : allp){
                    if((u==i && w ==k) || (u==k && w==i)) count++;
                }
            }
            }
        }
    }
    cout << allp.size() + n - count <<  endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

