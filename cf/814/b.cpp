#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,k;cin>>n>>k;
    int ok = 1;
    vector<int> a(n+1),db(n+1);
    vector<pair<int,int>> ans;
    for(int i = 1; i <= n; i++){
        a[i] = i;
        db[i] = 0;
    }
    for(int i = 2; i<=n; i++){
        if((a[i-1]+k)*a[i]%4==0){
            if(!db[a[i-1]] && !db[a[i]]){
                db[a[i-1]] = 1;
                db[a[i]] = 1;
                ans.push_back({a[i-1],a[i]});
            }
        }
        else if((a[i]+k)*a[i-1]%4==0)
            if(!db[a[i-1]] && !db[a[i]]){
                db[a[i-1]] = 1;
                db[a[i]] = 1;
                ans.push_back({a[i],a[i-1]});
            }
    }
    for(int i = 1; i<= n; i++){
        ok &= db[i];
    }
    if(!ok){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(auto u : ans){
        cout << u.first << ' ' << u.second << endl;
    }
}   
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

