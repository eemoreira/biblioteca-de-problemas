#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1),b(k+1),c;
    int m = INT_MIN;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i<=k) b[i] = a[i];
        else c.push_back(a[i]);
    }
    int res=0;
    if(n==k){
        cout << 0 << endl;
        return;
    }
    sort(begin(b) + 1, end(b));
    m = b[k];
    sort(begin(c), end(c));
    for(auto u : c){
        if(u <= m) {
            res++;
            m = b[k-res];
        }
    }
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc; cin >> tc;
    while(tc--)
    solve();
	return 0;
}

