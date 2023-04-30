#include <bits/stdc++.h>

const int MAX = 1000;

using namespace std;

void solve(){
    int xi,yi,xf,yf; cin >> xi >> yi >> xf >> yf;
    int n; cin >> n;
    vector<pair<int,int>> vx(n);
    vector<pair<int,int>> vy(n);
    vector<vector<int>> adj(n);
    vector<pair<int, int>> moves = {{0,1}, {1,0}, {-1,0},{0,-1}};
    for(int i =0;i<n;i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        vx.first = a;
        vx.second = b;
        vy.first = c;
        vy.second = d;
    }
    
}


int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        solve();
        return 0;
    }