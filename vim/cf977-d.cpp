#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 200;
ll arr[MAX];
int n;
map<int, int> adj;

void solve(){
    cin >> n;
    map<int,int> vis;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n ; k++){
            if(arr[k] == 2*arr[i]){
                adj[i] = k;
                vis[k] = 1;
            }
            else if(arr[i] == 3*arr[k]) {
                adj[i] = k;
                vis[k] = 1;
            }
    
    }
}
    int source;
    for(int i = 1; i <= n; i++) if(!vis[i]) source = i;
    while(n--){
        cout << arr[source] << " ";
        source = adj[source];
    }    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    solve();
    cout << endl;
	return 0;
}

