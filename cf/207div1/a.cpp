#include <bits/stdc++.h>
#define endl '\n' 

using namespace std; 
 
typedef long long ll; 
typedef vector<int> vi; 
typedef pair<int, int> ii;

#define comp(a,b) a+b

const int mx = 1e5 + 5;
const int neutral = 0;

int st[4*mx],a[mx];

void build(int v, int tl, int tr) {
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2+1, tl, tm);
    build(v*2+2, tm+1, tr);
    st[v] = comp(st[v*2+1],st[v*2+2]);
}

ii query(int n, int low, int high, int l, int r){
    if(low>=l && high<=r){
        return st[n];
    }
    if(low>r || high<l) return neutral;
    int mid = (low+high)/2;
    int left = query(2*n+ 1, low, mid, l, min(r,mid));
    int right = query(2*n + 2, mid+1, high, max(l,mid+1) , r);
    return comp(right,left);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr){
        st[v] = new_val;
        return;
    }
    int tm = (tl + tr) / 2;
    if(pos <= tm) update(v*2+1, tl, tm, pos, new_val);
    else update(v*2+2, tm+1, tr, pos, new_val);
    st[v] = comp(st[v*2+2],st[v*2+1]);
}
void solve(){
    int n,q; cin >> n >> q;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

