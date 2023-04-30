#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pqg;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back
#define comp(a,b) min(a,b)

const int mx = 1e5 + 5;
const int neutral = 0;
int ok2321 = 1;

void solve(){
    int n,k; cin >> n >> k;
    vector<ll> a(n);
    for(auto&u:a)cin>>u;
    if(k==1 || k==n){
        cout << "YES" << endl;
        return;
    }
    ll sumr = 0, suml =0;
    for(int i = 0; i <= k-2; i++) suml+=a[i];
    for(int i = k; i < n; i++) sumr+=a[i];
    vector<ii> gg;
    ll us = a[k-1],s=0,mi=1e15,total=0;
    int cr = 0;
    int cl = 0;
    for(int i = k-2; i >= 0; i--){
        s+=a[i];
        total+=a[i];
        mi = min(s,mi); 
        /* cout << mi << ' ' << s << ' ' << i << endl; */
        if(s>0 || i == 0){
            /* cout << mi << ' ' << s << ' ' << i << endl; */
            gg.pb(ii(-mi,s));
            s=0; 
            cr++;
            cl++;
        }
    }
    s=0,mi=1e15,total=0;
    reverse(all(gg));
    for(int i = k; i < n; i++){
        s+=a[i];
        total+=a[i];
        mi = min(s,mi);
        /* cout << mi << ' ' << s << ' ' << i << endl; */
        if(s>0 || i == n-1){
            /* cout << mi << ' ' << s << ' ' << i << endl; */
            gg.pb(ii(-mi,s));
            s=0;
        }
    }
    int keep=cr;
    cl--;
    /* for(int i = 0; i < gg.size() ; i++) cout << gg[i].fst << ' ' << gg[i].snd << ' ' << i << endl; */
    /* cout << cl << ' ' << cr << endl; */
    /* cout << (int)gg.size()-1 << endl; */
    while(cl >= 0 && cr < (int)gg.size()){
        /* cout << us << ' ' << gg[cr].fst << ' ' << gg[cl].fst << endl; */
        if(us >= gg[cr].fst) us+=gg[cr].snd,cr++;
        else if(us >= gg[cl].fst) us+=gg[cl].snd,cl--;
        else{
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}   

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



