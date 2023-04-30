#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(auto &u : a) cin >> u;
    b = a;
    sort(b.begin(), b.end());
    if(n <= 1){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            if(i < n-1)swap(b[i],b[i+1]);
            else swap(b[i],b[i-1]);
        }
    }
    for(auto u : b) cout << u << ' ';
    cout << endl;
    }
    

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

