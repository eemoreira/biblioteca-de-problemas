const int N = 2e5 + 5;
vector<int> adj[N];

namespace st {
    int n, me;
    vector<vector<int>> up;
    vector<int> d;
    void bl_dfs(int v, int p) {
        up[v][0] = p;
        for(int i = 1; i <= me; i++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for(int u : adj[v]){
            if(u != p){
                d[u] = d[v] + 1;
                bl_dfs(u, v);
            }
        }
    }
    void build(int _n, int root){
        n = _n;
        me = __lg(n) + 1;
        up.assign(n, vector<int>(me+1, 0));
        d.assign(n, 0);
        bl_dfs(root, root);
    }
    int ancestor(int v, int k){ // k-th ancestor of u 
        for(int i = me; i >= 0; i--){
            if((1 << i) & k){
                v = up[v][i];
            }
        }
        return v;
    }
    int depth(int v) {
        return d[v];
    }
}
