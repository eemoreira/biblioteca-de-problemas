#include <bits/stdc++.h>


using namespace std;


const int INF = 1000;
int n, ind, s, menor = INF;
int adj[100][100];
int dist[100];
int vis[100];
int p[100];

int getnearest(){
    for(int i=0;i<n;i++){
        if(!vis[i] && dist[i] < menor){
            menor = dist[i];
            ind = i;
        }
    }
    return ind;
}

void dij(){
    for(int i = 0;i < n;i++){
        int nearest = getnearest();
        vis[nearest] = 1;
        for(int k = 0; k < n; k++){
            if(dist[nearest] != INF && dist[nearest] + adj[nearest][k] < dist[k]){ // if new dist is smaller then old dist, update.
                dist[k] = dist[nearest] + adj[nearest][k];
                p[k] = nearest;
            }
        }
    }
}
void print(){
    cout << "node: \t\t\tcost :\t\t\tpath";
    for(int i = 0; i <  n;i++){
        cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
        cout << i << " ";
        int parent = p[i];
        while(parent != s){
            cout << " <- " << parent << " ";
            parent = p[parent];
        }
        cout << "\n";
    }
}

void solve(){
    cin >> n >> s;
    for(int i =0;i<n;i++){
        for(int k = 0;k < n; k++){
            int w; cin >> w;
            adj[i][k] = w;
        }
        dist[i] = INF;
        p[i] = i;
    }
    p[s] = -1;
    dist[s] = 0;
    dij();
    print();
}


int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    solve();
    return 0;
    }
