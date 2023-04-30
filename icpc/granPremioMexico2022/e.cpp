#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

/* stop freaking out pls */
const int MX = 2e5 + 500;
vector<int> go, cp;
int vis[MX], visrev[MX];
vector<int> adj[MX], rev[MX];

void dfs1(int v) {
    vis[v] = 1;
    for (auto u : adj[v]) {
        if (!vis[u]) {
            dfs1(u);
        }
    }
    go.emplace_back(v);
}
void dfs2(int v) {
    visrev[v] = 1;
    cp.emplace_back(v);
    for (auto u : rev[v]) {
        if (!visrev[u]) {
            dfs2(u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    auto lmao = [&](int x) {
        if (x < 0) {
            x = -x + 1;
            x += n + 5;
        }
        return x;
    };
    auto add = [&](int x, int y) {

        adj[lmao(~x)].emplace_back(lmao(y));
        adj[lmao(~y)].emplace_back(lmao(x));
        rev[lmao(y)].emplace_back(lmao(~x));
        rev[lmao(x)].emplace_back(lmao(~y));
    };
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        string s;
        cin >> s;
        int z;
        cin >> z;
        if (s == "=") {
            if (z == 0) {
                add(~x,~x);
                add(~y,~y);
            }
            else if (z == 1) {
                add(x,y);
                add(~x,~y);
            }
            else {
                add(x,x);
                add(y,y);
            }
        }
        if (s == "!=") {
            if (z == 0) {
                add(x,y);
            }
            else if (z == 1) {
                add(x,~y);
                add(~x,y);
            }
            else {
                add(~x,~y);
            }
        }
        if (s == "<") {
            if (z == 0) {
                ok = false;
            }
            else if (z == 1) {
                add(~x,~x);
                add(~y,~y);
            }
            else {
                add(~x,~y);
            }
        }
        if (s == ">") {
            if (z == 0) {
                add(x,y);
            }
            else if (z == 1) {
                add(x,x);
                add(y,y);
            }
            else {
                ok = false;
            }
        }
        if (s == "<=") {
            if (z == 0) {
                add(~x,~x);
                add(~y,~y);
            }
            else if (z == 1) {
                add(~x,~y);
            }
            else {
                //lol
            }
        }
        if (s == ">=") {
            if (z == 0) {
                //lol
            }
            else if (z == 1) {
                add(x,y);
            }
            else {
                add(x,x);
                add(y,y);
            }
        }
    }
    // por cuasa de n operaçoes a mais
    for (int i = 0; i <= (n << 1) + 30; i++) {
        if (!adj[i].empty() && !vis[i]) {
            dfs1(i);
        }
    }
    reverse(go.begin(), go.end());
    for (auto u : go) {
        if (!visrev[u]) {
            dfs2(u);
            map<int,int> have;
            for (auto x : cp) {
                have[lmao(x)]++;
            }
            for (auto x : cp) {
                if (have[lmao(x)] && have[lmao(~x)]) {
                    ok = false;
                }
            }
            cp.clear();
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}




