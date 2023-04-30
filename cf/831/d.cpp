#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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

int ok2321 = 1;
const int mx = 1e5 + 5;
int out[mx];

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vi a(k);
    for(auto &u : a) cin >> u;
    int tryy = k;
    int qt = n*m;
    int cnt = 0;
    for(int i = 0; i <= k; i++) out[i] = 0;
    for(int i = 0; i < k; i++){
        if(cnt > qt - 4 && cnt >= 2*(n+m-3)){
            cout << "tidak\n";
            return;
        }
        if(out[tryy]){
            /* cout << "left: " << tryy << '\n'; */
            tryy--;
            cnt--;
            i--;
        }
        else if(a[i] != tryy){
            /* cout << "tryy: " << tryy << " comming out: " << a[i] << '\n'; */
            out[a[i]]++;
            cnt++;
        }
        else{
            /* cout << "left: " << tryy << '\n'; */
            tryy--;
        }
    }
    cout << "ya\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



