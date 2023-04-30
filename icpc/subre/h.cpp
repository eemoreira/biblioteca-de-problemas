#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
int res[MAX];
vector<pair<int,int>> a(MAX);
int n,k;

void solve(){
    cin>>n>>k;
    vector<vector<int>> b(k+1);
    for(int i = 1; i <= n; i++){
        int x,y; cin>>x>>y;
        a[i] = {x,y};
        b[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
       sort(begin(b[a[i].second]) , end(b[a[i].second]));
    }
    for(int i=1; i <= n; i++){
        res[i] = b[a[i].second][0];
        b[a[i].second].erase(begin(b[a[i].second]));
    }
    int ok = 0;
    for(int i = 2; i <= n; i++){
        if(res[i-1] > res[i]){
            ok = 1;
            cout << "N" << endl;
            break;
        }
    }
    if(!ok) cout << "Y" << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

