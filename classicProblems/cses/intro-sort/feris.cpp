#include <bits/stdc++.h>
#define ll long long
void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
	cin.tie(0); 
    solve();
    return 0;
}

void solve(){
    ll n ,x ,w ,sumw=0 ,count=0; cin >> n >> x;
    vector<ll> pesos(n);
    vector<int> visited(n);
    for(ll i=0; i<n;i++){
        cin >> w;
        pesos[i] = w;
        }
    sort(pesos.begin(), pesos.end());
    int i=0,j=n-1;
    while(i<j){
        if(pesos[i] + pesos[j] > x){
            j--;
        }
        else{
            count++;
            visited[i] = 1; visited[j] = 1;
            i++;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) count++;
    }
    cout << count << "\n";
}