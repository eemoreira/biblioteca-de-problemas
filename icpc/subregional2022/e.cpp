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

int ok2321 = 0;
const int mx = 1e5 + 5;
vector<vi> adj(mx);
bool vis[mx];
int arr[mx];

void dfs(int v){
    vis[v] = true;
    for(auto u : adj[v]) if(!vis[u]) dfs(u);
}

void solve(){
    int n; cin >> n;
    map<ii,int> where;
    map<int,int> freq,f;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(!freq[arr[i]]) f[arr[i]]++; // frequencia inicial pra toda altura que eu inicializo com 1
        freq[arr[i]]++; // frequencia total das alturas
        where[ii(arr[i],freq[arr[i]])] = i; //fala que eu tenho a altura h que apareceu pela freq[h] vez ate agora na posicao i
    }
    for(int i = 0; i < n; i++){
        if(f[arr[i]] <= f[arr[i]-1]){ //passo da esquerda pra direita olhando se tem uma altura que eh igual a minha altura menos um
                                      // que apareceu menos ou igual vezes a minha altura que eu to olhando
            int a = where[ii(arr[i],f[arr[i]])];
            int b = where[ii(arr[i]-1,f[arr[i]-1])]; //pego os index de cada altura que aparece pela f[arr] vez
            cout << "arr[i]: " << arr[i] << " no: " << a << " with: " << f[arr[i]] << endl;
            cout << "arr[i]-1: " << arr[i]-1 << " no: " << b << " with: " << f[arr[i]-1] << endl;
            if(a < b){ //se a altura maior ta antes da menor no array, eu posso fazer uma edge q conecta as duas
                adj[a].pb(b);
                f[arr[i]]++;
            }
            else f[arr[i]-1]++;
        }
        else f[arr[i]]++;
    }
    int ans = 0;
    /* for(int i = 0; i < n; i++){ */
    /*     cout << arr[i] << ": "; */
    /*     for(auto u : adj[i]) cout << arr[u] << ' '; */
    /*     cout << endl; */
    /* } */
    for(int i = 0; i < n; i++) if(!vis[i]){
        dfs(i);
        ans++;
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int tc=1;
	if(ok2321) cin >> tc;
    while(tc--) solve();
	return 0;
}



