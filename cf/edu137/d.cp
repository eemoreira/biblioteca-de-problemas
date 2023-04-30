
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

int ok2321 = 1;

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    for(auto &u : a) cin >> u;
    for(auto &u : b) cin >> u;
    if(a[0] > b[0]){
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i < n; i++){
        /* cout << b[i] << ' ' << b[i-1] << endl; */
        if(b[i] < b[i-1] - 1 && a[i-1] != b[i-1]){
            cout << "NO" << endl;
            return;
        }
        if(a[i] > b[i]){
            cout << "NO" << endl;
            return;
        }
    }
    if(b[0] < b[n-1] - 1 && a[n-1] != b[n-1]){
        cout << "NO" << endl;
        return;
    }
    int ok = 0;
    a.pb(a[0]);
    for(int i = 1; i <= n; i++){
        ok |= (a[i] <= a[i-1]);
    }
    cout << (ok?"YES":"NO") << endl;
}
