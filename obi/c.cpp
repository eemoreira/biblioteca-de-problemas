#include<bits/stdc++.h>

using namespace std;

const int mx= 1e5 + 5;
int s[mx],m[mx];
int pfs[mx],pfm[mx];
int minn[mx],maxx[mx];

void solve(){
    int n,l,h;cin>>n>>l>>h;
    for(int i = 0; i < n; i++) cin>>s[i];
    for(int i = 0; i < n; i++) cin>>m[i];
    pfs[0] = 0;
    pfm[0] = 0;
    for(int i = 1; i <= n; i++){
        pfs[i] = pfs[i-1] + s[i-1];
        pfm[i] = pfm[i-1] + m[i-1];
    }
    for(int i = 0 ; i < mx; i++){
        minn[i]  = INT_MAX;
        maxx[i] = INT_MIN;
    }
    for(int i = 0; i <= n; i++){
        if(pfs[i] < minn[pfm[i]]) minn[pfm[i]] = pfs[i];
        if(pfs[i] > maxx[pfm[i]]) maxx[pfm[i]] = pfs[i];
    }
    int res = INT_MIN;
    for(int i = 0; i < n-l;i++){
        int maior = INT_MIN;
        for(int k = l+i; k <= h+i; k++){
            if(k > n) break;
            if(k==i)continue;
            if(maxx[k] - minn[i] > maior) maior = maxx[k] - minn[i];   
        }
       res = max(res, maior);
    }
    cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}

