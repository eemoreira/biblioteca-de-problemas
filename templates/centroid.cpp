const int MAX = 2e5 + 5;
int l,n;
vector<int> adj[MAX], d, sz, vis, AdjCentroid;
int up[MAX][30];

void Pre_dfs(int v, int p){
    up[v][0] = p;
    for(int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : adj[v]){
        if (u != p) {
            d[u] = d[v] + 1;
            Pre_dfs(u,v);
        }
    }
}

int lca(int u, int v){
    if (d[u] < d[v]) {
        swap(u,v);
    }
    int k = d[u] - d[v];
    for (int i = l; ~i; i--) {
        if (k >> i & 1) {
            u = up[u][i];
        }
    }
    if (u == v) return v;
    for (int i = l; ~i; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void preprocess(int root) {
    d.assign(n,0);
    sz.assign(n,0);
    vis.assign(n,0);
    AdjCentroid.assign(n, -1);
    l =  __lg(n) + 1;
    Pre_dfs(root, root);
}

int Get_dist(int v, int u) {
    return d[v] + d[u] - 2 * d[lca(u,v)];
}

int Dfs(int v, int p) {
    sz[v] = 1;
    for (auto u : adj[v]) {
        if (!vis[u] && u != p) {
            sz[v] += Dfs(u,v);
        }
    }
    return sz[v];
}
int Centroid(int v, int p, int size) {
    for (auto u : adj[v]) {
        if (!vis[u] && u != p && sz[u] > size/2) {
            return Centroid(u,v,size);
        }
    }
    return v;
}
int Decompose(int v) {
    int root = Centroid(v, -1, Dfs(v,-1));
    vis[root] = 1;
    for (auto u : adj[root]) {
        if (!vis[u]) {
            AdjCentroid[Decompose(u)] = root;
        }
    }
    return root;
}
