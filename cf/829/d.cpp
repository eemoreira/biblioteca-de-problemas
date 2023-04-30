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

const int mx = 5e5 + 5;
int ok2321 = 0;
int freq[mx];

void solve(){
    int n; cin >> n;
    int x; cin >> x;
    vi a(n);
    for(auto &u: a) cin >> u;
    sor(a);
    for(auto u : a) freq[u]++;
    for(int i = 1; i < x; i++){
        if(freq[i] % (i+1)){
            cout << "no" << endl;
            return;
        }
        freq[i+1] += freq[i]/(i+1);
        /* cout << i+1 << ' ' << freq[i+1] << endl; */
    }
    cout << "yes" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc=1;
    if(ok2321) cin >> tc;
    while(tc--) solve();
    return 0;
}



