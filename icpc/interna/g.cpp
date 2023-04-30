#include <bits/stdc++.h>

using namespace std;

double circ(double n){
    return  2 * n* (M_PI);
}

void solve(){
    double tam; cin >> tam;
    int n; cin >> n;
    vector<pair<double,int>> b;
    for(int i = 0; i < n; i++){
        int num,d; cin >> num >> d;
        b.push_back({d,num});
    }
    sort(b.begin(),b.end());
    int cont=0,ok=0;
    for(int i = 0; i < n; i++){
        while(b[i].second--){
            if(tam < circ(b[i].first)){
                ok = 1;
                break;
            }
            tam -= circ(b[i].first);
            cont++;
        }
        if(ok) break;
    }
    cout << cont << endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

