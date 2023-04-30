#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define pf push_front
#define eb emplace_back

int ok2321 = 0;

void solve(){
    int q; cin >> q;
    map<ll,int> have;
    map<ll,ll> smallest;
    have[0] = 1;
    while(q--){
        char c; cin >> c;
        if(c=='+'){
            ll a; cin >> a;
            have[a] = 1;
        }
        else{
            ll a; cin >> a;
            ll b = a;
            while(have[smallest[a]]) smallest[a] += b;
            cout << smallest[a] << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



