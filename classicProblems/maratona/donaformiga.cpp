#include <bits/stdc++.h>

void solve();

using namespace std;


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0;
}

void solve(){

    int count=0,s, t, p; cin >> s >> t >> p;
    vector<int> salas(s);
    vector<int> alturas(s);
    vector<pair<int, int>> tuneis(t);
    deque<int> dq;
    vector<bool> visited(s);
    for(int i=0;i<s;i++){   
        int temp; cin >> temp;
        alturas[i] = temp;
    }
    for(int j=0;j<t;j++){
        int a,b; cin >> a >> b;
        if(alturas[a-1] == alturas[b-1]) continue;
        if(alturas[a-1] < alturas[b-1]) swap(a,b);
        tuneis[j] = make_pair(a-1,b-1);
    }
    dq.push_front(p-1);
    visited[p-1] = true;
    while(!dq.empty()){
        int usando = dq.front();
        dq.pop_front();
        for(auto [u,w] : tuneis){
            if(u == usando && !visited[w]){
                dq.push_front(w);
                count++;
                visited[w] = true;
            }
        }
    }
    cout << count << "\n";
}


