#include <bits/stdc++.h>

using namespace std;

const int MAX  = 2e5 + 5;
int res[MAX],un[MAX];
int n,m;
void solve(){ 

    cin >> n >> m;
    int ok = 0;
    for(int i = 1; i <= n; i++) cin >> un[i];
    vector<vector<pair<int,int>>> adj(n+1);
    map<int,int> count;
    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        count[x]++; count[y]++;
        if(y > x) adj[y].push_back({un[x], x});
        else adj[x].push_back({un[y],y});
    }
    if(m % 2 == 0){
        cout << 0 << endl;
        return;   
     }
    for(int i= 1; i <= n; i++) if(adj[i].size()) sort(begin(adj[i]), end(adj[i]));
    res[1] = un[1];
    for(int i = 2; i <= n; i++){
        if(count[i] % 2) res[i] = un[i];
        else if(!count[i] || !adj[i].size()) res[i] = INT_MAX;
        else res[i] = adj[i][0].first + un[i];
    }
    int menor = count[1]%2 ? res[1] : INT_MAX;
    for(int i = 2; i <= n;i++) if(res[i] < menor){
        menor = res[i];
    }
    cout << menor << endl;   

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
    while(t--) {
            solve();
    } 
	return 0;
}

